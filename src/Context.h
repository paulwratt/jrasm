//=============================================================================
// Context.h
//=============================================================================
#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "Region.h"

class Expr;

//-----------------------------------------------------------------------------
// Context
//-----------------------------------------------------------------------------
class Context {
public:
	class LookupTable : public std::map<String, UInt32> {
	private:
		int _cntRef;
		AutoPtr<LookupTable> _pLookupTableParent;
	public:
		DeclareReferenceAccessor(LookupTable);
	public:
		inline LookupTable(LookupTable *pLookupTableParent = nullptr) :
			_cntRef(1), _pLookupTableParent(pLookupTableParent) {}
	private:
		inline ~LookupTable() {}
	public:
		inline LookupTable *GetParent() { return _pLookupTableParent.get(); }
		static inline bool IsGlobalLabel(const char *label) { return *label != '@'; }
		void Set(const String &label, UInt32 value);
		bool IsDefined(const char *label) const;
		UInt32 Lookup(const char *label, bool *pFoundFlag) const;
		LookupTable *GetRoot();
		inline const LookupTable *GetRoot() const {
			return const_cast<LookupTable *>(this)->GetRoot();
		}
	};
	class LookupTableOwner : public std::vector<LookupTable *> {
	public:
		~LookupTableOwner();
		void Clear();
	};
	typedef LookupTableOwner LookupTableStack;
private:
	UInt32 _addr;
	RegionOwner _regionOwner;
	bool _preparationFlag;
	LookupTableStack _lookupTableStack;
public:
	Context();
	inline bool IsRegionAvailable() const { return !_regionOwner.empty(); }
	inline Binary &GetBuffer() { return _regionOwner.back()->GetBuffer(); }
	inline const Binary &GetBuffer() const { return _regionOwner.back()->GetBuffer(); }
	inline void ResetSegment() { _regionOwner.Clear(); }
	inline void StartRegion(UInt32 addr) { _regionOwner.push_back(new Region(addr)), _addr = addr; }
	inline UInt32 GetAddress() const { return _addr; }
	inline void ForwardAddress(UInt32 bytes) { _addr += bytes; }
	inline void SetPreparationFlag(bool preparationFlag) { _preparationFlag = preparationFlag; }
	inline bool GetPreparationFlag() const { return _preparationFlag; }
	inline LookupTable *GetLookupTable() { return _lookupTableStack.back(); }
	inline LookupTable *GetLookupTableRoot() { return _lookupTableStack.front(); }
	bool CheckRegionReady() const;
	LookupTable *AddLookupTable();
	void RemoveLookupTable();
};

#endif
