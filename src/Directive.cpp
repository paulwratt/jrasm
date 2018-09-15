//=============================================================================
// Directive.h
//=============================================================================
#include "stdafx.h"

//-----------------------------------------------------------------------------
// Directive
//-----------------------------------------------------------------------------
const Directive *Directive::CSEG	= nullptr;
const Directive *Directive::DB		= nullptr;
const Directive *Directive::DSEG	= nullptr;
const Directive *Directive::DW		= nullptr;
const Directive *Directive::END		= nullptr;
const Directive *Directive::EQU		= nullptr;
const Directive *Directive::INCLUDE	= nullptr;
const Directive *Directive::MML		= nullptr;
const Directive *Directive::ORG		= nullptr;
const Directive *Directive::PCG		= nullptr;
const Directive *Directive::PROC	= nullptr;

void Directive::Initialize()
{
	CSEG	= new Directive_CSEG();
	DB		= new Directive_DB();
	DSEG	= new Directive_DSEG();
	DW		= new Directive_DW();
	END		= new Directive_END();
	EQU		= new Directive_EQU();
	INCLUDE	= new Directive_INCLUDE();
	MML		= new Directive_MML();
	ORG		= new Directive_ORG();
	PCG		= new Directive_PCG();
	PROC	= new Directive_PROC();
}

Expr *Directive::Reduce(Context &context, const Expr_Directive *pExpr) const
{
	return pExpr->Reference();
}

//-----------------------------------------------------------------------------
// Directive_CSEG
//-----------------------------------------------------------------------------
bool Directive_CSEG::PrepareLookupTable(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

bool Directive_CSEG::Generate(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

//-----------------------------------------------------------------------------
// Directive_DB
//-----------------------------------------------------------------------------
bool Directive_DB::PrepareLookupTable(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

bool Directive_DB::Generate(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}


//-----------------------------------------------------------------------------
// Directive_DSEG
//-----------------------------------------------------------------------------
bool Directive_DSEG::PrepareLookupTable(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

bool Directive_DSEG::Generate(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}


//-----------------------------------------------------------------------------
// Directive_DW
//-----------------------------------------------------------------------------
bool Directive_DW::PrepareLookupTable(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

bool Directive_DW::Generate(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}


//-----------------------------------------------------------------------------
// Directive_END
//-----------------------------------------------------------------------------
bool Directive_END::PrepareLookupTable(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

bool Directive_END::Generate(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}


//-----------------------------------------------------------------------------
// Directive_EQU
//-----------------------------------------------------------------------------
bool Directive_EQU::PrepareLookupTable(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

bool Directive_EQU::Generate(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

Expr *Directive_EQU::Reduce(Context &context, const Expr_Directive *pExpr) const
{
	const ExprList &operands = pExpr->GetOperands();
	// .equ data
	if (operands.size() != 1) {
		ErrorLog::AddError(pExpr, "directive .equ takes one operand");
		return nullptr;
	}
	return operands.back()->Reduce(context);
}

//-----------------------------------------------------------------------------
// Directive_INCLUDE
//-----------------------------------------------------------------------------
bool Directive_INCLUDE::PrepareLookupTable(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

bool Directive_INCLUDE::Generate(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}


//-----------------------------------------------------------------------------
// Directive_MML
//-----------------------------------------------------------------------------
bool Directive_MML::PrepareLookupTable(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

bool Directive_MML::Generate(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}


//-----------------------------------------------------------------------------
// Directive_ORG
//-----------------------------------------------------------------------------
bool Directive_ORG::PrepareLookupTable(Context &context, const Expr_Directive *pExpr) const
{
	const ExprList &operands = pExpr->GetOperands();
	// .org data16
	if (operands.size() != 1) {
		ErrorLog::AddError(pExpr, "directive .org takes one operand");
		return false;
	}
	AutoPtr<Expr> pExprLast(operands.back()->Reduce(context));
	if (pExprLast.IsNull()) return false;
	if (!pExprLast->IsType(Expr::TYPE_Number)) {
		ErrorLog::AddError(pExpr, "directive .org expects a number value for its operand");
		return false;
	}
	UInt32 num = dynamic_cast<const Expr_Number *>(pExprLast.get())->GetNumber();
	if (num > 0xffff) {
		ErrorLog::AddError(pExpr, "address value exceeds 16-bit range");
		return false;
	}
	context.SetAddress(static_cast<UInt16>(num));
	return true;
}

bool Directive_ORG::Generate(Context &context, const Expr_Directive *pExpr) const
{
	context.SetAddress(0);
	return true;
}


//-----------------------------------------------------------------------------
// Directive_PCG
//-----------------------------------------------------------------------------
bool Directive_PCG::PrepareLookupTable(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

bool Directive_PCG::Generate(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}


//-----------------------------------------------------------------------------
// Directive_PROC
//-----------------------------------------------------------------------------
bool Directive_PROC::PrepareLookupTable(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}

bool Directive_PROC::Generate(Context &context, const Expr_Directive *pExpr) const
{
	return true;
}
