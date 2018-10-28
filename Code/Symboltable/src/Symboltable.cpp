/*
 * Symboltable.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */


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
	char* positionInStringTable = this->stringTable->insert(lexem);
	Information* information = new Information(positionInStringTable, hash);
	SymtabEntry* entry = new SymtabEntry(information);
	this->addEntryToTable(entry);
	return entry;
}

void Symboltable::addEntryToTable(SymtabEntry* entry) {
	// Check, if SymtabEntry already exisits for this hashvalue
	SymtabEntry* potentialEntry = this->table[entry->getInfo()->getKey()];
	if(potentialEntry == NULL) {
		this->table[entry->getInfo()->getKey()] = entry;
	} else {
		SymtabEntry* lastNode = potentialEntry;
		while (lastNode->getNext() != NULL) {
			lastNode = lastNode->getNext();
		}
		lastNode->setNext(entry);
	}
	return;
}

SymtabEntry* Symboltable::lookup(char* lexem) {
	unsigned int hash = this->hash(lexem);
	SymtabEntry* currentNode = this->table[hash];
	while (currentNode!= NULL) {
		if (currentNode->getInfo()->equals(lexem)) {
			return currentNode;
		}
		currentNode = currentNode->getNext();
	}
	return NULL;
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
