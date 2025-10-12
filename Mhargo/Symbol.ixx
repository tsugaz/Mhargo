export module Symbol;

export class Symbol {
public:
	char* lable = 0;
	enum symbolType { OPEATER, VARIABLE_NAME, INTEGER, FLOAT_DOUBLE, STRING, KEYWORD, DELIMITER, FUNCTION_NAME, BOOLEAN, CHAR, ARRAY, POINTER, STRUCT_CLASS, ENUM, NUL, COMMENT, NONE} type = NUL;
	/*
	0 - operator
	1 - variable name
	2 - integer
	3 - float/double
	4 - string
	5 - keyword
	6 - delimiter
	7 - function name
	8 - boolean
	9 - char
	10 - array
	11 - pointer
	12 - struct/class
	13 - enum
	14 - null
	15 - comment
	*/
	unsigned int index = 0;

	Symbol(char* rlable, symbolType rtype, unsigned int rindex);
};

