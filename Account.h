#pragma once
using namespace std;
#include<iostream>

#include "TestForStudent.h"
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

		int* AnalisisMarks = new int[20];
		int* DescretMarks = new int[20];
		int* QuantumMarks = new int[20];
		int* MechanicMarks = new int[20];

	};
	int numberOfAcc;
	Accounts* accounts = new Accounts[numberOfAcc];

	Accounts attributes;
	AccountDate thisAccount;
public:
	Account( char* login);
	Account( bool access, int& numberOfAcc, char* login, char* password);
	void getEveryLogDate();
	void writeEveryLogDate();
	void accTest(bool& escape, bool& logOut);
	void saveAccountLog( char* login);
	void readDate(char* login);
	void userMenu(bool& escape, bool& logOut);
	void Questionary(bool& escape, bool& logOut);
	void AdminMenu(bool& escape, bool& logOut);
	void accMenu(bool& escape);

	
};

