import TokenType;
import std;
export module LexicalAnalyzer;

namespace Mhargo::LexicalAnalyzer {
	// Analyzes numeric types based on their lexemes and assigns appropriate token types
	Mhargo::Tokens::Token numericTypesAnalyzer(const std::string& lexeme, const std::string& tokenname) {
		using namespace Mhargo::Tokens;
		Token* token = new Token(types::TokenType::NULL, tokenname);
		NumberType* type = new types::NumberType;
		*type = NumberType::NULL;
		for (char i : lexeme) {
			switch (i) {
			case 'x':
				goto numhexadecimal;
			case 'X':
			numhexadecimal:
				*type = types::NumberType::HEXADECIMAL;
				token->type = types::TokenType::INT32;
				return *token;
			case 'b':
				goto numbinary;
			case 'B':
			numbinary:
				*type = types::NumberType::BINARY;
				token->type = types::TokenType::INT32;
				return *token;
			case 'o':
				goto numoctal;
			case 'O':
			numoctal:
				*type = types::NumberType::OCTAL;
				token->type = types::TokenType::INT32;
				return *token;
			default:
				if (*type == types::NumberType::NULL) {
					*type = types::NumberType::DECIMAL;
					token->type = types::TokenType::INT32;
				}
			}
		}
		return *token;
	}

	// lexical analyzer main function
	void lexicalAnalyzer( void ) {
		std::string *lexicalUnit = new std::string;
		std::vector<Mhargo::Tokens::Token> tokens;
		// put lexicalUnit into fileReader function
		for (char i : *lexicalUnit) {
			if ((i > '0' && i <= '9') || (((i == 'o' || i == 'O') || (i == 'b' || i == 'B')) || (i == 'x' || i == 'X'))) {
				numericTypesAnalyzer(*lexicalUnit, "NumericLiteral");
				break;
			}
		}
	}
}