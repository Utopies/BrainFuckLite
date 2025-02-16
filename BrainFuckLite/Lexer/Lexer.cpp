#include <iostream>
#include "Lexer.h"
#include "TokenType.h"

using namespace std;

vector<Lex::Token> Lex::Lexer::Tokenize(std::string_view input) {
	position = 0;

	::Lex::Lexer::input = input;

	current = input[position];

	while (position < input.length())
	{
		SwithCurrent();

		if (position >= input.length())
			break;
		else
		{
			position++;
			current = input[position];
		}
	}
	return Tokens;
}

void Lex::Lexer::SwithCurrent()
{
	switch (current)
	{
	case '<':
		Tokens.push_back(Token(TokenType::LAST_BYTE));
		break;
	case '>':
		Tokens.push_back(Token(TokenType::NEXT_BYTE));
		break;
	case '[':
		Tokens.push_back(Token(TokenType::FOR_START));
		break;
	case ']':
		Tokens.push_back(Token(TokenType::FOR_END));
		break;
	case '-':
		Tokens.push_back(Token(TokenType::MINUS));
		break;
	case '+':
		Tokens.push_back(Token(TokenType::PLUS));
		break;
	case '*':
		Tokens.push_back(Token(TokenType::INPUT));
		break;
	case '!':
		Tokens.push_back(Token(TokenType::OUTPUP));
		break;

	default:
		if (isdigit(current))
			Tokens.push_back(Token(TokenType::VALUE, collectDigits()));
		break;
	}
}

string Lex::Lexer::collectDigits()
{
	string buffer;

	while (isdigit(current))
	{
		buffer += current;
		position++;
		current = input[position];
	}

	if (std::stoi(buffer) > 255 || std::stoi(buffer) < 0)
	{
		cout << "Error : Value more 255 or less 0." << endl;
		cout << "Value is set to 0" << endl;

		buffer = "0";
	}

	return buffer;
}
