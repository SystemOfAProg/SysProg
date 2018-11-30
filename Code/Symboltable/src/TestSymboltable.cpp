#include "../includes/Symboltable.h"
#include <iostream>

const char* symTabLexems[] = {
		"position",
		"initial",
		"i",
		"thisIsAVeryLongLexem", // 20 characters
		"123456",
		"A1B2C3",
		// 1024 characters ( -> to long for stringtabnodes), exclude this from regular tests
		"0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123"
	};

int numDigits(int number) {
    int digits = 0;
    if (number < 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

// Check generated hashvalues
bool testSymTableInsert() {
	bool testSuccess = true;
	Symboltable* symboltable = new Symboltable();
	for(int i=0; i<6; i++) {
		int hashValue = symboltable->hash((char*)symTabLexems[i]);
		if (hashValue < (unsigned int)0 || hashValue > symboltable->getTableSize()) {
			std::cout << "Hash Value was not inside the Tablesizes boundary: \"" << symTabLexems[i] << "\" : " << hashValue << std::endl;
			testSuccess = false;
		}
	}
	return testSuccess;
}

bool testStringTable() {
	bool testSuccess = true;
	StringTable* st = new StringTable();
	for(int i=0; i<7; i++) {
		char* position = NULL;
		position = st->insert((char*)symTabLexems[i]);
		if (i != 6 && position == NULL) {
			testSuccess = false;
		}
	}
	// st->print();
	st->~StringTable();
	return testSuccess;
}

bool testLookup() {
	Symboltable* st = new Symboltable();
	if (st->lookup((char*)symTabLexems[0]) != NULL) {
		return false;
	}
	st->insert((char*)symTabLexems[0]);
	if (st->lookup((char*)symTabLexems[0]) == NULL) {
		return false;
	}
	if (st->lookup((char*)symTabLexems[1]) != NULL) {
		return false;
	}
	return true;
}

int main(int argc, char **argv) {
	int failedTestCounter = 0;
	if (!testSymTableInsert()) {
		std::cout << "Error in test \"testSymTableInsert()\"" << std::endl;
		failedTestCounter++;
	}
	if (!testStringTable()) {
		std::cout << "Error in test \"testStringTable()\"" << std::endl;
		failedTestCounter++;
	}
	if (!testLookup()) {
		std::cout << "Error in test \"testLookup()\"" << std::endl;
		failedTestCounter++;
	}
	std::cout << failedTestCounter << " errors happened in the test execution" << std::endl;
	return 0;
}