#pragma once
#include "Config.h"
class Setup
{
public:
	~Setup();
	void stringToChar(string str, char*& c);
	void intToChar(int num, char*& c);
	bool isSameChars(char* a, char* b);
};

