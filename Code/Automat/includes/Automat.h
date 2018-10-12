/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */

#ifndef Automat_H_
#define Automat_H_
using namespace std;
#include <string>
#include <stdbool.h>
#include <iostream>
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */

class Automat {
public:
	Automat();
	virtual ~Automat();
	int nextState(char input, int state);
	char getChar();
	string getToken();
	string zustandString(int zustand);
	enum state {
		INITIAL_STATE = 1,
		IDENTIFIER,
		INTEGER,
		SIGN_ALL,
		SIGN_COLON,
		SIGN_COLON_EQUALS,
		SIGN_EQUALS,
		SIGN_EQUALS_COLON_EQUALS,
		SIGN_AND,
		SIGN_COMMENT_BEGIN,
		SIGN_COMMENT_CONTENT,
		SIGN_COMMENT_END,
		SIGN_EQUALS_COLON,
		SIGN_AND_AND,
		UNKOWN_TOKEN,
		EPSILON_TOKEN
	};
	enum input {
		LETTER = 1, DIGIT, SIGN_ALL2, COLON, EQUALS, AND, STAR, UNKOWN, EPSILON
	};
private:
	string token = "";
	string tokenStringErstellen = "";
};

#endif /* Automat_H_ */
