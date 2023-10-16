#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include "Errors.h"
#include "Setup.h"
#include "Account.h"

using namespace std;
class Config
{
private:
	int numberOfAcc;
	
public:
	Config();
	int getNumberOfAcc();
	void pushNumberOfAcc();
	char* hashing(char* password);
	void exit();
	void enterMenu();
	bool isPassSave(char* pass);
	void logIn(bool& escape);
	void sighUp(bool& escape);
	bool isEmailTrue(char* Email);
	bool isLogAndPassTrue(bool& access, char* login, char* password);
	void createAccount(char* login, char* password);
};

