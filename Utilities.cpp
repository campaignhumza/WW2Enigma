#include <fstream>

bool isUppercaseCharacter(char chr) {
	return 'A' <= chr
			&& chr <= 'Z';
}

int charToIndex(char chr) {
	return static_cast<int>(chr - 'A');
}

char indexToCharacter(int index) {
	return static_cast<char>(index + 'A');
}

bool isFileExist(const char *fileName) {
	std::ifstream infile(fileName);
	return infile.good();
}
