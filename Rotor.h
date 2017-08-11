#ifndef ROTOR_H_
#define ROTOR_H_

class Rotor {

private:
	int rotorNumber;
	Rotor * nextRotor;
	Rotor * previousRotor;
	int rotations;
	int rotorArray[26];

public:
	Rotor(char * rotorSettings, int rotorNumber);

	void forwardwire(int &index);
	void backwardwire(int &index);
	void setNextRotor(Rotor * rotor);
	void setPreviousRotor(Rotor * rotor);
	int getRotations();
private:
	void rotate();

};

#endif
