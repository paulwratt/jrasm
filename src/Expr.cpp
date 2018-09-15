//=============================================================================
// Expr.cpp
//=============================================================================
#include "stdafx.h"

//-----------------------------------------------------------------------------
// Expr
//-----------------------------------------------------------------------------
Expr::Expr(Type type) :
	_cntRef(1), _type(type), _pExprChildren(new ExprOwner()), _lineNo(0)
{
}

Expr::~Expr()
{
}

void Expr::AddChild(Expr *pExpr)
{
	_pExprChildren->push_back(pExpr);
}

bool Expr::PrepareLookupTable(Context &context)
{
	_pLookupTable.reset(context.GetLookupTable()->Reference());
	return true;
}

bool Expr::Generate(Context &context)
{
	// nothing to do
	return true;
}

//-----------------------------------------------------------------------------
// ExprList
//-----------------------------------------------------------------------------
String ExprList::ToString() const
{
	String rtn;
	for (auto pExpr : *this) {
		if (!rtn.empty()) rtn += ",";
		rtn += pExpr->ToString();
	}
	return rtn;
}

void ExprList::Print() const
{
	for (auto pExpr : *this) {
		::printf("%s\n", pExpr->ToString().c_str());
	}
}

//-----------------------------------------------------------------------------
// ExprOwner
//-----------------------------------------------------------------------------
ExprOwner::~ExprOwner()
{
	Clear();
}

void ExprOwner::Clear()
{
	for (auto pExpr : *this) {
		Expr::Delete(pExpr);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Expr_Root
//-----------------------------------------------------------------------------
bool Expr_Root::PrepareLookupTable(Context &context)
{
	Expr::PrepareLookupTable(context);
	for (auto pExpr : GetChildren()) {
		pExpr->PrepareLookupTable(context);
	}
	return true;
}

bool Expr_Root::Generate(Context &context)
{
	for (auto pExpr : GetChildren()) {
		pExpr->Generate(context);
	}
	return true;
}

Expr *Expr_Root::Reduce(Context &context) const
{
	return Reference();
}

String Expr_Root::ToString() const
{
	return "";
}

//-----------------------------------------------------------------------------
// Expr_Number
//-----------------------------------------------------------------------------
String Expr_Number::ToString() const
{
	char buff[128];
	::sprintf_s(buff, "0x%x", _num);
	return buff;
}

Expr *Expr_Number::Reduce(Context &context) const
{
	return Reference();
}

//-----------------------------------------------------------------------------
// Expr_Symbol
//-----------------------------------------------------------------------------
String Expr_Symbol::ToString() const
{
	return _symbol;
}

Expr *Expr_Symbol::Reduce(Context &context) const
{
	bool foundFlag = false;
	UInt32 num = Lookup(GetSymbol(), &foundFlag);
	if (!foundFlag) {
		ErrorLog::AddError(this, "undefined symbol: ", GetSymbol());
		return nullptr;
	}
	return new Expr_Number(num);
}

//-----------------------------------------------------------------------------
// Expr_String
//-----------------------------------------------------------------------------
String Expr_String::ToString() const
{
	String str;
	str = "\"";
	str += _str;
	str += "\"";
	return str;
}

Expr *Expr_String::Reduce(Context &context) const
{
	return Reference();
}

//-----------------------------------------------------------------------------
// Expr_BinOp
//-----------------------------------------------------------------------------
String Expr_BinOp::ToString() const
{
	String str;
	str = GetLeft()->ToString();
	str += " + ";
	str += GetRight()->ToString();
	return str;
}

Expr *Expr_BinOp::Reduce(Context &context) const
{
	AutoPtr<Expr> pExprL(GetLeft()->Reduce(context));
	if (pExprL.IsNull()) return nullptr;
	AutoPtr<Expr> pExprR(GetRight()->Reduce(context));
	if (pExprR.IsNull()) return nullptr;
	
	return Reference();
}

//-----------------------------------------------------------------------------
// Expr_Bracket
//-----------------------------------------------------------------------------
String Expr_Bracket::ToString() const
{
	String str;
	str = "[";
	str += GetChildren().ToString();
	str += "]";
	return str;
}

Expr *Expr_Bracket::Reduce(Context &context) const
{
	AutoPtr<Expr_Bracket> pExprRtn(new Expr_Bracket());
	pExprRtn->DeriveSourceInfo(this);
	for (auto pExprChild : GetChildren()) {
		AutoPtr<Expr> pExprChildReduced(pExprChild->Reduce(context));
		if (pExprChildReduced.IsNull()) return nullptr;
		pExprRtn->AddChild(pExprChildReduced.release());
	}
	return pExprRtn.release();
}

//-----------------------------------------------------------------------------
// Expr_Parenthesis
//-----------------------------------------------------------------------------
String Expr_Parenthesis::ToString() const
{
	String str;
	str = "(";
	str += GetChildren().ToString();
	str += ")";
	return str;
}

Expr *Expr_Parenthesis::Reduce(Context &context) const
{
	AutoPtr<Expr_Parenthesis> pExprRtn(new Expr_Parenthesis());
	pExprRtn->DeriveSourceInfo(this);
	for (auto pExprChild : GetChildren()) {
		AutoPtr<Expr> pExprChildReduced(pExprChild->Reduce(context));
		if (pExprChildReduced.IsNull()) return nullptr;
		pExprRtn->AddChild(pExprChildReduced.release());
	}
	return pExprRtn.release();
}

//-----------------------------------------------------------------------------
// Expr_LabelDef
//-----------------------------------------------------------------------------
bool Expr_LabelDef::PrepareLookupTable(Context &context)
{
	if (!Expr::PrepareLookupTable(context)) return false;
	if (_pExprAssigned.IsNull()) {
		context.GetLookupTable()->Set(GetLabel(), context.GetAddress());
		return true;
	}
	return true;
}

bool Expr_LabelDef::Generate(Context &context)
{
	// nothing to do
	return true;
}

Expr *Expr_LabelDef::Reduce(Context &context) const
{
	return Reference();
}

String Expr_LabelDef::ToString() const
{
	String str;
	str = _label;
	str += ":";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Instruction
//-----------------------------------------------------------------------------
bool Expr_Instruction::PrepareLookupTable(Context &context)
{
	if (!Expr::PrepareLookupTable(context)) return false;
	UInt32 bytes = 0;
	context.GetGenerator()->CalcInstBytes(context, this, &bytes);
	context.ForwardAddress(bytes);
	return true;
}

bool Expr_Instruction::Generate(Context &context)
{
	return context.GetGenerator()->Generate(context, this);
}

Expr *Expr_Instruction::Reduce(Context &context) const
{
	return Reference();
}

String Expr_Instruction::ToString() const
{
	String str = _symbol;
	str += " ";
	str += GetChildren().ToString();
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Directive
//-----------------------------------------------------------------------------
bool Expr_Directive::PrepareLookupTable(Context &context)
{
	if (!Expr::PrepareLookupTable(context)) return false;
	return _pDirective->PrepareLookupTable(context, this);
}

bool Expr_Directive::Generate(Context &context)
{
	return _pDirective->Generate(context, this);
}

Expr *Expr_Directive::Reduce(Context &context) const
{
	return Reference();
}

String Expr_Directive::ToString() const
{
	String str = _pDirective->GetSymbol();
	str += " ";
	str += GetChildren().ToString();
	return str;
}
