#ifndef INFORMATION_H_
#define INFORMATION_H_

// #include "../../Parser/includes/Node.h"


class Information {
	public:
		Information(char* lexem, unsigned int key);
		virtual ~Information();
		char* getName();
		bool compareLex(char* lexem);
		unsigned int getKey();
		int stringCompare(const char *s1, const char *s2);

	private:
		char* name;
		unsigned int key;
};


#endif /* INFORMATION_H_ */
