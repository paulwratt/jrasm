//=============================================================================
// Pattern.h
//=============================================================================
#ifndef __JRPCGEDIT_PATTERN_H__
#define __JRPCGEDIT_PATTERN_H__

//-----------------------------------------------------------------------------
// Pattern
//-----------------------------------------------------------------------------
class Pattern {
private:
	int _cntRef;
public:
	DeclareReferenceAccessor(Pattern);
public:
	Pattern();
protected:
	inline ~Pattern() {};
public:
};

//-----------------------------------------------------------------------------
// PatternList
//-----------------------------------------------------------------------------
class PatternList : public std::vector<Pattern *> {
};

//-----------------------------------------------------------------------------
// PatternOwner
//-----------------------------------------------------------------------------
class PatternOwner : public PatternList {
public:
	~PatternOwner();
	void Clear();
};

#endif

