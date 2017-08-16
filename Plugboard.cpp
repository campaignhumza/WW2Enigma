#include <fstream>
#include <iostream>
#include <stdexcept>
#include "Plugboard.h"

using namespace std;

/**
 Constructor: instantiates plugBoardSetting field from
 plugboard config file

 @param plugBoardSettings plugboard config file
 */
Plugboard::Plugboard(char * plugBoardSettings) {
	this->plugBoardSettings = plugBoardSettings;
}

/**
 Constructor: default empty constructor
 */
Plugboard::Plugboard() {
}

/**
 Reads plugboard file field and translates index reference
 parameter according to appropriate plugboard wiring.

 @param index character index reference
 */
void Plugboard::wire(int &index) {
	ifstream file;
	file.open(plugBoardSettings);
	int letterPairOne;
	int letterPairTwo;
	bool translated = false;
	while (file >> letterPairOne >> letterPairTwo && !translated) {
		if (index == letterPairOne) {
			index = letterPairTwo;
			translated = true;
		} else if (index == letterPairTwo) {
			index = letterPairOne;
			translated = true;
		}
	}
	file.close();
}
