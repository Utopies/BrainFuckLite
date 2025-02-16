#include <iostream>
#include <fstream>
#include "Lexer/Lexer.h"
#include "BrainFuckLite.h"

using namespace std;

string translite(vector<Lex::Token> input);
string configSeting(int i);

int main()
{
	string fileProgramm = configSeting(0);
	int sizeRAM = stoi(configSeting(1));

	cout << fileProgramm << " " << sizeRAM << endl;

	std::string tasks = "<<>> 23 []";

	cout << translite(Lex::Lexer::Tokenize(tasks)) << endl;
	return 0; 
}

string translite(vector<Lex::Token> input) {
	string value = "";

	for (size_t i = 0; i < input.size(); i++) {
		if (input[i].token == TokenType::NEXT_BYTE) value += "NEXT_BYTE, ";
		else if (input[i].token == TokenType::LAST_BYTE) value += "LAST_BYTE, ";
		else if (input[i].token == TokenType::VALUE) value += "VALUE : " + input[i].value + ", ";
		else value += "token ";
	}

	return value;
}

string configSeting(int i) {
	std::string config;

	std::ifstream in("BFLConfig.txt");
	if (in.is_open())
	{
		std::string line;

		while (std::getline(in, line))
		{
			config = line;
		}
	}
	else {
		ofstream line("BFLConfig.txt");
		line << "30000\nProgramm.txt";
		std::cout << "File is not open" << endl;
	}
	in.close();

	return config;
}