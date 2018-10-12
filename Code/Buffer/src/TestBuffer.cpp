using namespace std;

#include "../includes/Buffer.h"
#include <iostream>

class TestBuffer {
	public:
		static void testGetNextChar();
		static void testReturnCurrentChar();
		static void printStartSequence();
		static void printEndSequence();
};

int main(int argc, char **argv) {
	TestBuffer* test = new TestBuffer();
	test->printStartSequence();
	try {
		test->testGetNextChar();
	} catch (int e) {
		cout << "[Test-Buffer]: An Error happened while executing the test for getNextChar()." << endl;
	}
	try {
		test->testReturnCurrentChar();
	} catch (int e) {
		cout << "[Test-Buffer]: An Error happened while executing the test for returnCurrentChar()." << endl;
	}
	test->printEndSequence();
}

void TestBuffer::testGetNextChar() {
	cout << "[Test-Buffer]: Execute test for Buffer::getNextChar()." << endl;
	cout << "[Test-Buffer]: Compare the lines below with 'buffer-test-file.txt'" << endl;
	Buffer*  buffer;
	buffer = new Buffer("buffer-test-file.txt", 123);
	char c;
	do {
		c = buffer->getNextChar();
		if(c == '\n') {
			cout << "[END OF LINE]";
		}
		cout << c;
	} while(c != NULL);
	cout << "[Test-Buffer]: The test was executed properly." << endl;
	buffer->~Buffer();
}

void TestBuffer::testReturnCurrentChar() {
	cout << "[Test-Buffer]: Execute test for Buffer::returnCurrentChar()." << endl;
	cout << "[Test-Buffer]: Compare the lines below with 'buffer-test-file.txt'" << endl;
	Buffer*  buffer;
	buffer = new Buffer("buffer-test-file.txt", 123);
	char c;
	char returnCharacter;
	do {
		c = buffer->getNextChar();
		if(c==NULL){
			break;
		} else {
			returnCharacter = buffer->returnCurrentChar();
			c = buffer->getNextChar();
			cout << c;
		}
	} while(true);
	cout << endl << "[Test-Buffer]: The test was executed properly." << endl;
	buffer->~Buffer();
}

void TestBuffer::printStartSequence() {
	cout << "=================================================================" << endl;
	cout << "                      Starting TestBuffer 				          " << endl;
	cout << "=================================================================" << endl << endl;
}

void TestBuffer::printEndSequence() {
	cout << endl;
	cout << "=================================================================" << endl;
	cout << "                       End of TestBuffer 				          " << endl;
	cout << "=================================================================" << endl;
}
