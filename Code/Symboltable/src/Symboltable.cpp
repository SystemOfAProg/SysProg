/*
 * Symboltable.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

using namespace std;
#include <iostream>
#include "../includes/Symboltable.h"
#include "../includes/StringTable.h"
#include "../includes/StringTabNode.h"

Symboltable::Symboltable() {
	this->stringTable = new StringTable();
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
	int seed = 131; 
   	unsigned long hash = 0;
	for(int i = 0; i < this->stringLength(s); i++) {
		hash = (hash * seed) + s[i];
	}
	return hash % this->TABLE_SIZE;
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

unsigned int Symboltable::getTableSize() {
	return this->TABLE_SIZE;
}

void Symboltable::initSymbols() {

}
