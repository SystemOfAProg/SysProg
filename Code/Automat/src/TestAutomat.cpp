#include "../includes/Automat.h"

int main(int argc, char* argv[]) {
	Automat* automat = new Automat();

	string eingabe = "%X :=3+4;\n"
			":*eine einfache *Aufgabe !! *:\n"
			"?y := 7 = := X% : (X - 4);; ; if(true)5 5\n"
			"Z := ((3 + %4 - 6);$while(true)\n"
			"Resultat := : X y waer";
	int zustand = 1;
	int zustandNeu = 0;
	cout << eingabe << endl << endl;
	for (unsigned int i = 0; i < eingabe.length() + 1; i++) {
		char eingabeCharacter = eingabe[i];
		zustandNeu = automat->nextState(eingabeCharacter, zustand);

		if (automat->getToken() != "") {
			cout << automat->zustandString(zustand) << " Lexem: |" << automat->getToken()
					<< "|" << endl;
		} else {
//			cout << "  " << zustandString(zustand) << " Lexem: |"
//					<< automat->getToken() << "| " << zustandNeu << endl;
		}
//		cout << "\t\t\tFolgezustand: " << zustandNeu << " " << zustandString(zustandNeu) << endl;
		zustand = zustandNeu;
	}
	return 0;
}
