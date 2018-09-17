//=============================================================================
// Operator.h
//=============================================================================
#include "stdafx.h"

//-----------------------------------------------------------------------------
// Operator
//-----------------------------------------------------------------------------
const Operator *Operator::Add = nullptr;
const Operator *Operator::Sub = nullptr;
const Operator *Operator::Mul = nullptr;
const Operator *Operator::Div = nullptr;

void Operator::Initialize()
{
	Add = new Operator_Add();
	Sub = new Operator_Sub();
	Mul = new Operator_Mul();
	Div = new Operator_Div();
}

//-----------------------------------------------------------------------------
// Operator_Add
//-----------------------------------------------------------------------------
Expr *Operator_Add::Reduce(AutoPtr<Expr> pExprL, AutoPtr<Expr> pExprR) const
{
	if (pExprL->IsTypeNumber() && pExprR->IsTypeNumber()) {
		UInt32 numL = dynamic_cast<const Expr_Number *>(pExprL.get())->GetNumber();
		UInt32 numR = dynamic_cast<const Expr_Number *>(pExprR.get())->GetNumber();
		return new Expr_Number(numL + numR);
	} else if (pExprL->IsTypeLabelRef() && pExprR->IsTypeNumber()) {
		return new Expr_BinOp(Operator::Add, pExprR.release(), pExprL.release());
	}
	return new Expr_BinOp(Operator::Add, pExprL.release(), pExprR.release());
}

//-----------------------------------------------------------------------------
// Operator_Sub
//-----------------------------------------------------------------------------
Expr *Operator_Sub::Reduce(AutoPtr<Expr> pExprL, AutoPtr<Expr> pExprR) const
{
	if (pExprL->IsTypeNumber() && pExprR->IsTypeNumber()) {
		UInt32 numL = dynamic_cast<const Expr_Number *>(pExprL.get())->GetNumber();
		UInt32 numR = dynamic_cast<const Expr_Number *>(pExprR.get())->GetNumber();
		return new Expr_Number(numL - numR);
	}
	return new Expr_BinOp(Operator::Sub, pExprL.release(), pExprR.release());
}

//-----------------------------------------------------------------------------
// Operator_Mul
//-----------------------------------------------------------------------------
Expr *Operator_Mul::Reduce(AutoPtr<Expr> pExprL, AutoPtr<Expr> pExprR) const
{
	if (pExprL->IsTypeNumber() && pExprR->IsTypeNumber()) {
		UInt32 numL = dynamic_cast<const Expr_Number *>(pExprL.get())->GetNumber();
		UInt32 numR = dynamic_cast<const Expr_Number *>(pExprR.get())->GetNumber();
		return new Expr_Number(numL * numR);
	}
	return new Expr_BinOp(Operator::Mul, pExprL.release(), pExprR.release());
}

//-----------------------------------------------------------------------------
// Operator_Div
//-----------------------------------------------------------------------------
Expr *Operator_Div::Reduce(AutoPtr<Expr> pExprL, AutoPtr<Expr> pExprR) const
{
	if (pExprL->IsTypeNumber() && pExprR->IsTypeNumber()) {
		UInt32 numL = dynamic_cast<const Expr_Number *>(pExprL.get())->GetNumber();
		UInt32 numR = dynamic_cast<const Expr_Number *>(pExprR.get())->GetNumber();
		if (numR == 0) return nullptr;
		return new Expr_Number(numL / numR);
	}
	return new Expr_BinOp(Operator::Div, pExprL.release(), pExprR.release());
}