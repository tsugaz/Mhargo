import std;

export module TokenType;

export namespace Mhargo::Tokens::inline types {
	export enum class TokenType {
		// Keywords
		FN, FOR, IF, ELSE, RETURN, WHILE, TRUE, FALSE,
		// Value Types
		INT16, INT32, INT64, INT128, UINT16, UINT32, UINT64, UINT128, STRING, BOOL, CHAR, BIGINT, FLOAT32, FLOAT64, FLOAT128,
		// Identifiers
		LEFT_PARENTHESIS, RIGHT_PARENTHESIS, LEFT_SQARE_BRACKET, RIGHT_SQARE_BRACKET, LEFT_BRACE, RIGHT_BRACE,
		LEFT_ANGLE_BRACKET, RIGHT_ANGLE_BRACKET, COMMA, DOT, COLON, SEMICOLON, QUOTATION_MARK,
		// Operators
		ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULO, ASSIGN, EQUALS, NOT_EQUALS, AND, OR, NOT, LESS_THAN, GREATER_THAN,
		NULL
	};

	export enum class NumberType {
		BINARY, OCTAL, DECIMAL, HEXADECIMAL, NULL
	};

	// Value Types Structures Of Numeric Types
	struct Int16 {
		short value;
		std::string tokenName;
	};
	struct Int32 {
		int value;
		std::string tokenName;
	};
	struct Int64 {
		long long value;
		std::string tokenName;
	};
	struct Int128 {
		struct {
			long long high;
			long long low;
		} value;
		std::string tokenName;
	};

	struct UInt16 {
		unsigned short value;
		std::string tokenName;
	};
	struct UInt32 {
		unsigned int value;
		std::string tokenName;
	};
	struct UInt64 {
		unsigned long long value;
		std::string tokenName;
	};
	struct UInt128 {
		struct {
			unsigned long long high;
			unsigned long long low;
		} value;
		std::string tokenName;
	};

	struct Float32 {
		float value;
		std::string tokenName;
	};
	struct Float64 {
		double value;
		std::string tokenName;
	};
	struct Float128 {
		long double value;
		std::string tokenName;
	};

	class BigInt {
	public:
		BigInt(const std::string& val, const std::string& tokenname) : value(val), tokenName(tokenname) {}

		BigInt operator+(const BigInt& other) {
			char* result = new char[std::max(value.length(), other.value.length()) + 2];
			std::string val1 = value;
			std::string val2 = other.value;
			std::reverse(val1.begin(), val1.end());
			std::reverse(val2.begin(), val2.end());
			int carry = 0;
			int i = 0;
			for (; i < val1.length() || i < val2.length() || carry; ++i) {
				int digit1 = (i < val1.length()) ? val1[i] - '0' : 0;
				int digit2 = (i < val2.length()) ? val2[i] - '0' : 0;
				int sum = digit1 + digit2 + carry;
				result[i] = (sum % 10) + '0';
				carry = sum / 10;
			}
			result[i] = '\0';
			std::reverse(result, result + i);
			return BigInt(std::string(result), "result");
		}

		BigInt operator-(const BigInt& other) {
			char* result = new char[value.length() + 1];
			std::string val1 = value;
			std::string val2 = other.value;
			std::reverse(val1.begin(), val1.end());
			std::reverse(val2.begin(), val2.end());
			int borrow = 0;
			int i = 0;
			for (; i < val1.length(); ++i) {
				int digit1 = val1[i] - '0' - borrow;
				int digit2 = (i < val2.length()) ? val2[i] - '0' : 0;
				if (digit1 < digit2) {
					digit1 += 10;
					borrow = 1;
				}
				else {
					borrow = 0;
				}
				int diff = digit1 - digit2;
				result[i] = diff + '0';
			}
			result[i] = '\0';
			std::reverse(result, result + i);
			return BigInt(std::string(result), "result");
		}

		BigInt operator*(const BigInt& other) {
			char* result = new char[value.length() + other.value.length() + 1];
			std::string val1 = value;
			std::string val2 = other.value;
			std::reverse(val1.begin(), val1.end());
			std::reverse(val2.begin(), val2.end());
			for (int i = 0; i < val1.length() + val2.length(); ++i) {
				result[i] = '0';
			}
			result[value.length() + other.value.length()] = '\0';
			for (int i = 0; i < val1.length(); ++i) {
				int carry = 0;
				for (int j = 0; j < val2.length() || carry; ++j) {
					int digit1 = val1[i] - '0';
					int digit2 = (j < val2.length()) ? val2[j] - '0' : 0;
					int existing = result[i + j] - '0';
					int prod = digit1 * digit2 + existing + carry;
					result[i + j] = (prod % 10) + '0';
					carry = prod / 10;
				}
			}
			int len = value.length() + other.value.length();
			while (len > 1 && result[len - 1] == '0') {
				--len;
			}
			result[len] = '\0';
			std::reverse(result, result + len);
			return BigInt(std::string(result), "result");
		}

		std::string getTokenName() const {
			return tokenName;
		}
		std::string getValue() const {
			return value;
		}

	private:
		std::string value;
		std::string tokenName;
	};

	class Token {
	public:
		TokenType type;
		std::string tokenName;
		Token(TokenType t, const std::string& name) : type(t), tokenName(name) {}
	};

}