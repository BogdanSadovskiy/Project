#include "Account.h"

void Account:: saveAccountsDate(char * login) {				//saving date of account
	ofstream date;
	date.open(login, ios::binary);
	if (!date.is_open()) {
		cout << Errors().getTheError(3);
		Errors().~Errors();
	}
	date.write((char*)&this->thisAccount, sizeof(AccountDate));
	date.close();
}

Account::Account(char* login) {
	this->thisAccount.questionary = false;

	this->thisAccount.numOfMathAnalisis = 0;
	this->thisAccount.numOfMathDescret = 0;
	this->thisAccount.numOfMechanicPhysics = 0;
	this->thisAccount.numOfQuantumPhysics = 0;

	this->thisAccount.numOfMathAnalisisDone = 0;
	this->thisAccount.numOfMathDescretDone = 0;
	this->thisAccount.numOfMechanicPhysicsDone = 0;
	this->thisAccount.numOfQuantumPhysicsDone = 0;

	this->thisAccount.Name[0] = '\0';
	this->thisAccount.Surname[0] = '\0';
	this->thisAccount.fullAdress[0] = '\0';

	this->thisAccount.AnalisisMarks[0] = '\0';
	this->thisAccount.DescretMarks[0] = '\0';
	this->thisAccount.MechanicMarks[0] = '\0';
	this->thisAccount.QuantumMarks[0] = '\0';

	saveAccountsDate(login);
}

Account::Account( bool access, int& numberOfAcc, char* login, char* password) {
	if (access) {
		this->admin = true;
	}
	else {
		this->admin = false;
		readDate(login);
	}
	this->attributes.login = login;
	this->attributes.password = password;
	this->numberOfAcc = numberOfAcc;
	
}

Account::~Account() {
	delete[] this->accountDate;
	delete[] this->accounts;
}
void Account::readDate(char* login) {		//reading for cuurrent date of account
	ifstream date;
	date.open(login, ios::binary);
	if (!date.is_open()) {
		cout << Errors().getTheError(3);
		Errors().~Errors();
	}
	date.read((char*)&this->thisAccount, sizeof(AccountDate));
	date.close();
}

void Account :: Questionary(bool& logOut) {					//anketa
startQuestionary:
	char* _name = new char[30];
	char* _surname = new char[30];
	char* _address = new char[100];
	cout << "\n\n\t\tYour Name: ";
	cin >> _name;
	cout << "\t\tYour Surname: ";
	cin >> _surname;
	cout << "\t\tYour home address:\n\t\t";
	string tmp;
	getline(cin, tmp);
	Setup().stringToChar(tmp, _address);
	isCorrectQuestionary:
	system("cls");
	cout << "\n\n\t\tName: ";
	cout << _name << endl;
	cout << "\t\tSurname: ";
	cout << _surname <<endl;
	cout << "\t\tHome address: ";
	cout << _address << endl <<  endl;
	cout << "\t\tIs everything correct?\n\t\t1 - yes , 0 - correct date, l - log out\n\t\t";
	cin >> tmp;
	if (tmp == "1") {
		this->thisAccount.questionary = true;
		this->thisAccount.Name = _name;
		this->thisAccount.Surname = _surname;
		this->thisAccount.fullAdress = _address;
	}
	else if (tmp == "0") {
		goto startQuestionary;
	}
	else if (tmp == "l" || tmp == "L") {
		logOut = true;
	}
	else {
		Errors().getTheError(1);
		Sleep(500);
		goto isCorrectQuestionary;
	}


}
 
void Account::userMenu(bool& escape, bool& logOut) {
startUserMenu:
	system("cls");
	if (escape || logOut) {
		return;
	}
	if (!this->thisAccount.questionary) {
		Questionary(escape);
		goto startUserMenu;
	}
	cout << "\n\n\t\t\t\tWelcome " << this->thisAccount.Name << endl;
	cout << "\t\tTest ------- 1\n";
	cout << "\t\tYour marks - 2\n";
	cout << "\t\tYour date -- 3\n";
	cout << "\t\te ------- exit\n";
	cout << "\t\tl ----- logOut\n";
	string tmp; cin >> tmp;
	if (tmp == "1") {

	}
	else if (tmp == "2") {

	}
	else if (tmp == "3") {

	}
	else if (tmp == "e" || tmp == "E") {
		escape = true;
		Config().exit();
	}
	else if (tmp == "l" || tmp == "L") {
		logOut = true;
	}
	else {
		Errors().getTheError(1);
	}
	goto startUserMenu;
}

void  Account:: AdminMenu(bool& escape, bool& logOut) {
	cout << "ok lets go";
	Sleep(1000);
}

void Account:: Menu(bool& escape) {
	bool logOut = false;
	if (this->admin) {
		AdminMenu(escape, logOut);
	}
	else {
		userMenu(escape, logOut);
	}
}
