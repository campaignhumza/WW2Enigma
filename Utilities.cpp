#include <fstream>
#include <string>

using namespace std;

/**
 Checks that a chracter is upper case

 @param chr character
 */
bool isUppercaseCharacter(char chr) {
	return 'A' <= chr && chr <= 'Z';
}

/**
 converts a characters into its index into the alphabet

 @param chr character
 */
int charToIndex(char chr) {
	return static_cast<int> (chr - 'A');
}

/**
 converts a characters index into the alphabet into a char

 @param index character index reference
 */
char indexToCharacter(int index) {
	return static_cast<char> (index + 'A');
}

/**
 Checks that a file exists

 @param fileName name of the file
 */
bool isFileExist(const char *fileName) {
	std::ifstream infile(fileName);
	return infile.good();
}
