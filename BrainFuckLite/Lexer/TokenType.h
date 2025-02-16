#pragma once

enum class TokenType : char
{
	NEXT_BYTE,	// >
	LAST_BYTE,	// <

	FOR_START,	// [
	FOR_END,	// ]

	PLUS,		// +
	MINUS,		// -

	VALUE,		// . 

	INPUT,		// *
	OUTPUP,		// !
};