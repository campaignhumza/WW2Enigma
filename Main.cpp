#include <stdexcept>
#include <iostream>
#include "Utilities.h"
#include "EnigmaEngine.h"

using namespace std;

int main(int argc, char **argv) {

	//initial command line arguments check.
	if (argc == 1) {
		cout
				<< "invalid configuration files, check readme files for configuration settings";
		return -1;
	}
	if (!isFileExist(*(argv + argc - 1))) {
		cout
				<< "invalid configuration files, check readme files for configuration settings";
		return -1;
	}

	EnigmaEngine engine = EnigmaEngine(argc, argv);
	engine.run();
	return 0;
}
