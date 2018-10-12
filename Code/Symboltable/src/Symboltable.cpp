/*
 * Symboltable.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

using namespace std;
#include <iostream>
#include "../includes/Symboltable.h"

Symboltable::Symboltable() {
	// TODO Auto-generated constructor stub

}

Symboltable::~Symboltable() {
	// TODO Auto-generated destructor stub
}

SymtabEntry* Symboltable::insert(char* lexem) {
	unsigned int hash = this->hash(lexem);
	return NULL;
	//return new SymtabEntry(new Information(lexem, hash));
}

Information* Symboltable::lookup(SymtabEntry* key) {
	
}

// ==== Utilities for inserting ===

unsigned int Symboltable::hash(char* s) {
	unsigned int hashValue = 0;
	int stringLength = (this->stringLength(s)) - 1;
	char* current = s;
	while ( *current != '\n' ) {
		hashValue += *current * stringLength;
		current++;
		stringLength--;
	}
	return hashValue;
}

int Symboltable::stringLength(char* lexem) {
	char* current = lexem;
	int stringLength = 0;
	while ( *current != '\n' ) {
		stringLength++;
		current++;
	}
	return stringLength;
}

void Symboltable::initSymbols() {

}
