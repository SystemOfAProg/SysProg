/*
 * Automat.cpp
 *
 */

#include "../includes/Automat.h"

Automat::Automat() {
}

Automat::~Automat() {
}

int Automat::nextState(char eingabeZeichen, int aktuellerZustand) {
	int eingabeInt = 0;
	int naechsterZustand = 0;
	bool keinTokenErstellen = false;
	bool leerzeichenAkzeptieren = true;
	bool eingabeIstLeerzeichen = false;
	switch (eingabeZeichen) {
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
		eingabeInt = LETTER;
		break;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		eingabeInt = DIGIT;
		break;
	case '+':
	case '-':
	case '<':
	case '>':
	case '!':
	case ';':
	case '(':
	case ')':
	case '{':
	case '}':
	case '[':
	case ']':
		eingabeInt = SIGN_ALL2;
		break;
	case ':':
		eingabeInt = COLON;
		break;
	case '=':
		eingabeInt = EQUALS;
		break;
	case '&':
		eingabeInt = AND;
		break;
	case '*':
		eingabeInt = STAR;
		break;
	case ' ':
	case '\t':
	case '\n':
	case '\r':
		eingabeInt = EPSILON;
		break;
	default:
		eingabeInt = UNKOWN;
		break;
	}
	switch (eingabeInt) {
	case LETTER: //input
		switch (aktuellerZustand) {
		case INITIAL_STATE: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		case IDENTIFIER: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			keinTokenErstellen = true;
			break;
		case INTEGER: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		case SIGN_ALL: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		case SIGN_COLON: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		case SIGN_COLON_EQUALS: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		case SIGN_EQUALS: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		case SIGN_EQUALS_COLON_EQUALS: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		case SIGN_AND: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		case SIGN_COMMENT_BEGIN: //current_state; input = LETTER
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_CONTENT: //current_state; input = LETTER
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_END: //current_state; input = LETTER
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_EQUALS_COLON: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		case SIGN_AND_AND: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		case UNKOWN_TOKEN: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		case EPSILON_TOKEN: //current_state; input = LETTER
			naechsterZustand = IDENTIFIER;
			break;
		}
		break;
	case DIGIT: //input
		switch (aktuellerZustand) {
		case INITIAL_STATE: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			break;
		case IDENTIFIER: //current_state; input = DIGIT
			naechsterZustand = IDENTIFIER;
			keinTokenErstellen = true;
			break;
		case INTEGER: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			keinTokenErstellen = true;
			break;
		case SIGN_ALL: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			break;
		case SIGN_COLON: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			break;
		case SIGN_COLON_EQUALS: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			break;
		case SIGN_EQUALS: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			break;
		case SIGN_EQUALS_COLON_EQUALS: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			break;
		case SIGN_AND: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			break;
		case SIGN_COMMENT_BEGIN: //current_state; input = DIGIT
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_CONTENT: //current_state; input = DIGIT
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_END: //current_state; input = DIGIT
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_EQUALS_COLON: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			break;
		case SIGN_AND_AND: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			break;
		case UNKOWN_TOKEN: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			break;
		case EPSILON_TOKEN: //current_state; input = DIGIT
			naechsterZustand = INTEGER;
			break;
		}
		break;
	case SIGN_ALL2: //input
		switch (aktuellerZustand) {
		case INITIAL_STATE: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		case IDENTIFIER: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		case INTEGER: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_ALL: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_COLON: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_COLON_EQUALS: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_EQUALS: //current_state
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_EQUALS_COLON_EQUALS: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_AND: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_COMMENT_BEGIN: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_CONTENT: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_END: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_EQUALS_COLON: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_AND_AND: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		case UNKOWN_TOKEN: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		case EPSILON_TOKEN: //current_state; input = SIGN_ALL2
			naechsterZustand = SIGN_ALL;
			break;
		}
		break;
	case COLON: //input
		switch (aktuellerZustand) {
		case INITIAL_STATE: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		case IDENTIFIER: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		case INTEGER: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		case SIGN_ALL: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		case SIGN_COLON: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		case SIGN_COLON_EQUALS: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		case SIGN_EQUALS: //current_state; input = COLON
			naechsterZustand = SIGN_EQUALS_COLON;
			keinTokenErstellen = true;
			break;
		case SIGN_EQUALS_COLON_EQUALS: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		case SIGN_AND: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		case SIGN_COMMENT_BEGIN: //current_state; input = COLON
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_CONTENT: //current_state; input = COLON
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_END: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			keinTokenErstellen = true;
			break;
		case SIGN_EQUALS_COLON: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		case SIGN_AND_AND: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		case UNKOWN_TOKEN: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		case EPSILON_TOKEN: //current_state; input = COLON
			naechsterZustand = SIGN_COLON;
			break;
		}
		break;
	case EQUALS: //input
		switch (aktuellerZustand) {
		case INITIAL_STATE: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS;
			break;
		case IDENTIFIER: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS;
			break;
		case INTEGER: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS;
			break;
		case SIGN_ALL: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS;
			break;
		case SIGN_COLON: //current_state; input = EQUALS
			naechsterZustand = SIGN_COLON_EQUALS;
			keinTokenErstellen = true;
			break;
		case SIGN_COLON_EQUALS: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS;
			break;
		case SIGN_EQUALS: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS;
			break;
		case SIGN_EQUALS_COLON_EQUALS: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS;
			break;
		case SIGN_AND: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS;
			break;
		case SIGN_COMMENT_BEGIN: //current_state; input = EQUALS
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_CONTENT: //current_state; input = EQUALS
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_END: //current_state; input = EQUALS
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_EQUALS_COLON: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS_COLON_EQUALS;
			keinTokenErstellen = true;
			break;
		case SIGN_AND_AND: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS;
			break;
		case UNKOWN_TOKEN: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS;
			break;
		case EPSILON_TOKEN: //current_state; input = EQUALS
			naechsterZustand = SIGN_EQUALS;
			break;
		}
		break;
	case AND: //input
		switch (aktuellerZustand) {
		case INITIAL_STATE: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		case IDENTIFIER: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		case INTEGER: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		case SIGN_ALL: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		case SIGN_COLON: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		case SIGN_COLON_EQUALS: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		case SIGN_EQUALS: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		case SIGN_EQUALS_COLON_EQUALS: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		case SIGN_AND: //current_state; input = AND
			naechsterZustand = SIGN_AND_AND;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_BEGIN: //current_state; input = AND
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_CONTENT: //current_state; input = AND
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_END: //current_state; input = AND
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_EQUALS_COLON: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		case SIGN_AND_AND: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		case UNKOWN_TOKEN: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		case EPSILON_TOKEN: //current_state; input = AND
			naechsterZustand = SIGN_AND;
			break;
		}
		break;
	case STAR: //input
		switch (aktuellerZustand) {
		case INITIAL_STATE: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		case IDENTIFIER: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		case INTEGER: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_ALL: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_COLON: //current_state; input = STAR
			naechsterZustand = SIGN_COMMENT_BEGIN;
			keinTokenErstellen = true;
			break;
		case SIGN_COLON_EQUALS: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_EQUALS: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_EQUALS_COLON_EQUALS: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_AND: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_COMMENT_BEGIN: //current_state; input = STAR
			naechsterZustand = SIGN_COMMENT_END;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_CONTENT: //current_state; input = STAR
			naechsterZustand = SIGN_COMMENT_END;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_END: //current_state; input = STAR
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_EQUALS_COLON: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_AND_AND: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		case UNKOWN_TOKEN: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		case EPSILON_TOKEN: //current_state; input = STAR
			naechsterZustand = SIGN_ALL;
			break;
		}
		break;
	case UNKOWN: //input
		//		cout << "test";
		switch (aktuellerZustand) {
		case INITIAL_STATE: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case IDENTIFIER: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case INTEGER: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case SIGN_ALL: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case SIGN_COLON: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case SIGN_COLON_EQUALS: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case SIGN_EQUALS: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case SIGN_EQUALS_COLON_EQUALS: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case SIGN_AND: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case SIGN_COMMENT_BEGIN: //current_state; input = UNKOWN
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_CONTENT: //current_state; input = UNKOWN
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_COMMENT_END: //current_state; input = UNKOWN
			naechsterZustand = SIGN_COMMENT_CONTENT;
			keinTokenErstellen = true;
			break;
		case SIGN_EQUALS_COLON: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case SIGN_AND_AND: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case UNKOWN_TOKEN: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case EPSILON_TOKEN: //current_state; input = UNKOWN
			naechsterZustand = UNKOWN_TOKEN;
			break;
		}
		break;
	case EPSILON: //input
//		cout << aktuellerZustand << " " << eingabeInt;
		switch (aktuellerZustand) {
		case INITIAL_STATE: //current_state; input = EPSILON
			keinTokenErstellen = true;
			leerzeichenAkzeptieren = false;
			naechsterZustand = INITIAL_STATE;
			break;
		case IDENTIFIER: //current_state; input = EPSILON
			naechsterZustand = EPSILON_TOKEN;
			leerzeichenAkzeptieren = false;
			break;
		case INTEGER: //current_state; input = EPSILON
			leerzeichenAkzeptieren = false;
			naechsterZustand = INTEGER;
			break;
		case SIGN_ALL: //current_state; input = EPSILON
			leerzeichenAkzeptieren = false;
			naechsterZustand = SIGN_ALL;
			break;
		case SIGN_COLON: //current_state; input = EPSILON
			leerzeichenAkzeptieren = false;
			naechsterZustand = SIGN_COLON;
			break;
		case SIGN_COLON_EQUALS: //current_state; input = EPSILON
			leerzeichenAkzeptieren = false;
			naechsterZustand = SIGN_COLON_EQUALS;
			break;
		case SIGN_EQUALS: //current_state; input = EPSILON
			leerzeichenAkzeptieren = false;
			naechsterZustand = INITIAL_STATE;
			break;
		case SIGN_EQUALS_COLON_EQUALS: //current_state; input = EPSILON
			leerzeichenAkzeptieren = false;
			keinTokenErstellen = false;
			naechsterZustand = SIGN_EQUALS_COLON_EQUALS;
			break;
		case SIGN_AND: //current_state; input = EPSILON
			leerzeichenAkzeptieren = false;
			naechsterZustand = SIGN_AND;
			break;
		case SIGN_COMMENT_BEGIN: //current_state; input = EPSILON
			leerzeichenAkzeptieren = true;
			keinTokenErstellen = true;
			naechsterZustand = SIGN_COMMENT_BEGIN;
			break;
		case SIGN_COMMENT_CONTENT: //current_state; input = EPSILON
			leerzeichenAkzeptieren = true;
			keinTokenErstellen = true;
			naechsterZustand = SIGN_COMMENT_CONTENT;
			break;
		case SIGN_COMMENT_END: //current_state; input = EPSILON
			leerzeichenAkzeptieren = true;
			keinTokenErstellen = true;
			naechsterZustand = SIGN_COMMENT_END;
			break;
		case SIGN_EQUALS_COLON: //current_state; input = EPSILON
			leerzeichenAkzeptieren = false;
			naechsterZustand = INITIAL_STATE;
			break;
		case SIGN_AND_AND: //current_state; input = EPSILON
			leerzeichenAkzeptieren = false;
			naechsterZustand = SIGN_AND_AND;
			break;
		case UNKOWN_TOKEN: //current_state; input = EPSILON
			leerzeichenAkzeptieren = false;
			naechsterZustand = UNKOWN_TOKEN;
			break;
		case EPSILON_TOKEN: //current_state; input = EPSILON
			leerzeichenAkzeptieren = false;
			naechsterZustand = EPSILON_TOKEN;
			break;
		}
		eingabeIstLeerzeichen = true;
		break;
	default:
		exit(1);
	} //Ende Switch

	if (!keinTokenErstellen) {
		//Token erstellen
		if (leerzeichenAkzeptieren) {
			tokenStringErstellen = token; //Token erstellen
			token = eingabeZeichen; //neues Token Festlegen

		} else if (eingabeIstLeerzeichen) {
			tokenStringErstellen = token; //Token erstellen
			token = ""; //neues Token Festlegen

		} else {
			tokenStringErstellen = "";
		}
	} else {
		// Kein Token erstellen
		if (leerzeichenAkzeptieren) {
			//Eingabe ist (noch) Kommentar
			token += eingabeZeichen;
			tokenStringErstellen = "";

		}
	}
	return naechsterZustand;
}
string Automat::getToken() {
	return tokenStringErstellen;
}
string Automat::zustandString(int zustand) {
	switch (zustand) {
	case 1:
		return "INITIAL_STATE           ";
	case 2:
		if (tokenStringErstellen == "while"
				|| tokenStringErstellen == "WHILE") {
			return "WHILE                   ";
		} else if (tokenStringErstellen == "if"
				|| tokenStringErstellen == "IF") {
			return "IF                      ";
		} else {
			return "IDENTIFIER              ";
		}
	case 3:
		return "INTEGER                 ";
	case 4:
		if (tokenStringErstellen == "+") {
			return "PLUS                    ";
		} else if (tokenStringErstellen == "-") {
			return "MINUS                   ";
		} else if (tokenStringErstellen == "<") {
			return "SMALLER                 ";
		} else if (tokenStringErstellen == ">") {
			return "GREATER                 ";
		} else if (tokenStringErstellen == "!") {
			return "BANG                    ";
		} else if (tokenStringErstellen == ";") {
			return "SEMICOLON               ";
		} else if (tokenStringErstellen == "(") {
			return "OPEN_BRACKET            ";
		} else if (tokenStringErstellen == ")") {
			return "CLOSE_BRACKET           ";
		} else if (tokenStringErstellen == "{") {
			return "BRACELEFT               ";
		} else if (tokenStringErstellen == "}") {
			return "BRACERIGHT              ";
		} else if (tokenStringErstellen == "[") {
			return "SQUARED_BRACKET_OPEN    ";
		} else if (tokenStringErstellen == "]") {
			return "SQUARED_BRACKET_CLOSE   ";
		} else {
			return "fehler9";
		}
	case 5:
		return "SIGN_COLON              ";
	case 6:
		return "SIGN_COLON_EQUALS       ";
	case 7:
		return "SIGN_EQUALS             ";
	case 8:
		return "SIGN_EQUALS_COLON_EQUALS";
	case 9:
		return "SIGN_AND                ";
	case 10:
		return "SIGN_COMMENT_BEGIN      ";
	case 11:
		return "SIGN_COMMENT_CONTENT    ";
	case 12:
		return "SIGN_COMMENT_END        ";
	case 13:
		return "SIGN_EQUALS_COLON       ";
	case 14:
		return "SIGN_AND_AND            ";
	case 15:
		return "UNKNOWN_TOKEN           ";
	case 16:
		return "EPSILON_TOKEN           ";
	default:
		return 0;
	}
}
