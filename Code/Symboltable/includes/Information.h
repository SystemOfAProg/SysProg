#ifndef INFORMATION_H_
#define INFORMATION_H_

// #include "../../Parser/includes/Node.h"


class Information {
	public:
		Information(char* lexem, unsigned int key);
		virtual ~Information();
		char* getName();
		bool compareLexem(char* lexem);
		unsigned int getKey();

	private:
		char* name;
		unsigned int key;
};


#endif /* INFORMATION_H_ */
