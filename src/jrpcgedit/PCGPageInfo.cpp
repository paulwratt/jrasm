//=============================================================================
// PCGPageInfo.cpp
//=============================================================================
#include "stdafx.h"

//-----------------------------------------------------------------------------
// PCGPageInfo
//-----------------------------------------------------------------------------
PCGPageInfo::PCGPageInfo(const String &symbol, PCGType pcgType, int charCodeStart, bool upperCaseFlag) :
	_cntRef(1), _symbol(symbol), _pcgType(pcgType), _charCodeStart(charCodeStart), _upperCaseFlag(upperCaseFlag)
{
}

void PCGPageInfo::AddPCGInfo(PCGInfo *pPCGInfo)
{
	_pcgInfoOwner.push_back(pPCGInfo);
}

bool PCGPageInfo::WriteFile(FILE *fp)
{
	const char *strPCGPAGE = ".pcgpage";
	const char *strEND = ".end";
	if (_upperCaseFlag) {
		strPCGPAGE = ".PCGPAGE";
		strEND = ".END\n";
	}
	::fprintf(fp, "\t%s\t%s,%s,0x%02x\n", strPCGPAGE, GetSymbol(), GetPCGTypeName(), GetCharCodeStart());
	for (auto pPCGInfo : GetPCGInfoOwner()) {
		::fprintf(fp, "\n");
		if (!pPCGInfo->WriteFile(fp)) return false;
	}
	::fprintf(fp, "\n");
	::fprintf(fp, "\t%s\n", strEND);
	return true;
}

PCGPageInfo *PCGPageInfo::CreateFromExpr(Context &context, const Expr *pExpr)
{
	bool upperCaseFlag = true;
	String symbol;
	PCGType pcgType;
	int charCodeStart;
	if (!Directive_PCGPAGE::ExtractParams(pExpr, &symbol, &pcgType, &charCodeStart)) return nullptr;
	AutoPtr<PCGPageInfo> pPCGPageInfo(new PCGPageInfo(symbol, pcgType, charCodeStart, upperCaseFlag));
	bool firstFlag = true;
	for (auto pExprChild : pExpr->GetExprChildren()) {
		if (!pExprChild->IsTypeDirective(Directive::PCG)) continue;
		String symbol;
		int wdChar, htChar;
		int stepX, stepY;
		Binary buff;
		if (!Directive_PCG::ExtractParams(context, pExprChild, &symbol,
										  &wdChar, &htChar, &stepX, &stepY, buff)) return nullptr;
		AutoPtr<PCGInfo> pPCGInfo(
			new PCGInfo(symbol, PCGInfo::Pattern::CreateFromBuff(
							wdChar, htChar, buff), stepX, stepY, upperCaseFlag));
		pPCGInfo->SetSelectedFlag(firstFlag);
		firstFlag = false;
		pPCGPageInfo->AddPCGInfo(pPCGInfo.release());
	}
	if (pPCGPageInfo->IsEmptyPCGInfo()) pPCGPageInfo->NewPCGInfo();
	return pPCGPageInfo.release();
}

//-----------------------------------------------------------------------------
// PCGPageInfoList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// PCGPageInfoOwner
//-----------------------------------------------------------------------------
PCGPageInfoOwner::~PCGPageInfoOwner()
{
	Clear();
}

void PCGPageInfoOwner::Clear()
{
	for (auto pPCGPageInfo : *this) {
		PCGPageInfo::Delete(pPCGPageInfo);
	}
	clear();
}

void PCGPageInfoOwner::NewPCGPageInfo()
{
	bool upperCaseFlag = true;
	char symbol[256];
	::sprintf_s(symbol, "page%d", static_cast<int>(size()) + 1);
	AutoPtr<PCGPageInfo> pPCGPageInfo(new PCGPageInfo(symbol, PCGTYPE_User, 0x20, upperCaseFlag));
	pPCGPageInfo->NewPCGInfo();
	push_back(pPCGPageInfo.release());
}
