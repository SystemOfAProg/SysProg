using namespace std;
#include <iostream>
#include "../includes/StringTable.h";

StringTable::StringTable() {
    this->freeSpace = STRING_TAB_NODE_SIZE;
    this->freePosition = (char*) malloc(STRING_TAB_NODE_SIZE);
    this->firstNode = (StringTabNode*) freePosition;
    // TODO: implement
}

StringTable::~StringTable() {
    // Delete here everything in case heap memory is allocated with keyword "new"
}

// If stringtable runs out of space -> double the existing space
char* StringTable::insert(char* lexem) {
    int lexemCharacterCount = (int)this->countCharacters(lexem);
    char* temporary = this->freePosition;
    // If there is not enough space for 
    if (lexemCharacterCount >= this->freeSpace) {
        StringTabNode* newNode = (StringTabNode*) malloc(STRING_TAB_NODE_SIZE);
        this->freePosition = (char*) newNode;
    }
    // copy lexem to free space
    memcpy(this->freePosition, lexem, lexemCharacterCount+1);
    // NULL Terminated Strings
    this->freePosition[lexemCharacterCount] = '\0';
    this->freePosition += lexemCharacterCount+1;
    this->freeSpace -= lexemCharacterCount+1;
    return temporary;
}

unsigned int StringTable::countCharacters(char* lexem) {
    unsigned int size = 0;
    char* position = lexem;
    while(position != NULL || *position != '\n' || *position != '\r' || *position != ' ' || *position != '\0') {
        size++;
    }
    return size;
}

// Code for realloc version, when StringTable runs out of space
// STRING_TAB_NODE_SIZE *= 2;
//         char* reallocatedPosition = (char*) realloc(this->firstNode, STRING_TAB_NODE_SIZE);
//         // Check, if reallocation is at new space and copy data to new location, if neccessary
//         if(reallocatedPosition != (char*)this->firstNode) {
//             memcpy(reallocatedPosition, this->firstNode, this->freePosition-(char*)this->firstNode + 1);
//             this->firstNode = (StringTabNode*)reallocatedPosition;
//             this->
//        }