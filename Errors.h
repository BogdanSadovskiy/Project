#pragma once
using namespace std;
#include <iostream>
class Errors
{
	string error[11];
public:
	Errors();
	~Errors();
	string getTheError(int numOfError);
};

