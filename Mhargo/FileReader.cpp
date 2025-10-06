#include "FileReader.h"

unsigned int FileReader::readWord()
{
	char* word = new char[256];
	char ch;
	unsigned int length = 0;
	while (((((ch = getchar()) != 'EOF')&&ch!=32)&&ch!=10)&&ch!=13)
	{
		length++;
		*word++ = ch;
	}
	Symbol* symbol = new Symbol(word, Symbol::NONE, FileReader::index);
	index++;
	FileReader::symbolTab.push_back(*symbol);
	delete symbol; delete[] word;
	return length;
}

