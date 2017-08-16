/*
 * EnigmaEngine.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: Humza
 */

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include "Plugboard.h"
#include "Rotor.h"
#include "Utilities.h"
#include "EnigmaEngine.h"

using namespace std;

/**
 Constructor: Enigma reflector function

 @param index character index reference
 */
void reflect(int &index) {
	index = ((index + 13) % 26);
}

/**
 Constructor: instantiates the EnigmaEngine,
 the workhorse of the Enigma.

 @param argc command line argument count
 @param argv command line argument strings
 */
EnigmaEngine::EnigmaEngine(int argc, char **argv) {
	this->argc = argc;
	this->argv = argv;
	this->plugboard = Plugboard(*(argv + argc - 1));
	this->rotors = rotorSetup();
}

/**
 Reads command line arguments and instantiates
 rotors placing them into vector
 setting thier previous and next rotors.

 */
vector<Rotor> EnigmaEngine::rotorSetup() {
	vector < Rotor > rotors;
	if (this->argc > 2) {
		for (int i = 1; i < (this->argc) - 1; i++) {
			rotors.push_back(Rotor(*(this->argv + i), i));
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
	return rotors;
}

/**
 Resets rotors to initial setup.

 */
void EnigmaEngine::reset() {
	this->rotors = rotorSetup();
	this->plugboard = Plugboard(*(this->argv + this->argc - 1));
}

/**
 Checks a string is a valid Enigma input.

 @param str input string
 */
bool EnigmaEngine::isValidString(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (!isUppercaseCharacter(str[i])) {
			return false;
		}
	}
	return true;
}

/**
 Encrypts/Decrypts given character according to Enigma configuration.

 @param c character to be encrypted/decrypted
 @return encrypted/decrypted character

 */
char EnigmaEngine::pressEnigmaKey(char c) {
	Rotor *currentrotor;
	int charIndex = charToIndex(c);
	this->plugboard.wire(charIndex);
	for (int i = 0; i < this->rotors.size(); i++) {
		currentrotor = &(this->rotors[i]);
		currentrotor->forwardwire(charIndex);
	}
	reflect(charIndex);
	for (int i = this->rotors.size() - 1; i >= 0; i--) {
		currentrotor = &(this->rotors[i]);
		currentrotor->backwardwire(charIndex);
	}
	this->plugboard.wire(charIndex);
	return indexToCharacter(charIndex);
}

/**
 Encryps/Decrypts string according to Enigma configuration.

 @param str string to be encryped/decrypted
 @return encrypted/decrypted string

 */
string EnigmaEngine::outputString(string str) {
	string output;
	for (int i = 0; i < str.size(); i++) {
		output += this->pressEnigmaKey(str[i]);
	}
	return output;
}

/**
 Runs Enigma machine with specified configuration
 taking user input returning encrypted/decrypted
 message.

 */
void EnigmaEngine::run() {
	string input;
	string output;
	cout
			<< "Enter the message you would like to encrypt/decrypt and press Enter."
			<< endl;
	while (!cin.eof()) {
		getline(cin, input);
		if (isValidString(input)) {
			output = outputString(input);
			cout << "Your encrypted/decrypted message is:" << endl;
			cout << output << endl;
			output.clear();
			input.clear();
			this->reset();
			cout << "Enter another:" << endl;
		} else {
			this->reset();
			output.clear();
			input.clear();
			cout
					<< "Enigma machine inputs consist only of uppercase characters in the range A-Z with no spaces, enter again:"
					<< endl;

		}
	}
}

