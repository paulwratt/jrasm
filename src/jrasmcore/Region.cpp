//=============================================================================
// Region.cpp
//=============================================================================
#include "stdafx.h"

//-----------------------------------------------------------------------------
// Region
//-----------------------------------------------------------------------------
Region::Region(Integer addrTop) : _cntRef(1), _addrTop(addrTop), _addrOffset(0)
{
	_buff.reserve(4096);
}

Region::Region(const Region &region) :
	_cntRef(1), _addrTop(region._addrTop), _addrOffset(region._addrOffset), _buff(region._buff)
{
}

void Region::AddRegionIngredient(Region *pRegion)
{
	_regionsIngredient.push_back(pRegion);
}

void Region::AppendFiller(UInt8 dataFiller, size_t bytes)
{
	while (bytes-- > 0) _buff += dataFiller;
}

void Region::Dump() const
{
	size_t col = 0;
	for (auto data : _buff) {
		if (col > 0) ::printf(" ");
		::printf("%02x", static_cast<UInt8>(data));
		col++;
		if (col == 32) {
			::printf("\n");
			col = 0;
		}
	}
	if (col > 0) ::printf("\n");
}

//-----------------------------------------------------------------------------
// RegionList
//-----------------------------------------------------------------------------
void RegionList::ResetAddrOffset()
{
	for (auto pRegion : *this) {
		pRegion->ResetAddrOffset();
	}
}

void RegionList::Sort()
{
	std::sort(begin(), end(), Region::LessThan());
}

RegionOwner *RegionList::Join(size_t bytesGapToJoin, UInt8 dataFiller) const
{
	std::unique_ptr<RegionOwner> pRegionOwner(new RegionOwner());
	const_iterator ppRegion = begin();
	if (ppRegion == end()) return pRegionOwner.release();
	const Region *pRegion = *ppRegion;
	//::printf("%04x-%04x\n", pRegion->GetAddrTop(), pRegion->GetAddrBtm());
	pRegionOwner->push_back(pRegion->Clone());
	Region *pRegionPrev = pRegionOwner->back();
	pRegionPrev->AddRegionIngredient(pRegion->Reference());
	ppRegion++;
	for ( ; ppRegion != end(); ppRegion++) {
		const Region *pRegion = *ppRegion;
		//::printf("%04x-%04x\n", pRegion->GetAddrTop(), pRegion->GetAddrBtm());
		if (pRegion->GetAddrTop() < pRegionPrev->GetAddrBtm()) {
			ErrorLog::AddError("memory regions are overwrapped at 0x%04x", pRegion->GetAddrTop());
			return nullptr;
		} else if (pRegion->GetAddrTop() - pRegionPrev->GetAddrBtm() < static_cast<Int32>(bytesGapToJoin)) {
			pRegionPrev->AppendFiller(dataFiller, pRegion->GetAddrTop() - pRegionPrev->GetAddrBtm());
			pRegionPrev->AppendBuffer(pRegion->GetBuffer());
			pRegionPrev->AddRegionIngredient(pRegion->Reference());
		} else {
			pRegionOwner->push_back(pRegion->Clone());
			pRegionPrev = pRegionOwner->back();
			pRegionPrev->AddRegionIngredient(pRegion->Reference());
		}
	}
	return pRegionOwner.release();
}

Region *RegionList::FindByAddrTop(Integer addrTop)
{
	for (auto pRegion : *this) {
		if (pRegion->GetAddrTop() == addrTop) return pRegion;
	}
	return nullptr;
}

Integer RegionList::GetAddrBtmMax() const
{
	Integer rtn = 0;
	for (auto pRegion : *this) {
		if (rtn < pRegion->GetAddrBtm()) rtn = pRegion->GetAddrBtm();
	}
	return rtn;
}

//-----------------------------------------------------------------------------
// RegionOwner
//-----------------------------------------------------------------------------
RegionOwner::~RegionOwner()
{
	Clear();
}

void RegionOwner::Clear()
{
	for (auto pRegion : *this) {
		Region::Delete(pRegion);
	}
	clear();
}
