/*
 * EnigmaEngine.h
 *
 *  Created on: Aug 14, 2017
 *      Author: Humza
 */

#ifndef ENIGMAENGINE_H_
#define ENIGMAENGINE_H_
#include "Plugboard.h"
#include "Rotor.h"
#include <vector>

using namespace std;

class EnigmaEngine {

private:
	Plugboard plugboard;
	vector<Rotor> rotors;
	int argc;
	char **argv;

public:
	EnigmaEngine(int argc, char **argv);
	void run();

private:
	vector<Rotor> rotorSetup();
	char pressEnigmaKey(char c);
	void reset();
	string outputString(string str);
	bool isValidString(string str);

};

#endif /* ENIGMAENGINE_H_ */
