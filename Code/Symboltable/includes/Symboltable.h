#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "SymtabEntry.h"
#include "StringTable.h"

class Symboltable {
	public:
		Symboltable();
		virtual ~Symboltable();
		SymtabEntry* insert(char* lexem);
		unsigned int hash(char* s);
		unsigned int getTableSize();
		Information* lookup(SymtabEntry* key);

	private:
		static const unsigned int TABLE_SIZE = 1024;
		StringTable* stringTable;
		SymtabEntry** table;
		void initSymbols();
		int stringLength(char* lexem);
};

#endif /* SYMBOLTABLE_H_ */
