//=============================================================================
// jrasm.cpp
//=============================================================================
#include "stdafx.h"

bool Parse(const char *fileName)
{
	FILE *fp;
	if (::fopen_s(&fp, fileName, "rt") != 0) {
		::fprintf(stderr, "failed to open file\n");
		::exit(1);
	}
	Parser parser(fileName);
	for (;;) {
		int chRaw = ::fgetc(fp);
		char ch = (chRaw < 0)? '\0' : static_cast<unsigned char>(chRaw);
		if (!parser.FeedChar(ch)) {
			::fprintf(stderr, "%s\n", parser.GetErrMsg());
		}
		if (ch == '\0') break;
	}
	::fclose(fp);
	const ExprList &exprList = parser.GetInstructions();
	//exprList.Print();
	Context context(fileName, new Generator_M6800());
	for (auto pExpr : exprList) {
		context.ClearBuffer();
		pExpr->Generate(context);
		::printf("%-32s", pExpr->ToString().c_str());
		if (context.GetBuffer().empty()) {
			::printf("(none)\n");
		} else {
			context.Dump();
		}
	}
	return true;
}

int main(int argc, char *argv[])
{

#if 1
	if (argc < 2) {
		::fprintf(stderr, "usage: jasm file\n");
		::exit(1);
	}
	::Parse(argv[1]);
#else
	FILE *fp = ::fopen("test.cjr", "wb");
	CJRFormat::Write(fp, "hello", 0x2000,
					 (const UInt8 *)"\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f", 16);
	::fclose(fp);
#endif
	return 0;
}
