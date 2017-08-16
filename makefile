all: enigma

enigma: Main.o Rotor.o Plugboard.o Utilities.o EnigmaEngine.o
	g++ -o enigma Main.o Rotor.o Plugboard.o Utilities.o EnigmaEngine.o

Main.o: Main.cpp Utilities.h EnigmaEngine.h
	g++ -c Main.cpp
	
EnigmaEngine.o: EnigmaEngine.cpp EnigmaEngine.h Rotor.h Plugboard.h Utilities.h
	g++ -c EnigmaEngine.cpp	

Rotor.o: Rotor.cpp Rotor.h
	g++ -c Rotor.cpp

Plugboard.o: Plugboard.cpp Plugboard.h
	g++ -c Plugboard.cpp

Utilities.o: Utilities.cpp Utilities.h
	g++ -c Utilities.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean