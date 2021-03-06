//=============================================================================
// Expr.h
//=============================================================================
#ifndef __JRASMCORE_EXPR_H__
#define __JRASMCORE_EXPR_H__

#include "Directive.h"
#include "Operator.h"
#include "DisasmDumper.h"
#include "InlineData.h"

class ExprOwner;
class Expr;
class Expr_Label;

//-----------------------------------------------------------------------------
// ExprDict
//-----------------------------------------------------------------------------
class ExprDict : public std::map<String, Expr *, LessThan_StringICase> {
private:
	int _cntRef;
	AutoPtr<ExprDict> _pExprDictParent;
public:
	DeclareReferenceAccessor(ExprDict);
public:
	inline ExprDict(ExprDict *pExprDictParent = nullptr) :
	_cntRef(1), _pExprDictParent(pExprDictParent) {}
private:
	~ExprDict();
public:
	inline ExprDict *GetParent() { return _pExprDictParent.get(); }
	void Assign(const String &symbol, Expr *pExpr, bool forceGlobalFlag);
	bool IsAssigned(const char *symbol) const;
	const Expr *Lookup(const char *symbol) const;
	ExprDict *GetGlobal();
	inline const ExprDict *GetGlobal() const {
		return const_cast<ExprDict *>(this)->GetGlobal();
	}
};

//-----------------------------------------------------------------------------
// ExprList
//-----------------------------------------------------------------------------
class ExprList : public std::vector<Expr *> {
public:
	Expr_Label *SeekLabelToAssoc();
	void AssignExprDict(Context &context, bool recursiveFlag);
	bool OnPhasePreprocess(Context &context);
	bool OnPhaseAssignMacro(Context &context);
	bool OnPhaseExpandMacro(Context &context);
	bool OnPhaseAssignSymbol(Context &context);
	bool OnPhaseGenerate(Context &context, Binary *pBuffDst) const;
	bool OnPhaseDisasm(Context &context, DisasmDumper &disasmDumper, int indentLevelCode) const;
	String ComposeSource(bool upperCaseFlag, const char *sep) const;
	void Print(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// ExprOwner
//-----------------------------------------------------------------------------
class ExprOwner : public ExprList {
private:
	int _cntRef;
public:
	DeclareReferenceAccessor(ExprOwner);
public:
	inline ExprOwner() : _cntRef(1) {}
protected:
	~ExprOwner();
public:
	void Clear();
	ExprOwner *Clone() const;
	ExprOwner *Resolve(Context &context) const;
	ExprOwner *Substitute(const ExprDict &exprDict) const;
};

//-----------------------------------------------------------------------------
// Expr
//-----------------------------------------------------------------------------
class Expr {
public:
	enum Type {
		TYPE_Null,
		TYPE_Group,
		TYPE_Integer,
		TYPE_String,
		TYPE_BitPattern,
		TYPE_MML,
		TYPE_UnaryOp,
		TYPE_BinaryOp,
		TYPE_Assign,
		TYPE_Bracket,
		TYPE_Brace,
		TYPE_Label,
		TYPE_Symbol,
		TYPE_Instruction,
		TYPE_Directive,
	};
public:
protected:
	int _cntRef;
	Type _type;
	AutoPtr<ExprOwner> _pExprOperands;
	AutoPtr<ExprOwner> _pExprChildren;
	AutoPtr<ExprDict> _pExprDict;
	AutoPtr<StringShared> _pPathNameSrc;
	int _lineNo;
public:
	DeclareReferenceAccessor(Expr);
public:
	Expr(Type type);
	Expr(Type type, ExprOwner *pExprOperands);
	Expr(Type type, ExprOwner *pExprOperands, ExprOwner *pExprChildren);
	Expr(const Expr &expr);
protected:
	virtual ~Expr();
public:
	inline bool IsType(Type type) const { return _type == type; }
	inline bool IsTypeNull() const { return IsType(TYPE_Null); }
	inline bool IsTypeGroup() const { return IsType(TYPE_Group); }
	inline bool IsTypeInteger() const { return IsType(TYPE_Integer); }
	inline bool IsTypeBuffer() const { return IsType(TYPE_String) || IsType(TYPE_BitPattern) || IsType(TYPE_MML); }
	inline bool IsTypeString() const { return IsType(TYPE_String); }
	inline bool IsTypeBitPattern() const { return IsType(TYPE_BitPattern); }
	inline bool IsTypeMML() const { return IsType(TYPE_MML); }
	inline bool IsTypeUnaryOp() const { return IsType(TYPE_UnaryOp); }
	inline bool IsTypeBinaryOp() const { return IsType(TYPE_BinaryOp); }
	inline bool IsTypeAssign() const { return IsType(TYPE_Assign); }
	inline bool IsTypeBracket() const { return IsType(TYPE_Bracket); }
	inline bool IsTypeBrace() const { return IsType(TYPE_Brace); }
	inline bool IsTypeLabel() const { return IsType(TYPE_Label); }
	inline bool IsTypeSymbol() const { return IsType(TYPE_Symbol); }
	inline bool IsTypeInstruction() const { return IsType(TYPE_Instruction); }
	inline bool IsTypeDirective() const { return IsType(TYPE_Directive); }
	inline Type GetType() const { return _type; }
	inline ExprOwner &GetExprOperands() { return *_pExprOperands; }
	inline const ExprOwner &GetExprOperands() const { return *_pExprOperands; }
	inline ExprOwner &GetExprChildren() { return *_pExprChildren; }
	inline const ExprOwner &GetExprChildren() const { return *_pExprChildren; }
	inline void SetSourceInfo(StringShared *pPathNameSrc, int lineNo) {
		_pPathNameSrc.reset(pPathNameSrc), _lineNo = lineNo;
	}
	inline bool HasSourceInfo() const { return !_pPathNameSrc.IsNull(); }
	inline void DeriveSourceInfo(const Expr *pExpr) {
		_pPathNameSrc.reset(pExpr->_pPathNameSrc->Reference());
		_lineNo = pExpr->_lineNo;
	}
	inline const char *GetPathNameSrc() const {
		return _pPathNameSrc.IsNull()? "" : _pPathNameSrc->GetString();
	}
	inline int GetLineNo() const { return _lineNo; }
	inline bool IsExprDictReady() const { return !_pExprDict.IsNull(); }
	inline const ExprDict *GetExprDict() const { return _pExprDict.get(); }
	void AssignExprDict(Context &context, bool recursiveFlag);
	bool IsTypeLabel(const char *symbol) const;
	bool IsTypeSymbol(const char *symbol) const;
	bool IsTypeUnaryOp(const Operator *pOperator) const;
	bool IsTypeBinaryOp(const Operator *pOperator) const;
	bool IsTypeDirective(const DirectiveFactory *pDirectiveFactory) const;
	bool IsGroupingDirective() const;
	void Print() const;
	static InlineData::Type GetInlineDataType(Type type);
	inline InlineData::Type GetInlineDataType() const { return GetInlineDataType(_type); }
	virtual bool OnPhasePreprocess(Context &context);
	virtual bool OnPhaseAssignMacro(Context &context);
	virtual bool OnPhaseExpandMacro(Context &context);
	virtual bool OnPhaseAssignSymbol(Context &context);
	virtual bool OnPhaseGenerate(Context &context, Binary *pBuffDst) const;
	virtual bool OnPhaseDisasm(Context &context, DisasmDumper &disasmDumper, int indentLevelCode) const;
	virtual void GetFields(ExprList &exprFields) const;
	virtual Expr *Resolve(Context &context) const = 0;
	virtual Expr *Clone() const = 0;
	virtual Expr *Substitute(const ExprDict &exprDict) const = 0;
	virtual String ComposeSource(bool upperCaseFlag) const = 0;
};

//-----------------------------------------------------------------------------
// ExprStack
//-----------------------------------------------------------------------------
class ExprStack : public ExprOwner {
};

//-----------------------------------------------------------------------------
// ExprDictList
//-----------------------------------------------------------------------------
class ExprDictList : public std::vector<ExprDict *> {
};

//-----------------------------------------------------------------------------
// ExprDictList
//-----------------------------------------------------------------------------
class ExprDictOwner : public ExprDictList {
public:
	~ExprDictOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// ExprDictOwner
//-----------------------------------------------------------------------------
typedef ExprDictOwner ExprDictStack;

//-----------------------------------------------------------------------------
// Expr_Null
//-----------------------------------------------------------------------------
class Expr_Null : public Expr {
public:
	static const Type TYPE;
public:
	inline Expr_Null() : Expr(TYPE) {}
	inline Expr_Null(const Expr_Null &expr) : Expr(expr) {}
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_Group
//-----------------------------------------------------------------------------
class Expr_Group : public Expr {
public:
	static const Type TYPE;
public:
	inline Expr_Group() : Expr(TYPE) {}
	inline Expr_Group(ExprOwner *pExprOperands) : Expr(TYPE, pExprOperands) {}
	inline Expr_Group(ExprOwner *pExprOperands, ExprOwner *pExprChildren) :
		Expr(TYPE, pExprOperands, pExprChildren) {}
	inline Expr_Group(const Expr_Group &expr) : Expr(expr) {}
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_Integer
//-----------------------------------------------------------------------------
class Expr_Integer : public Expr {
private:
	String _str;
	Integer _num;
	AutoPtr<Region> _pRegion;
public:
	static const Type TYPE;
public:
	inline Expr_Integer(Integer num) : Expr(TYPE), _num(num) {}
	inline Expr_Integer(Integer num, Region *pRegion) : Expr(TYPE), _num(num), _pRegion(pRegion) {}
	inline Expr_Integer(const String &str, Integer num) : Expr(TYPE), _str(str), _num(num) {}
	inline Expr_Integer(const Expr_Integer &expr) :
		Expr(expr), _str(expr._str), _num(expr._num), _pRegion(Region::Reference(expr._pRegion.get())) {}
	inline Integer GetInteger() const { return _pRegion.IsNull()? _num : _num + _pRegion->GetAddrTop(); }
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_Buffer
//-----------------------------------------------------------------------------
class Expr_Buffer : public Expr {
protected:
	AutoPtr<InlineData> _pInlineData;	// valid when the buffer appears as an operand
public:
	inline Expr_Buffer(Type type) : Expr(type) {}
	inline Expr_Buffer(const Expr_Buffer &expr) :
		Expr(expr), _pInlineData(InlineData::Reference(expr._pInlineData.get())) {}
	inline void SetInlineData(InlineData *pInlineData) { _pInlineData.reset(pInlineData); }
	inline InlineData *GetInlineData() { return _pInlineData.get(); }
	virtual const Binary &GetBinary() const = 0;
};

//-----------------------------------------------------------------------------
// Expr_String
//-----------------------------------------------------------------------------
class Expr_String : public Expr_Buffer {
private:
	String _str;
public:
	static const Type TYPE;
public:
	inline Expr_String(const String &str) : Expr_Buffer(TYPE), _str(str) {}
	inline Expr_String(const Expr_String &expr) : Expr_Buffer(expr), _str(expr._str) {}
	inline const char *GetString() const { return _str.c_str(); }
	virtual const Binary &GetBinary() const;
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_BitPattern
//-----------------------------------------------------------------------------
class Expr_BitPattern : public Expr_Buffer {
private:
	String _str;
	Binary _buff;
public:
	static const Type TYPE;
public:
	inline Expr_BitPattern(const String &str, const Binary &buff) :
		Expr_Buffer(TYPE), _str(str), _buff(buff) {}
	inline Expr_BitPattern(const Expr_BitPattern &expr) :
		Expr_Buffer(expr), _str(expr._str), _buff(expr._buff) {}
	inline const char *GetString() const { return _str.c_str(); }
	virtual const Binary &GetBinary() const;
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_MML
//-----------------------------------------------------------------------------
class Expr_MML : public Expr_Buffer {
private:
	String _str;
	AutoPtr<BinaryShared> _pBuffShared;
public:
	static const Type TYPE;
public:
	inline Expr_MML(const String &str, BinaryShared *pBuffShared) :
		Expr_Buffer(TYPE), _str(str), _pBuffShared(pBuffShared) {}
	inline Expr_MML(const Expr_MML &expr) :
		Expr_Buffer(expr), _str(expr._str), _pBuffShared(expr._pBuffShared->Reference()) {}
	inline const char *GetString() const { return _str.c_str(); }
	virtual const Binary &GetBinary() const;
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_Assign
//-----------------------------------------------------------------------------
class Expr_Assign : public Expr {
public:
	static const Type TYPE;
public:
	inline Expr_Assign(Expr *pExprL, Expr *pExprR) : Expr(TYPE) {
		GetExprOperands().push_back(pExprL);
		GetExprOperands().push_back(pExprR);
	}
	inline Expr_Assign(ExprOwner *pExprOperands) : Expr(TYPE, pExprOperands) {}
	inline Expr_Assign(ExprOwner *pExprOperands, ExprOwner *pExprChildren) :
		Expr(TYPE, pExprOperands, pExprChildren) {}
	inline Expr_Assign(const Expr_Assign &expr) : Expr(expr) {}
	inline Expr *GetLeft() { return GetExprOperands()[0]; }
	inline Expr *GetRight(){ return GetExprOperands()[1]; }
	inline const Expr *GetLeft() const { return GetExprOperands()[0]; }
	inline const Expr *GetRight() const { return GetExprOperands()[1]; }
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_UnaryOp
//-----------------------------------------------------------------------------
class Expr_UnaryOp : public Expr {
private:
	const Operator *_pOperator;
public:
	static const Type TYPE;
public:
	inline Expr_UnaryOp(const Operator *pOperator, Expr *pExprOperand) :
			Expr(TYPE), _pOperator(pOperator) {
		GetExprOperands().push_back(pExprOperand);
	}
	inline Expr_UnaryOp(const Operator *pOperator, ExprOwner *pExprOperands) :
		Expr(TYPE, pExprOperands), _pOperator(pOperator) {}
	inline Expr_UnaryOp(const Operator *pOperator, ExprOwner *pExprOperands, ExprOwner *pExprChildren) :
		Expr(TYPE, pExprOperands, pExprChildren), _pOperator(pOperator) {}
	inline Expr_UnaryOp(const Expr_UnaryOp &expr) : Expr(expr), _pOperator(expr._pOperator) {}
	inline Expr *GetOperand() { return GetExprOperands()[0]; }
	inline const Expr *GetOperand() const { return GetExprOperands()[0]; }
	inline const Operator *GetOperator() const { return _pOperator; }
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_BinaryOp
//-----------------------------------------------------------------------------
class Expr_BinaryOp : public Expr {
private:
	const Operator *_pOperator;
public:
	static const Type TYPE;
public:
	inline Expr_BinaryOp(const Operator *pOperator, Expr *pExprL, Expr *pExprR) :
			Expr(TYPE), _pOperator(pOperator) {
		GetExprOperands().push_back(pExprL);
		GetExprOperands().push_back(pExprR);
	}
	inline Expr_BinaryOp(const Operator *pOperator, ExprOwner *pExprOperands) :
		Expr(TYPE, pExprOperands), _pOperator(pOperator) {}
	inline Expr_BinaryOp(const Operator *pOperator, ExprOwner *pExprOperands, ExprOwner *pExprChildren) :
		Expr(TYPE, pExprOperands, pExprChildren), _pOperator(pOperator) {}
	inline Expr_BinaryOp(const Expr_BinaryOp &expr) : Expr(expr), _pOperator(expr._pOperator) {}
	inline Expr *GetLeft() { return GetExprOperands()[0]; }
	inline Expr *GetRight(){ return GetExprOperands()[1]; }
	inline const Expr *GetLeft() const { return GetExprOperands()[0]; }
	inline const Expr *GetRight() const { return GetExprOperands()[1]; }
	inline const Operator *GetOperator() const { return _pOperator; }
	virtual void GetFields(ExprList &exprFields) const;
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_Bracket
//-----------------------------------------------------------------------------
class Expr_Bracket : public Expr {
public:
	static const Type TYPE;
public:
	inline Expr_Bracket() : Expr(TYPE) {}
	inline Expr_Bracket(ExprOwner *pExprOperands) : Expr(TYPE, pExprOperands) {}
	inline Expr_Bracket(ExprOwner *pExprOperands, ExprOwner *pExprChildren) :
		Expr(TYPE, pExprOperands, pExprChildren) {}
	inline Expr_Bracket(const Expr_Bracket &expr) : Expr(expr) {}
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_Brace
//-----------------------------------------------------------------------------
class Expr_Brace : public Expr {
public:
	static const Type TYPE;
public:
	inline Expr_Brace() : Expr(TYPE) {}
	inline Expr_Brace(ExprOwner *pExprOperands) : Expr(TYPE, pExprOperands) {}
	inline Expr_Brace(ExprOwner *pExprOperands, ExprOwner *pExprChildren) :
		Expr(TYPE, pExprOperands, pExprChildren) {}
	inline Expr_Brace(const Expr_Brace &expr) : Expr(expr) {}
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_Label
//-----------------------------------------------------------------------------
class Expr_Label : public Expr {
private:
	String _symbol;
	bool _forceGlobalFlag;
public:
	static const Type TYPE;
public:
	inline Expr_Label(const String &symbol, bool forceGlobalFlag) :
		Expr(TYPE), _symbol(symbol), _forceGlobalFlag(forceGlobalFlag) {}
	inline Expr_Label(const Expr_Label &expr) :
		Expr(expr), _symbol(expr._symbol), _forceGlobalFlag(expr._forceGlobalFlag) {}
	inline void SetAssigned(Expr *pExprAssigned) { GetExprChildren().push_back(pExprAssigned); }
	inline Expr *GetAssigned() { return GetExprChildren().back(); }
	inline const Expr *GetAssigned() const { return GetExprChildren().back(); }
	inline bool IsAssigned() const { return !GetExprChildren().empty(); }
	inline const char *GetSymbol() const { return _symbol.c_str(); }
	inline bool GetForceGlobalFlag() const { return _forceGlobalFlag; }
	inline bool MatchCase(const char *symbol) const { return ::strcmp(_symbol.c_str(), symbol) == 0; }
	inline bool MatchICase(const char *symbol) const { return ::strcasecmp(_symbol.c_str(), symbol) == 0; }
	virtual bool OnPhaseAssignSymbol(Context &context);
	virtual bool OnPhaseDisasm(Context &context, DisasmDumper &disasmDumper, int indentLevelCode) const;
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
	static String MakeSource(const char *symbol, bool forceGlobalFlag);
};

//-----------------------------------------------------------------------------
// Expr_Symbol
//-----------------------------------------------------------------------------
class Expr_Symbol : public Expr {
private:
	String _symbol;
	AutoPtr<Expr> _pExprAssigned;	// not cloned
public:
	static const Type TYPE;
public:
	inline Expr_Symbol(const String &symbol) : Expr(TYPE), _symbol(symbol) {}
	inline Expr_Symbol(const Expr_Symbol &expr) : Expr(expr), _symbol(expr._symbol) {}
	inline const char *GetSymbol() const { return _symbol.c_str(); }
	inline bool MatchCase(const char *symbol) const { return ::strcmp(_symbol.c_str(), symbol) == 0; }
	inline bool MatchICase(const char *symbol) const { return ::strcasecmp(_symbol.c_str(), symbol) == 0; }
	virtual bool OnPhaseAssignSymbol(Context &context);
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_Instruction
//-----------------------------------------------------------------------------
class Expr_Instruction : public Expr {
private:
	String _symbol;
	AutoPtr<ExprOwner> _pExprsExpanded;
public:
	static const Type TYPE;
public:
	inline Expr_Instruction(const String &symbol) : Expr(TYPE), _symbol(symbol) {}
	inline Expr_Instruction(const String &symbol, ExprOwner *pExprOperands) :
		Expr(TYPE, pExprOperands), _symbol(symbol) {}
	inline Expr_Instruction(const String &symbol, ExprOwner *pExprOperands, ExprOwner *pExprChildren) :
		Expr(TYPE, pExprOperands, pExprChildren), _symbol(symbol) {}
	inline Expr_Instruction(const Expr_Instruction &expr) :
		Expr(expr), _symbol(expr._symbol),
		_pExprsExpanded(expr._pExprsExpanded.IsNull()? nullptr : expr._pExprsExpanded->Clone()) {}
	inline const char *GetSymbol() const { return _symbol.c_str(); }
	virtual bool OnPhasePreprocess(Context &context);
	virtual bool OnPhaseExpandMacro(Context &context);
	virtual bool OnPhaseAssignSymbol(Context &context);
	virtual bool OnPhaseGenerate(Context &context, Binary *pBuffDst) const;
	virtual bool OnPhaseDisasm(Context &context, DisasmDumper &disasmDumper, int indentLevelCode) const;
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

//-----------------------------------------------------------------------------
// Expr_Directive
//-----------------------------------------------------------------------------
class Expr_Directive : public Expr {
private:
	AutoPtr<Directive> _pDirective;
public:
	static const Type TYPE;
public:
	inline Expr_Directive(Directive *pDirective) :
		Expr(TYPE), _pDirective(pDirective) {}
	inline Expr_Directive(Directive *pDirective, ExprOwner *pExprOperands) :
		Expr(TYPE, pExprOperands), _pDirective(pDirective) {}
	inline Expr_Directive(Directive *pDirective, ExprOwner *pExprOperands, ExprOwner *pExprChildren) :
		Expr(TYPE, pExprOperands, pExprChildren), _pDirective(pDirective) {}
	inline Expr_Directive(const Expr_Directive &expr) :
		Expr(expr), _pDirective(expr._pDirective->Reference()) {}
	inline Directive *GetDirective() { return _pDirective.get(); }
	inline const Directive *GetDirective() const { return _pDirective.get(); }
	virtual bool OnPhasePreprocess(Context &context);
	virtual bool OnPhaseAssignMacro(Context &context);
	virtual bool OnPhaseExpandMacro(Context &context);
	virtual bool OnPhaseAssignSymbol(Context &context);
	virtual bool OnPhaseGenerate(Context &context, Binary *pBuffDst) const;
	virtual bool OnPhaseDisasm(Context &context, DisasmDumper &disasmDumper, int indentLevelCode) const;
	virtual Expr *Resolve(Context &context) const;
	virtual Expr *Clone() const;
	virtual Expr *Substitute(const ExprDict &exprDict) const;
	virtual String ComposeSource(bool upperCaseFlag) const;
};

#endif
