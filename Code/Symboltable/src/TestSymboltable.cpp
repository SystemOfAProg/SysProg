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

bool testSymTableInsert() {
	bool testSuccess = true;
	Symboltable* symboltable = new Symboltable();
	const char* lexems[] = {
		"position",
		"initial",
		"i",
		"thisIsAVeryLongLexem",
		"123456",
		"A1B2C3"
	};
	for(int i=0; i<6; i++) {
		int hashValue = symboltable->hash((char*)lexems[i]);
		if (numDigits(hashValue) != 9) {
			std::cout << "Hash Value with wrong length detected for lexem \"" << lexems[i] << "\" : " << hashValue << std::endl;
			testSuccess = false;
		}
	}
	return testSuccess;
}

int main(int argc, char **argv) {
	int failedTestCounter = 0;
	if (!testSymTableInsert()) {
		std::cout << "Error in test \"testSymTableInsert()\"" << std::endl;
		failedTestCounter++;
	}
	std::cout << failedTestCounter << " errors happened in the test execution" << std::endl;
}