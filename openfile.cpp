#include <iostream>
#include <fstream>
#include <cstring>
#include "changecase.h"

void help() {
	std::cout << "\nUse\n\tchangecase source destination_file" << std::endl;
	std::cout << "\t-L - to lover case" << std::endl;
	std::cout << "\t-U - to upper case" << std::endl;
	std::cout << "\t-G - to toggle case" << std::endl;
	std::cout << "\t-T - to title case\n" << std::endl;
}


int main(int argc, char* argv[]) {

	if (argc != 4) {
		help();
		return 0;
	}

	const char* inputfilename = argv[2];
	const char* outputfilename = argv[3];

	std::ifstream inFile;
	inFile.open(inputfilename, std::ios_base::binary);

	if (!inFile) {
		std::cout << "Can not open file " << inputfilename << std::endl;
		return 1;
	}

	std::ofstream outFile;
	outFile.open(outputfilename, std::ios_base::binary);

	if (!outFile) {
		std::cout << "Can not open file " << outputfilename << std::endl;
		inFile.close();
		return 2;
	}

	int ch;

	if (strcmp(argv[1], "-L") == 0) {
		to_lower_case(inFile, outFile);
	}
	else if (strcmp(argv[1], "-U") == 0) {
		to_upper_case(inFile, outFile);
	}
	else if (strcmp(argv[1], "-G") == 0) {
		toggle_case(inFile, outFile);
	}
	else if (strcmp(argv[1], "-T") == 0) {
		to_title_case(inFile, outFile);
	}
	else {
		help();
	}

	inFile.close();
	outFile.close();

	return 0;
}
