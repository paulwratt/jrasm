//=============================================================================
// Parser.h
//=============================================================================
#ifndef __PARSER_H__
#define __PARSER_H__

#include "Common.h"

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
class Parser : public Tokenizer::Listener {
private:
	enum Stat {
		STAT_LineTop,
		STAT_Label,
		STAT_Instruction,
		STAT_Operand,
	};
private:
	Tokenizer _tokenizer;
	Stat _stat;
	ExprOwner _exprOwner;
	ExprStack _exprStack;
public:
	Parser(const String &fileNameSrc);
	inline const ExprOwner &GetInstructions() const { return _exprOwner; }
	inline bool FeedChar(char ch) { return _tokenizer.FeedChar(ch); }
	inline const char *GetErrMsg() const { return _tokenizer.GetErrMsg(); }
	virtual bool FeedToken(const Token &token);
};

#endif
