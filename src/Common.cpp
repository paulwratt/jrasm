//=============================================================================
// Common.cpp
//=============================================================================
#include "stdafx.h"

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
String ToLower(const char *str)
{
	String rtn;
	for (const char *p = str; *p != '\0'; ) {
		char ch = *p;
		if ('A' <= ch && ch <= 'Z') {
			rtn += ch - 'A' + 'a';
			p++;
		} else {
			rtn += ch;
			p++;
		}
	}
	return rtn;
}

String ToUpper(const char *str)
{
	String rtn;
	for (const char *p = str; *p != '\0'; ) {
		char ch = *p;
		if ('a' <= ch && ch <= 'z') {
			rtn += ch - 'a' + 'A';
			p++;
		} else {
			rtn += ch;
			p++;
		}
	}
	return rtn;
}
