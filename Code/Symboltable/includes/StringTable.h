#ifndef STRINGTABLE_H_
#define STRINGTABLE_H_

#include "../includes/StringTabNode.h"

class StringTable {
	public:
		StringTable();
		virtual ~StringTable();
		char* insert(char* lexem);
	private:
		static const unsigned int STRING_TAB_NODE_SIZE = 256;
		char* freePosition;
		unsigned int freeSpace;
		StringTabNode* firstNode;
		StringTabNode* currentNode;
		unsigned int countCharacters(char* lexem);
};

#endif /* STRINGTABLE_H_ */
