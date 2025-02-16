#pragma once
#include <string>
#include "TokenType.h"

namespace Lex {
	struct Token
	{
		TokenType token;
		std::string value;

		Token(TokenType token, std::string value = ";") : token(token), value(value) { };
	};
}