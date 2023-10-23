#pragma once
#include"Config.h"
class Menu
{
public:
	void mainMenu(string& tmp);
	void LoginingLog(string& tmp);
	void LoginingPass(string& tmp, char* login);
	void SighUpLog(string& tmp);
	void SighUpPass(string& tmp,  char* login);
	void accMenustart(string& tmp, char* name);
	void QuestionaryAccount(char*& name, char*& surname, char*& address);
	void QuestionaryAccountSecond(char* name, char* surname, char* address, string& tmp);
	void TestAccountMenu(string& tmp);
};

