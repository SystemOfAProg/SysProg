#ifndef STRINGTABNODE_H_
#define STRINGTABNODE_H_

class StringTabNode {
	public:
		StringTabNode();
		virtual ~StringTabNode();
		char* getVector();
		void setNext(StringTabNode* next);
		StringTabNode* getNext();
		unsigned int getSize();
		void print();
	private:
		static const unsigned int STRING_TAB_NODE_SIZE = 1024;
		char vector[STRING_TAB_NODE_SIZE];
		StringTabNode* next;
		void init();
};


#endif /* STRINGTABNODE_H_ */
