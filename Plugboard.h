#ifndef PLUGBOARD_H_
#define PLUGBOARD_H_

class Plugboard {

	char * plugBoardSettings;

public:
	Plugboard(char * plugBoardSettings);
	Plugboard();

	void wire(int &index);

};

#endif
