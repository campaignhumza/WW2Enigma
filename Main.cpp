#include <stdexcept>
#include <iostream>
#include <vector>
#include "Plugboard.h"
#include "Rotor.h"
#include "Utilities.h"

using namespace std;

void reflect(int &index) {
	index = ((index + 13) % 26);
}

int main(int argc, char **argv) {

	//checks command line arguments are valid.
	if (argc == 1) {
		cout << "invalid configuration files";
		return -1;
	}
	if (!isFileExist(*(argv + argc - 1))) {
		cout << "invalid configuration files";
		return -1;
	}

	/*
	 * Reads command line arguments and instantiates
	 * plugboard and rotors placing rotors into vector
	 * setting their previous and next rotors manually.
	 */
	Plugboard plugboard = Plugboard(*(argv + argc - 1));
	vector<Rotor> rotors;
	if (argc > 2) {
		for (int i = 1; i < argc - 1; i++) {
			rotors.push_back(Rotor(*(argv + i), i));
		}
		//previous and next rotors manual set.
		Rotor *nextRotor;
		Rotor *currentRotor;
		for (int i = 0; i < rotors.size() - 1; i++) {
			currentRotor = &rotors[i];
			nextRotor = &rotors[i + 1];
			currentRotor->setNextRotor(nextRotor);
			nextRotor->setPreviousRotor(currentRotor);
		}
	}

	/*
	 * Reads user inputs and passes through plugboard,
	 * rotors and reflector outputting result.
	 */
	char nextInput;
	int charIndex;
	Rotor *currentrotor;
	while (!cin.eof() && cin >> nextInput) {
		cin >>ws;
		try {
			if (isUppercaseCharacter(nextInput)) {
				charIndex = charToIndex(nextInput);
				plugboard.wire(charIndex);
				for (int i = 0; i < rotors.size(); i++) {
					currentrotor = &rotors[i];
					currentrotor->forwardwire(charIndex);
				}
				reflect(charIndex);
				for (int i = rotors.size() - 1; i >= 0;
						i--) {
					currentrotor = &rotors[i];
					currentrotor->backwardwire(charIndex);
				}
				plugboard.wire(charIndex);
				cout<<indexToCharacter(charIndex);
			} else {
				throw invalid_argument(" Invalid input, "
						"inputs must consist of upper "
						"case characters A-Z only. ");
			}
		} catch (const std::exception& ex) {
			cout << ex.what();
			return -1;
		}
	}
	return 0;
}
