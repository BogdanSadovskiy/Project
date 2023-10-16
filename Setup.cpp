#include "Setup.h"

Setup:: ~Setup() {};

void Setup:: intToChar(int num, char*& c) {
	string  str = to_string(num);
	int i = 0;
	for (; str[i] != '\0'; i++) {
		c[i] = str[i];
	}
	c[i] = '\0';
}

void Setup:: stringToChar(string str, char*& c) {
	int i = 0;
	
	for (; str[i] != '\0'; i++) {
		c[i] = str[i];
	}
	c[i] = '\0';
	
}

bool Setup:: isSameChars(char* a, char* b) {
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}