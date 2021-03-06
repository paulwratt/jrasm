//=============================================================================
// Expr.cpp
//=============================================================================
#include "stdafx.h"

//-----------------------------------------------------------------------------
// Expr
//-----------------------------------------------------------------------------
Expr::Expr(Type type) :
	_cntRef(1), _type(type), _pExprOperands(new ExprOwner()), _pExprChildren(new ExprOwner()), _lineNo(0)
{
}

Expr::Expr(Type type, ExprOwner *pExprOperands) :
	_cntRef(1), _type(type), _pExprOperands(pExprOperands), _pExprChildren(new ExprOwner()), _lineNo(0)
{
}

Expr::Expr(Type type, ExprOwner *pExprOperands, ExprOwner *pExprChildren) :
	_cntRef(1), _type(type), _pExprOperands(pExprOperands), _pExprChildren(pExprChildren), _lineNo(0)
{
}

Expr::Expr(const Expr &expr) :
	_cntRef(1), _type(expr._type),
	_pExprOperands(expr._pExprOperands->Clone()), _pExprChildren(expr._pExprChildren->Clone()),
	_pPathNameSrc(expr._pPathNameSrc->Reference()), _lineNo(expr._lineNo)
{
	// don't copy _pExprDict, which should be different for each Expr instance.
}

Expr::~Expr()
{
}

void Expr::AssignExprDict(Context &context, bool recursiveFlag)
{
	_pExprDict.reset(context.GetExprDictCurrent().Reference());
	if (recursiveFlag) {
		GetExprChildren().AssignExprDict(context, recursiveFlag);
		GetExprOperands().AssignExprDict(context, recursiveFlag);
	}
}

bool Expr::IsTypeLabel(const char *symbol) const
{
	return IsTypeLabel() &&
		::strcasecmp(dynamic_cast<const Expr_Label *>(this)->GetSymbol(), symbol) == 0;
}

bool Expr::IsTypeSymbol(const char *symbol) const
{
	return IsTypeSymbol() &&
		::strcasecmp(dynamic_cast<const Expr_Symbol *>(this)->GetSymbol(), symbol) == 0;
}

bool Expr::IsTypeBinaryOp(const Operator *pOperator) const
{
	return IsTypeBinaryOp() &&
		dynamic_cast<const Expr_BinaryOp *>(this)->GetOperator()->IsIdentical(pOperator);
}

bool Expr::IsTypeDirective(const DirectiveFactory *pDirectiveFactory) const
{
	return IsTypeDirective() && dynamic_cast<const Expr_Directive *>(this)->
		GetDirective()->GetDirectiveFactory()->IsIdentical(pDirectiveFactory);
}

bool Expr::IsGroupingDirective() const
{
	return IsTypeDirective() && dynamic_cast<const Expr_Directive *>(this)->GetDirective()->GetGroupingFlag();
}

void Expr::Print() const
{
	::printf("%s\n", ComposeSource(false).c_str());
}

InlineData::Type Expr::GetInlineDataType(Type type)
{
	return
		(type == TYPE_String)? InlineData::TYPE_String :
		(type == TYPE_BitPattern)? InlineData::TYPE_BitPattern :
		(type == TYPE_MML)? InlineData::TYPE_MML : InlineData::TYPE_String;
}

bool Expr::OnPhasePreprocess(Context &context)
{
	return GetExprOperands().OnPhasePreprocess(context) &&
		GetExprChildren().OnPhasePreprocess(context);
}

bool Expr::OnPhaseAssignMacro(Context &context)
{
	return GetExprOperands().OnPhaseAssignMacro(context) &&
		GetExprChildren().OnPhaseAssignMacro(context);
}

bool Expr::OnPhaseExpandMacro(Context &context)
{
	return GetExprOperands().OnPhaseExpandMacro(context) &&
		GetExprChildren().OnPhaseExpandMacro(context);
}

bool Expr::OnPhaseAssignSymbol(Context &context)
{
	AssignExprDict(context, false);
	return GetExprOperands().OnPhaseAssignSymbol(context) &&
		GetExprChildren().OnPhaseAssignSymbol(context);
}

bool Expr::OnPhaseGenerate(Context &context, Binary *pBuffDst) const
{
	return GetExprOperands().OnPhaseGenerate(context, pBuffDst) &&
		GetExprChildren().OnPhaseGenerate(context, pBuffDst);
}

bool Expr::OnPhaseDisasm(Context &context, DisasmDumper &disasmDumper, int indentLevelCode) const
{
	return GetExprOperands().OnPhaseDisasm(context, disasmDumper, indentLevelCode) &&
		GetExprChildren().OnPhaseDisasm(context, disasmDumper, indentLevelCode);
}

void Expr::GetFields(ExprList &exprFields) const
{
	exprFields.push_back(const_cast<Expr *>(this));
}

//-----------------------------------------------------------------------------
// ExprList
//-----------------------------------------------------------------------------
Expr_Label *ExprList::SeekLabelToAssoc()
{
	if (empty() || !back()->IsTypeLabel()) return nullptr;
	Expr_Label *pExprLabel = dynamic_cast<Expr_Label *>(back());
	return pExprLabel->IsAssigned()? nullptr : pExprLabel;
}

void ExprList::AssignExprDict(Context &context, bool recursiveFlag)
{
	for (auto pExpr : *this) {
		pExpr->AssignExprDict(context, recursiveFlag);
	}
}

bool ExprList::OnPhasePreprocess(Context &context)
{
	for (auto pExpr : *this) {
		if (!pExpr->OnPhasePreprocess(context)) return false;
	}
	return true;
}

bool ExprList::OnPhaseAssignMacro(Context &context)
{
	for (auto pExpr : *this) {
		if (!pExpr->OnPhaseAssignMacro(context)) return false;
	}
	return true;
}

bool ExprList::OnPhaseExpandMacro(Context &context)
{
	for (auto pExpr : *this) {
		if (!pExpr->OnPhaseExpandMacro(context)) return false;
	}
	return true;
}

bool ExprList::OnPhaseAssignSymbol(Context &context)
{
	for (auto pExpr : *this) {
		if (!pExpr->OnPhaseAssignSymbol(context)) return false;
	}
	return true;
}

bool ExprList::OnPhaseGenerate(Context &context, Binary *pBuffDst) const
{
	for (auto pExpr : *this) {
		if (!pExpr->OnPhaseGenerate(context, pBuffDst)) return false;
	}
	return true;
}

bool ExprList::OnPhaseDisasm(Context &context, DisasmDumper &disasmDumper, int indentLevelCode) const
{
	for (auto pExpr : *this) {
		if (!pExpr->OnPhaseDisasm(context, disasmDumper, indentLevelCode)) return false;
	}
	return true;
}

String ExprList::ComposeSource(bool upperCaseFlag, const char *sep) const
{
	String rtn;
	for (const_iterator ppExpr = begin(); ppExpr != end(); ppExpr++) {
		const Expr *pExpr = *ppExpr;
		if (ppExpr != begin()) rtn += sep;
		rtn += pExpr->ComposeSource(upperCaseFlag);
	}
	return rtn;
}

void ExprList::Print(bool upperCaseFlag) const
{
	for (auto pExpr : *this) {
		::printf("%s%s\n", pExpr->IsTypeLabel()? "" : "        ",
				 pExpr->ComposeSource(upperCaseFlag).c_str());
		pExpr->GetExprChildren().Print(upperCaseFlag);
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

ExprOwner *ExprOwner::Clone() const
{
	AutoPtr<ExprOwner> pExprOwner(new ExprOwner());
	pExprOwner->reserve(size());
	for (auto pExpr : *this) {
		pExprOwner->push_back(pExpr->Clone());
	}
	return pExprOwner.release();
}

ExprOwner *ExprOwner::Resolve(Context &context) const
{
	AutoPtr<ExprOwner> pExprOwner(new ExprOwner());
	pExprOwner->reserve(size());
	for (auto pExpr : *this) {
		AutoPtr<Expr> pExprResolved(pExpr->Resolve(context));
		if (pExprResolved.IsNull()) return nullptr;
		pExprOwner->push_back(pExprResolved.release());
	}
	return pExprOwner.release();
}

ExprOwner *ExprOwner::Substitute(const ExprDict &exprDict) const
{
	AutoPtr<ExprOwner> pExprOwner(new ExprOwner());
	pExprOwner->reserve(size());
	for (auto pExpr : *this) {
		AutoPtr<Expr> pExprSubst(pExpr->Substitute(exprDict));
		if (pExprSubst.IsNull()) return nullptr;
		pExprOwner->push_back(pExprSubst.release());
	}
	return pExprOwner.release();
}

//-----------------------------------------------------------------------------
// ExprDict
//-----------------------------------------------------------------------------
ExprDict::~ExprDict()
{
	for (auto iter : *this) {
		Expr::Delete(iter.second);
	}
}

void ExprDict::Assign(const String &symbol, Expr *pExpr, bool forceGlobalFlag)
{
	ExprDict *pExprDict = forceGlobalFlag? GetGlobal() : this;
	pExprDict->insert(std::make_pair(symbol, pExpr));
}

bool ExprDict::IsAssigned(const char *symbol) const
{
	return find(symbol) != end();
}

const Expr *ExprDict::Lookup(const char *symbol) const
{
	const_iterator iter = find(symbol);
	if (iter != end()) return iter->second;
	return _pExprDictParent.IsNull()? nullptr : _pExprDictParent->Lookup(symbol);
}

ExprDict *ExprDict::GetGlobal()
{
	ExprDict *pExprDict = this;
	for ( ; pExprDict->GetParent() != nullptr; pExprDict = pExprDict->GetParent()) ;
	return pExprDict;
}

//-----------------------------------------------------------------------------
// ExprDictOwner
//-----------------------------------------------------------------------------
ExprDictOwner::~ExprDictOwner()
{
	Clear();
}

void ExprDictOwner::Clear()
{
	for (auto pExprDict : *this) {
		ExprDict::Delete(pExprDict);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Expr_Null
//-----------------------------------------------------------------------------
const Expr::Type Expr_Null::TYPE = Expr::TYPE_Null;

Expr *Expr_Null::Resolve(Context &context) const
{
	return Reference();
}

Expr *Expr_Null::Clone() const
{
	return new Expr_Null(*this);
}

Expr *Expr_Null::Substitute(const ExprDict &exprDict) const
{
	return Clone();
}

String Expr_Null::ComposeSource(bool upperCaseFlag) const
{
	return "";
}

//-----------------------------------------------------------------------------
// Expr_Group
//-----------------------------------------------------------------------------
const Expr::Type Expr_Group::TYPE = Expr::TYPE_Group;

Expr *Expr_Group::Resolve(Context &context) const
{
	return Reference();
}

Expr *Expr_Group::Clone() const
{
	return new Expr_Group(*this);
}

Expr *Expr_Group::Substitute(const ExprDict &exprDict) const
{
	AutoPtr<ExprOwner> pExprOperandsSubst(GetExprOperands().Substitute(exprDict));
	if (pExprOperandsSubst.IsNull()) return nullptr;
	AutoPtr<ExprOwner> pExprChildrenSubst(GetExprChildren().Substitute(exprDict));
	if (pExprChildrenSubst.IsNull()) return nullptr;
	AutoPtr<Expr> pExprRtn(new Expr_Group(pExprOperandsSubst.release(), pExprChildrenSubst.release()));
	pExprRtn->DeriveSourceInfo(this);
	return pExprRtn.release();
}

String Expr_Group::ComposeSource(bool upperCaseFlag) const
{
	return "";
}

//-----------------------------------------------------------------------------
// Expr_Integer
//-----------------------------------------------------------------------------
const Expr::Type Expr_Integer::TYPE = Expr::TYPE_Integer;

Expr *Expr_Integer::Resolve(Context &context) const
{
	return Reference();
}

Expr *Expr_Integer::Clone() const
{
	return new Expr_Integer(*this);
}

Expr *Expr_Integer::Substitute(const ExprDict &exprDict) const
{
	return Clone();
}

String Expr_Integer::ComposeSource(bool upperCaseFlag) const
{
	if (!_str.empty()) {
		if (_str[0] != '\'') return _str;
		String str;
		str += _str[1];
		str = MakeQuotedString(str.c_str(), '\'');
		str = String("'") + str + "'";
		return str;
	}
	const char *format =
		(_num < 0x100)? (upperCaseFlag? "0x%02X" : "0x%02x") :
		(_num < 0x10000)? (upperCaseFlag? "0x%04X" : "0x%04x") :
		(upperCaseFlag? "0x%08X" : "0x%08x");
	char buff[128];
	::sprintf_s(buff, format, _num);
	return buff;
}

//-----------------------------------------------------------------------------
// Expr_Buffer
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Expr_String
//-----------------------------------------------------------------------------
const Expr::Type Expr_String::TYPE = Expr::TYPE_String;

const Binary &Expr_String::GetBinary() const
{
	return _str;
}

Expr *Expr_String::Resolve(Context &context) const
{
	return Reference();
}

Expr *Expr_String::Clone() const
{
	return new Expr_String(*this);
}

Expr *Expr_String::Substitute(const ExprDict &exprDict) const
{
	return Clone();
}

String Expr_String::ComposeSource(bool upperCaseFlag) const
{
	String str;
	str = "\"";
	str += MakeQuotedString(_str, '"'); // not affected by upperCaseFlag
	str += "\"";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_BitPattern
//-----------------------------------------------------------------------------
const Expr::Type Expr_BitPattern::TYPE = Expr::TYPE_BitPattern;

const Binary &Expr_BitPattern::GetBinary() const
{
	return _buff;
}

Expr *Expr_BitPattern::Resolve(Context &context) const
{
	return Reference();
}

Expr *Expr_BitPattern::Clone() const
{
	return new Expr_BitPattern(*this);
}

Expr *Expr_BitPattern::Substitute(const ExprDict &exprDict) const
{
	return Clone();
}

String Expr_BitPattern::ComposeSource(bool upperCaseFlag) const
{
	String str;
	str = "b\"";
	str += MakeQuotedString(_str, '"'); // not affected by upperCaseFlag
	str += "\"";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_MML
//-----------------------------------------------------------------------------
const Expr::Type Expr_MML::TYPE = Expr::TYPE_MML;

const Binary &Expr_MML::GetBinary() const
{
	return _pBuffShared->GetBinary();
}

Expr *Expr_MML::Resolve(Context &context) const
{
	return Reference();
}

Expr *Expr_MML::Clone() const
{
	return new Expr_MML(*this);
}

Expr *Expr_MML::Substitute(const ExprDict &exprDict) const
{
	return Clone();
}

String Expr_MML::ComposeSource(bool upperCaseFlag) const
{
	String str;
	str = "m\"";
	str += MakeQuotedString(_str, '"'); // not affected by upperCaseFlag
	str += "\"";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Assign
//-----------------------------------------------------------------------------
const Expr::Type Expr_Assign::TYPE = Expr::TYPE_Assign;

Expr *Expr_Assign::Resolve(Context &context) const
{
	AutoPtr<Expr> pExprL(GetLeft()->Clone());
	AutoPtr<Expr> pExprR(GetRight()->Resolve(context));
	if (pExprR.IsNull()) return nullptr;
	return new Expr_Assign(pExprL.release(), pExprR.release());
}

Expr *Expr_Assign::Clone() const
{
	return new Expr_Assign(*this);
}

Expr *Expr_Assign::Substitute(const ExprDict &exprDict) const
{
	AutoPtr<ExprOwner> pExprOperandsSubst(GetExprOperands().Substitute(exprDict));
	if (pExprOperandsSubst.IsNull()) return nullptr;
	AutoPtr<ExprOwner> pExprChildrenSubst(GetExprChildren().Substitute(exprDict));
	if (pExprChildrenSubst.IsNull()) return nullptr;
	AutoPtr<Expr> pExprRtn(new Expr_Assign(pExprOperandsSubst.release(), pExprChildrenSubst.release()));
	pExprRtn->DeriveSourceInfo(this);
	return pExprRtn.release();
}

String Expr_Assign::ComposeSource(bool upperCaseFlag) const
{
	String str;
	str += GetLeft()->ComposeSource(upperCaseFlag);
	str += "=";
	str += GetRight()->ComposeSource(upperCaseFlag);
	return str;
}

//-----------------------------------------------------------------------------
// Expr_BinaryOp
//-----------------------------------------------------------------------------
const Expr::Type Expr_BinaryOp::TYPE = Expr::TYPE_BinaryOp;

void Expr_BinaryOp::GetFields(ExprList &exprFields) const
{
	if (_pOperator->IsIdentical(Operator::FieldSep)) {
		GetLeft()->GetFields(exprFields);
		GetRight()->GetFields(exprFields);
	} else {
		exprFields.push_back(const_cast<Expr_BinaryOp *>(this));
	}
}

Expr *Expr_BinaryOp::Resolve(Context &context) const
{
	AutoPtr<Expr> pExprL(GetLeft()->Resolve(context));
	if (pExprL.IsNull()) return nullptr;
	AutoPtr<Expr> pExprR(GetRight()->Resolve(context));
	if (pExprR.IsNull()) return nullptr;
	return _pOperator->Resolve(context, pExprL.release(), pExprR.release());
}

Expr *Expr_BinaryOp::Clone() const
{
	return new Expr_BinaryOp(*this);
}

Expr *Expr_BinaryOp::Substitute(const ExprDict &exprDict) const
{
	AutoPtr<ExprOwner> pExprOperandsSubst(GetExprOperands().Substitute(exprDict));
	if (pExprOperandsSubst.IsNull()) return nullptr;
	AutoPtr<ExprOwner> pExprChildrenSubst(GetExprChildren().Substitute(exprDict));
	if (pExprChildrenSubst.IsNull()) return nullptr;
	AutoPtr<Expr> pExprRtn(new Expr_BinaryOp(
							   GetOperator(),
							   pExprOperandsSubst.release(), pExprChildrenSubst.release()));
	pExprRtn->DeriveSourceInfo(this);
	return pExprRtn.release();
}

String Expr_BinaryOp::ComposeSource(bool upperCaseFlag) const
{
	String str;
	bool needParenFlagL = false;
	bool needParenFlagR = false;
	if (GetLeft()->IsTypeBinaryOp()) {
		Token::Precedence prec = Operator::LookupPrec(
			dynamic_cast<const Expr_BinaryOp *>(GetLeft())->GetOperator(),
			GetOperator());
		needParenFlagL = prec == (Token::PREC_LT);
	}
	if (GetRight()->IsTypeBinaryOp()) {
		Token::Precedence prec = Operator::LookupPrec(
			GetOperator(),
			dynamic_cast<const Expr_BinaryOp *>(GetRight())->GetOperator());
		needParenFlagR = prec == (Token::PREC_GT);
	}
	if (needParenFlagL) str += "(";
	str += GetLeft()->ComposeSource(upperCaseFlag);
	if (needParenFlagL) str += ")";
	str += _pOperator->GetSymbol();
	if (needParenFlagR) str += "(";
	str += GetRight()->ComposeSource(upperCaseFlag);
	if (needParenFlagR) str += ")";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_UnaryOp
//-----------------------------------------------------------------------------
const Expr::Type Expr_UnaryOp::TYPE = Expr::TYPE_UnaryOp;

Expr *Expr_UnaryOp::Resolve(Context &context) const
{
	AutoPtr<Expr> pExprOperand(GetOperand()->Resolve(context));
	if (pExprOperand.IsNull()) return nullptr;
	return _pOperator->Resolve(context, pExprOperand.release());
}

Expr *Expr_UnaryOp::Clone() const
{
	return new Expr_UnaryOp(*this);
}

Expr *Expr_UnaryOp::Substitute(const ExprDict &exprDict) const
{
	AutoPtr<ExprOwner> pExprOperandsSubst(GetExprOperands().Substitute(exprDict));
	if (pExprOperandsSubst.IsNull()) return nullptr;
	AutoPtr<ExprOwner> pExprChildrenSubst(GetExprChildren().Substitute(exprDict));
	if (pExprChildrenSubst.IsNull()) return nullptr;
	AutoPtr<Expr> pExprRtn(new Expr_UnaryOp(
							   GetOperator(),
							   pExprOperandsSubst.release(), pExprChildrenSubst.release()));
	pExprRtn->DeriveSourceInfo(this);
	return pExprRtn.release();
}

String Expr_UnaryOp::ComposeSource(bool upperCaseFlag) const
{
	String str;
	bool needParenFlag = GetOperand()->IsTypeBinaryOp() || GetOperand()->IsTypeUnaryOp();
	str += _pOperator->GetSymbol();
	if (needParenFlag) str += "(";
	str += GetOperand()->ComposeSource(upperCaseFlag);
	if (needParenFlag) str += ")";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Bracket
//-----------------------------------------------------------------------------
const Expr::Type Expr_Bracket::TYPE = Expr::TYPE_Bracket;

Expr *Expr_Bracket::Resolve(Context &context) const
{
	AutoPtr<Expr_Bracket> pExprRtn(new Expr_Bracket());
	pExprRtn->DeriveSourceInfo(this);
	for (auto pExprOperand : GetExprOperands()) {
		AutoPtr<Expr> pExprOperandResolved(pExprOperand->Resolve(context));
		if (pExprOperandResolved.IsNull()) return nullptr;
		pExprRtn->GetExprOperands().push_back(pExprOperandResolved.release());
	}
	return pExprRtn.release();
}

Expr *Expr_Bracket::Clone() const
{
	return new Expr_Bracket(*this);
}

Expr *Expr_Bracket::Substitute(const ExprDict &exprDict) const
{
	AutoPtr<ExprOwner> pExprOperandsSubst(GetExprOperands().Substitute(exprDict));
	if (pExprOperandsSubst.IsNull()) return nullptr;
	AutoPtr<ExprOwner> pExprChildrenSubst(GetExprChildren().Substitute(exprDict));
	if (pExprChildrenSubst.IsNull()) return nullptr;
	AutoPtr<Expr> pExprRtn(new Expr_Bracket(
							   pExprOperandsSubst.release(), pExprChildrenSubst.release()));
	pExprRtn->DeriveSourceInfo(this);
	return pExprRtn.release();
}

String Expr_Bracket::ComposeSource(bool upperCaseFlag) const
{
	String str;
	str = "[";
	str += GetExprOperands().ComposeSource(upperCaseFlag, ",");
	str += "]";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Brace
//-----------------------------------------------------------------------------
const Expr::Type Expr_Brace::TYPE = Expr::TYPE_Brace;

Expr *Expr_Brace::Resolve(Context &context) const
{
	AutoPtr<Expr_Brace> pExprRtn(new Expr_Brace());
	pExprRtn->DeriveSourceInfo(this);
	for (auto pExprOperand : GetExprOperands()) {
		AutoPtr<Expr> pExprOperandResolved(pExprOperand->Resolve(context));
		if (pExprOperandResolved.IsNull()) return nullptr;
		pExprRtn->GetExprOperands().push_back(pExprOperandResolved.release());
	}
	return pExprRtn.release();
}

Expr *Expr_Brace::Clone() const
{
	return new Expr_Brace(*this);
}

Expr *Expr_Brace::Substitute(const ExprDict &exprDict) const
{
	AutoPtr<ExprOwner> pExprOperandsSubst(GetExprOperands().Substitute(exprDict));
	if (pExprOperandsSubst.IsNull()) return nullptr;
	AutoPtr<ExprOwner> pExprChildrenSubst(GetExprChildren().Substitute(exprDict));
	if (pExprChildrenSubst.IsNull()) return nullptr;
	AutoPtr<Expr> pExprRtn(new Expr_Brace(
							   pExprOperandsSubst.release(), pExprChildrenSubst.release()));
	pExprRtn->DeriveSourceInfo(this);
	return pExprRtn.release();
}

String Expr_Brace::ComposeSource(bool upperCaseFlag) const
{
	String str;
	str = "{";
	str += GetExprOperands().ComposeSource(upperCaseFlag, ",");
	str += "}";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Label
//-----------------------------------------------------------------------------
const Expr::Type Expr_Label::TYPE = Expr::TYPE_Label;

bool Expr_Label::OnPhaseAssignSymbol(Context &context)
{
	if (!Expr::OnPhaseAssignSymbol(context)) return false;
	if (_pExprDict->IsAssigned(GetSymbol())) {
		ErrorLog::AddError(this, "duplicated definition of symbol: %s", GetSymbol());
		return false;
	}
	if (IsAssigned()) {
		_pExprDict->Assign(GetSymbol(), GetAssigned()->Reference(), _forceGlobalFlag);
	} else {
		AutoPtr<Expr> pExpr(new Expr_Integer(context.GetSegmentCur()->GetAddrOffset(),
											 context.GetSegmentCur()->GetRegionCur()->Reference()));
		pExpr->DeriveSourceInfo(this);
		_pExprDict->Assign(GetSymbol(), pExpr.release(), _forceGlobalFlag);
	}
	return true;
}

bool Expr_Label::OnPhaseDisasm(Context &context, DisasmDumper &disasmDumper, int indentLevelCode) const
{
	String strLabel = MakeSource(_symbol.c_str(), _forceGlobalFlag);
	if (!IsAssigned()) {
		disasmDumper.DumpLabel(strLabel.c_str(), indentLevelCode);
	} else if (GetAssigned()->IsTypeDirective(Directive::EQU)) {
		disasmDumper.DumpLabelAndCode(
			strLabel.c_str(),
			GetAssigned()->ComposeSource(disasmDumper.GetUpperCaseFlag()).c_str(), indentLevelCode);
	}
	return true;
}

Expr *Expr_Label::Resolve(Context &context) const
{
	return Reference();
}

Expr *Expr_Label::Clone() const
{
	return new Expr_Label(*this);
}

Expr *Expr_Label::Substitute(const ExprDict &exprDict) const
{
	return Clone();
}

String Expr_Label::ComposeSource(bool upperCaseFlag) const
{
	String str = MakeSource(_symbol.c_str(), _forceGlobalFlag);
	return str;
}

String Expr_Label::MakeSource(const char *symbol, bool forceGlobalFlag)
{
	String str;
	str = symbol;
	str += forceGlobalFlag? "::" : ":";
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Symbol
//-----------------------------------------------------------------------------
const Expr::Type Expr_Symbol::TYPE = Expr::TYPE_Symbol;

bool Expr_Symbol::OnPhaseAssignSymbol(Context &context)
{
	if (!Expr::OnPhaseAssignSymbol(context)) return false;
	if (_symbol == "$") {
		_pExprAssigned.reset(new Expr_Integer(context.GetSegmentCur()->GetAddrOffset(),
											  context.GetSegmentCur()->GetRegionCur()->Reference()));
		_pExprAssigned->DeriveSourceInfo(this);
	}
	return true;
}

Expr *Expr_Symbol::Resolve(Context &context) const
{
	if (!_pExprAssigned.IsNull()) return _pExprAssigned->Reference();
	if (context.CheckCircularReference(this)) return nullptr;
	if (Generator::GetInstance().IsRegisterSymbol(GetSymbol())) return Reference();
	const Expr *pExpr = _pExprDict.IsNull()? nullptr : _pExprDict->Lookup(GetSymbol());
	if (pExpr != nullptr) {
		// nothing to do
	} else if (context.IsPhase(Context::PHASE_Generate)) {
		ErrorLog::AddError(this, "undefined symbol: %s", GetSymbol());
		return nullptr;
	} else {
		AutoPtr<Expr> pExprRtn(new Expr_Integer(0));
		pExprRtn->DeriveSourceInfo(this);
		return pExprRtn.release();
	}
	AutoPtr<Expr> pExprResolved(pExpr->Resolve(context));
	if (pExprResolved.IsNull()) return nullptr;
	if (!pExprResolved->IsTypeInteger()) {
		ErrorLog::AddError(this, "symbol %s must be associated with an integer", GetSymbol());
		return nullptr;
	}
	return pExprResolved.release();
}

Expr *Expr_Symbol::Clone() const
{
	return new Expr_Symbol(*this);
}

Expr *Expr_Symbol::Substitute(const ExprDict &exprDict) const
{
	const Expr *pExpr = exprDict.Lookup(GetSymbol());
	return (pExpr == nullptr)? Clone() : pExpr->Clone();
}

String Expr_Symbol::ComposeSource(bool upperCaseFlag) const
{
	if (Generator::GetInstance().IsRegisterSymbol(_symbol.c_str())) {
		return upperCaseFlag? ToUpper(_symbol.c_str()) : ToLower(_symbol.c_str());
	}
	return _symbol;
}

//-----------------------------------------------------------------------------
// Expr_Instruction
//-----------------------------------------------------------------------------
const Expr::Type Expr_Instruction::TYPE = Expr::TYPE_Instruction;

bool Expr_Instruction::OnPhasePreprocess(Context &context)
{
	for (auto pExpr : GetExprOperands()) {
		if (pExpr->IsTypeBuffer()) {
			Expr_Buffer *pExprEx = dynamic_cast<Expr_Buffer *>(pExpr);
			pExprEx->SetInlineData(context.CreateInlineData(
									   pExprEx->GetInlineDataType(), pExprEx->GetBinary(),
									   pExprEx->ComposeSource(false)));
		}
	}
	return true;
}

bool Expr_Instruction::OnPhaseExpandMacro(Context &context)
{
	const Macro *pMacro = context.GetMacroDict().Lookup(GetSymbol());
	if (pMacro == nullptr) return true;
	_pExprsExpanded.reset(pMacro->Expand(context, this));
	if (_pExprsExpanded.IsNull()) return false;
	return _pExprsExpanded->OnPhaseExpandMacro(context);
}

bool Expr_Instruction::OnPhaseAssignSymbol(Context &context)
{
	if (!context.CheckGeneratable(this)) return false;
	if (!Expr::OnPhaseAssignSymbol(context)) return false;
	bool rtn = true;
	if (_pExprsExpanded.IsNull()) {
		rtn = Generator::GetInstance().ForwardAddress(context, this);
	} else {
		context.BeginScope();
		for (auto pExpr : *_pExprsExpanded) {
			if (!(rtn = pExpr->OnPhaseAssignSymbol(context))) break;
		}
		context.EndScope();
	}
	return rtn;
}

bool Expr_Instruction::OnPhaseGenerate(Context &context, Binary *pBuffDst) const
{
	bool rtn = true;
	if (_pExprsExpanded.IsNull()) {
		rtn = Generator::GetInstance().Generate(context, this, pBuffDst);
	} else {
		for (auto pExpr : *_pExprsExpanded) {
			if (!(rtn = pExpr->OnPhaseGenerate(context, pBuffDst))) break;
		}
	}
	return rtn;
}

bool Expr_Instruction::OnPhaseDisasm(Context &context, DisasmDumper &disasmDumper, int indentLevelCode) const
{
	bool rtn = true;
	bool upperCaseFlag = disasmDumper.GetUpperCaseFlag();
	if (_pExprsExpanded.IsNull()) {
		Binary buffDst;
		Integer addr = context.GetAddress();
		if ((rtn = Generator::GetInstance().Generate(context, this, &buffDst))) {
			disasmDumper.DumpDataAndCode(addr, buffDst, ComposeSource(upperCaseFlag).c_str(), indentLevelCode);
		}
	} else {
		disasmDumper.DumpCode(ComposeSource(upperCaseFlag).c_str(), indentLevelCode);
		for (auto pExpr : *_pExprsExpanded) {
			if (!(rtn = pExpr->OnPhaseDisasm(context, disasmDumper, indentLevelCode + 1))) break;
		}
	}
	return rtn;
}

Expr *Expr_Instruction::Resolve(Context &context) const
{
	return Reference();
}

Expr *Expr_Instruction::Clone() const
{
	return new Expr_Instruction(*this);
}

Expr *Expr_Instruction::Substitute(const ExprDict &exprDict) const
{
	const char *symbol = GetSymbol();
	const Expr *pExpr = exprDict.Lookup(symbol);
	if (pExpr != nullptr) {
		if (!pExpr->IsTypeSymbol()) {
			ErrorLog::AddError(this, "failed to replace symbol '%s'", symbol);
			return nullptr;
		}
		symbol = dynamic_cast<const Expr_Symbol *>(pExpr)->GetSymbol();
	}
	AutoPtr<ExprOwner> pExprOperandsSubst(GetExprOperands().Substitute(exprDict));
	if (pExprOperandsSubst.IsNull()) return nullptr;
	AutoPtr<ExprOwner> pExprChildrenSubst(GetExprChildren().Substitute(exprDict));
	if (pExprChildrenSubst.IsNull()) return nullptr;
	AutoPtr<Expr> pExprRtn(new Expr_Instruction(
							   symbol,
							   pExprOperandsSubst.release(), pExprChildrenSubst.release()));
	pExprRtn->DeriveSourceInfo(this);
	return pExprRtn.release();
}

String Expr_Instruction::ComposeSource(bool upperCaseFlag) const
{
	String str = JustifyLeft(
		(upperCaseFlag? ToUpper(_symbol.c_str()) : ToLower(_symbol.c_str())).c_str(),
		Generator::GetInstance().GetInstNameLenMax());
	if (!GetExprOperands().empty()) {
		str += " ";
		str += GetExprOperands().ComposeSource(upperCaseFlag, ",");
	}
	return str;
}

//-----------------------------------------------------------------------------
// Expr_Directive
//-----------------------------------------------------------------------------
const Expr::Type Expr_Directive::TYPE = Expr::TYPE_Directive;

bool Expr_Directive::OnPhasePreprocess(Context &context)
{
	return _pDirective->OnPhasePreprocess(context, this) && Expr::OnPhasePreprocess(context);
}

bool Expr_Directive::OnPhaseAssignMacro(Context &context)
{
	return _pDirective->OnPhaseAssignMacro(context, this) && Expr::OnPhaseAssignMacro(context);
}

bool Expr_Directive::OnPhaseExpandMacro(Context &context)
{
	return _pDirective->OnPhaseExpandMacro(context, this) && Expr::OnPhaseExpandMacro(context);
}

bool Expr_Directive::OnPhaseAssignSymbol(Context &context)
{
	if (_pDirective->GetChildrenEvalFlag() &&
		!Expr::OnPhaseAssignSymbol(context)) return false;
	return _pDirective->OnPhaseAssignSymbol(context, this);
}

bool Expr_Directive::OnPhaseGenerate(Context &context, Binary *pBuffDst) const
{
	if (_pDirective->GetChildrenEvalFlag() &&
		!Expr::OnPhaseGenerate(context, pBuffDst)) return false;
	return _pDirective->OnPhaseGenerate(context, this, pBuffDst);
}

bool Expr_Directive::OnPhaseDisasm(Context &context, DisasmDumper &disasmDumper, int indentLevelCode) const
{
	if (_pDirective->GetChildrenEvalFlag() &&
		!Expr::OnPhaseDisasm(context, disasmDumper, indentLevelCode)) return false;
	return _pDirective->OnPhaseDisasm(context, this, disasmDumper, indentLevelCode);
}

Expr *Expr_Directive::Resolve(Context &context) const
{
	return _pDirective->Resolve(context, this);
}

Expr *Expr_Directive::Clone() const
{
	AutoPtr<Expr> pExprRtn(new Expr_Directive(*this));
	pExprRtn->DeriveSourceInfo(this);
	return pExprRtn.release();
}

Expr *Expr_Directive::Substitute(const ExprDict &exprDict) const
{
	AutoPtr<ExprOwner> pExprOperandsSubst(GetExprOperands().Substitute(exprDict));
	if (pExprOperandsSubst.IsNull()) return nullptr;
	AutoPtr<ExprOwner> pExprChildrenSubst(GetExprChildren().Substitute(exprDict));
	if (pExprChildrenSubst.IsNull()) return nullptr;
	AutoPtr<Expr> pExprRtn(new Expr_Directive(
							   GetDirective()->Reference(),
							   pExprOperandsSubst.release(), pExprChildrenSubst.release()));
	pExprRtn->DeriveSourceInfo(this);
	return pExprRtn.release();
}

String Expr_Directive::ComposeSource(bool upperCaseFlag) const
{
	const char *symbol = _pDirective->GetSymbol();
	String str = JustifyLeft(
		(upperCaseFlag? ToUpper(symbol) : ToLower(symbol)).c_str(),
		Generator::GetInstance().GetInstNameLenMax());
	if (!GetExprOperands().empty()) {
		str += " ";
		str += GetExprOperands().ComposeSource(upperCaseFlag, ",");
	}
	return str;
}
