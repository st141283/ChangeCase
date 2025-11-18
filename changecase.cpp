#include "changecase.h"

void toggle_case(std::ifstream & inFile, std::ofstream & outFile) {
	int ch;
	while ((ch = inFile.get()) != EOF) {
		if (ch >= 'a' && ch <= 'z') {
			ch = (ch - 'a') + 'A';
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = (ch - 'A') + 'a';
		}
		outFile.put(ch);
	}
}

void to_lower_case(std::ifstream & inFile, std::ofstream & outFile) {
	int ch;
	while ((ch = inFile.get()) != EOF) {
		if (ch >= 'A' && ch <= 'Z') {
			ch = (ch - 'A') + 'a';
		}
		outFile.put(ch);
	}
}

void to_upper_case(std::ifstream & inFile, std::ofstream & outFile) {
	int ch;
	while ((ch = inFile.get()) != EOF) {
		if (ch >= 'a' && ch <= 'z') {
			ch = (ch - 'a') + 'A';
		}
		outFile.put(ch);
	}
}

void to_title_case(std::ifstream & inFile, std::ofstream & outFile) {
	int ch;
	bool flag = true;
	while ((ch = inFile.get()) != EOF) {
		if (flag) {
			if (ch >= 'a' && ch <= 'z') {
				ch = (ch - 'a') + 'A';
			}
			flag = false;
		}
		else {
			if (ch >= 'A' && ch <= 'Z') {
				ch = (ch - 'A') + 'a';
			}
		}
		if (ch == '\t' || ch == '\r' || ch == '\n' || ch == ' ') {
			flag = true;
		}
		outFile.put(ch);
	}
}
