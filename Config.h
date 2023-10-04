#pragma once
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include "Errors.h"
using namespace std;
class Config
{
private:
	struct Access {
		bool log;
		bool password;
		bool permission;
	};
	Access access;
	
public:
	Config();
	void exit();
	void enterMenu();
	bool isPassSave(string pass);
	bool isEnteringCorrect(string log, string password);
	void logIn(bool& escape);
	void sighUp(bool& escape);
	bool isEmailTrue(string Email);
	void createAccount(string login, string password);
};

