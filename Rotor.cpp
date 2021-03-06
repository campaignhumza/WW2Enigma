#include <fstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Rotor.h"

using namespace std;

/**
 Constructor instantiates rotorArray field from
 configuration file, rotorNumber field from
 rotorNumber parameter and remaining fields
 set to default

 @param rotorSettings command line rotor config file
 @param rotorNumber rotor position in enigma
 */
Rotor::Rotor(char * rotorSettings, int rotorNumber) {
	this->rotorNumber = rotorNumber;
	this->nextRotor = 0;
	this->previousRotor = 0;
	this->rotations = 0;
	ifstream file;
	file.open(rotorSettings);
	for (int i = 0; i < 26; ++i) {
		file >> rotorArray[i];
	}
	file.close();
}

/**
 Returns rotor rotations field
 */
int Rotor::getRotations() {
	return rotations;
}

/**
 Sets rotors nextRotor field

 @param rotor this rotors next rotor
 */
void Rotor::setNextRotor(Rotor *rotor) {
	this->nextRotor = rotor;
}

/**
 Sets rotors previousRotor field

 @param rotor this rotors previous rotor
 */
void Rotor::setPreviousRotor(Rotor *rotor) {
	this->previousRotor = rotor;
}

/**
 Rotates rotor by one position
 */
void Rotor::rotate() {
	if (rotations % 26 == 25 && rotations >= 25 && nextRotor != 0) {
		nextRotor->rotate();
		rotations++;
	} else {
		rotations++;
	}
}

/**
 Updates character index reference param as
 a forward movement in rotor

 @param index character index reference
 */
void Rotor::forwardwire(int &index) {
	int previousRotations;
	if (previousRotor != 0) {
		previousRotations = previousRotor->getRotations();
		int newindex = (index + rotations - previousRotations) % 26;
		if (newindex < 0) {
			newindex = 26 + newindex;
		}
		index = rotorArray[newindex % 26];
	} else {
		index = rotorArray[(index + rotations) % 26];
	}
}

/**
 Updates character index reference param as
 a backward movement in rotor

 @param index character index reference
 */
void Rotor::backwardwire(int &index) {
	int locationInRotorArray = (std::distance(rotorArray,
			std::find(rotorArray, rotorArray + 26, index)));
	int newindex;
	int previousRotations = 0;
	if (previousRotor != 0) {
		previousRotations = previousRotor->getRotations();
		newindex = ((locationInRotorArray) - rotations + previousRotations)
				% 26;
	} else {
		newindex = ((locationInRotorArray) - rotations) % 26;
	}
	if (newindex < 0) {
		newindex = 26 + newindex;
	}
	index = newindex;
	if (rotorNumber == 1) {
		rotate();
	}
}
