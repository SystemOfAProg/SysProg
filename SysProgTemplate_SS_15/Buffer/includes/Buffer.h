/*
 * Buffer.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef BUFFER_H_
#define BUFFER_H_

class Buffer {
	char* next;
	char* buffer1;
	char* buffer2;
	int size;
	int lastCharInBuffer;
	int lastReadIndex;
	public:
		Buffer(int);
		virtual ~Buffer();
		char getNextChar();
		char getCurrentChar();
		char returnCurrentChar();
		int fillUpBuffer(char*);
		void printDebugInfo();
		void printCurrentDirectory();

};

#endif /* BUFFER_H_ */
