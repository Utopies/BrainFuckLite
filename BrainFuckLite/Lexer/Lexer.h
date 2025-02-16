#pragma once
#include <vector>
#include <string>
#include "TokenSt.h"

namespace Lex {
	class Lexer {
	private:
        static std::string_view input;
        static std::vector<Token> Tokens;

        static size_t position;
        static char current;

        static std::string collectDigits();
        static void SwithCurrent();
	public:
		//Lexer(std::string_view input) : input(input) { }

		static std::vector<Token> Tokenize(std::string_view input);
	};
}