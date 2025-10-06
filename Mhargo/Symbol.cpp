#include "Symbol.h"

Symbol::Symbol(char* rlable, symbolType rtype, unsigned int rindex) {
	lable = rlable;
	type = rtype;
	index = rindex;
}