export module FileReader;

import std;
import Symbol;
#include <cstdio>

export class FileReader {
public:
	FileReader(const char* filename) {
		fopen_s(&file, filename, "r");
		if (!file) {
			throw "Could not open file";
		}
	}
	~FileReader() {
		if (file) {
			fclose(file);
		}
	}
	unsigned int readWord();
	std::vector<Symbol> symbolTab;
private:
	unsigned int index = 0;
	
	FILE* file;
};

