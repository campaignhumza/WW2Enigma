# WW2Enigma
command line WW2 Enigma encryption machine written in C++

1) compile in the terminal using the make all command

2) run program in terminal with example rotors and plugboards, 
   e.g >enigma ./rotors/I.rot ./rotors/II.rot ./rotors/III.rot ./plugboards/I.pb
   
You can write your own rotor or plugboard configurations using the following spec:

ROTOR:
The rotor configuration files will contain 26 numbers, separated by white space. The first number will
give the (0-based) index into the alphabet that the first letter, 'A', maps to. The second number will
give the index for the second letter, 'B', and so on. For example, the sample file I.rot contains:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 0
This shifts the alphabet up one when mapped forwards (e.g. f(0) = 1, so 'A' becomes 'B'), and
maps the alphabet down one when mapped backwards (f(0) = 25, so 'A' becomes 'Z').

PLUGBOARD:
The plugboard configuration files will contain an even number of numbers (possibly zero), separated
by white space. The numbers are to be read off in pairs, where each pair specifies a connection made
between two contacts on the plugboard. The numbers are, as with the rotors, the (0-based) index into
the alphabet.
For example, the sample file plugboards/III.pb contains:
23 8 20 22 18 16 24 2 9 12
which corresponds to the plugboard where : 'X' is connected to 'I', 'U' is connected to 'W', 'S' is
connected to 'Q', 'Y' is connected to 'C' and 'J' is connected to 'M'. All other letters are mapped to
themselves.

REFLECTOR:
the relfector is currently inconfigurable.
