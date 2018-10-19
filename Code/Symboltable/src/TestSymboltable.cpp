#include "../includes/Symboltable.h"
#include <iostream>

int numDigits(int number) {
    int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
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
	const char* lexems[] = {
		"position",
		"initial",
		"i",
		"thisIsAVeryLongLexem",
		"123456",
		"A1B2C3",
		"A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3A1B2C3"
	};
	for(int i=0; i<6; i++) {
		int hashValue = symboltable->hash((char*)lexems[i]);
		if (hashValue < (unsigned int)0 || hashValue > symboltable->getTableSize()) {
			std::cout << "Hash Value was not inside the Tablesizes boundary: \"" << lexems[i] << "\" : " << hashValue << std::endl;
			testSuccess = false;
		}
	}
	return testSuccess;
}

bool testStringTable() {
	bool testSuccess = true;
	return testSuccess;
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
	std::cout << failedTestCounter << " errors happened in the test execution" << std::endl;
}