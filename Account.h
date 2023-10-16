#pragma once
using namespace std;
#include<iostream>


#include "Config.h"
class Account
{
private:
	bool admin;
	struct Accounts {
		char* login = new char[30];
		char* password = new char[30];
	};
	struct AccountDate {
		bool questionary;
		char* Name = new char[30];
		char* Surname = new char[30];
		char* fullAdress = new char[100];

		int numOfMathAnalisis;
		int numOfMathDescret;
		int numOfQuantumPhysics;
		int numOfMechanicPhysics;

		int numOfMathAnalisisDone;
		int numOfMathDescretDone;
		int numOfQuantumPhysicsDone;
		int numOfMechanicPhysicsDone;

		char* AnalisisMarks = new char[1000];
		char* DescretMarks = new char[1000];
		char* QuantumMarks = new char[1000];
		char* MechanicMarks = new char[1000];

	};
	int numberOfAcc;
	AccountDate* accountDate = new AccountDate[numberOfAcc];
	Accounts* accounts = new Accounts[numberOfAcc];

	Accounts attributes;
	AccountDate thisAccount;
public:
	Account(char* login);
	Account( bool access, int& numberOfAcc, char* login, char* password);
	~Account();
	void saveAccountsDate(char* login);
	void readDate(char* login);
	void userMenu(bool& escape, bool& logOut);
	void Questionary(bool& escape);
	void AdminMenu(bool& escape, bool& logOut);
	void Menu(bool& escape);

	
};

