import TokenType;
import std;
export module SyntacticAnalyzer;

namespace Mhargo::SyntacticAnalyzer {
	Mhargo::Tokens::types::Token numericTypesAnalyzer(const std::string& lexeme, const std::string& tokenname) {
		using namespace Mhargo::Tokens;
		types::Token *token = new types::Token(types::TokenType::NULL, tokenname);
		types::NumberType *type = new types::NumberType;
		*type = types::NumberType::NULL;
		for (char i : lexeme) {
			switch (i) {
			case 'x':
			case 'X':
				*type = types::NumberType::HEXADECIMAL;
				token->type = types::TokenType::INT32;
				return *token;
			default:
				break;
			}
		}
		
	}
}