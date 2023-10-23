#include "Account.h"

void Account:: saveAccountLog( char * login) {				//saving date of account
	ofstream date;
	date.open(login, ios::binary);
	if (!date.is_open()) {
		cout << Errors().getTheError(3);
		Errors().~Errors();
	}
	date.write((char*)&this->thisAccount, sizeof(AccountDate));
	date.close();
}

Account::Account( char* login) {					//constructor for sighUping
	this->thisAccount.questionary = false;

	this->thisAccount.numOfMathAnalisis = 0;
	this->thisAccount.numOfMathDescret = 0;
	this->thisAccount.numOfMechanicPhysics = 0;
	this->thisAccount.numOfQuantumPhysics = 0;

	this->thisAccount.numOfMathAnalisisDone = 0;
	this->thisAccount.numOfMathDescretDone = 0;
	this->thisAccount.numOfMechanicPhysicsDone = 0;
	this->thisAccount.numOfQuantumPhysicsDone = 0;
	

	Setup().stringToChar("Non", this->thisAccount.Name);
	Setup().stringToChar("registrated", this->thisAccount.Surname);
	this->thisAccount.fullAdress[0] = '\0';
	int none = 69;
	this->thisAccount.AnalisisMarks[0] = none;
	this->thisAccount.DescretMarks[0] = none;
	this->thisAccount.MechanicMarks[0] = none;
	this->thisAccount.QuantumMarks[0] = none;
	
	saveAccountLog(login);
}

Account::Account( bool access, int& numberOfAcc, char* login, char* password) {
	if (access) {
		this->admin = true;		//constructor for logIning
	}
	else {
		this->admin = false;
		readDate(login);
	}
	this->attributes.login = login;
	this->attributes.password = password;
	this->numberOfAcc = numberOfAcc;
	
	getEveryLogDate();
}



void Account::getEveryLogDate() {			//reading all acc log date
	ifstream tmp; tmp.open("Logs", ios::binary);
	if (!tmp.is_open()) {
		cout << Errors().getTheError(3);
	}
	for (int i = 0; i < this->numberOfAcc; i++) {
		tmp.read(this->accounts[i].login, 30);
		tmp.read(this->accounts[i].password, 30);
		cout << this->accounts[i].login << endl;
	}
	Sleep(1000);
	tmp.close();
}

void Account::writeEveryLogDate() {				//writing all acc logs date
	ofstream tmp; tmp.open("Logs", ios::binary);
	if (!tmp.is_open()) {
		cout << Errors().getTheError(3);
	}
	for (int i = 0; i < this->numberOfAcc; i++) {
		tmp.write(this->accounts[i].login, 30);
		tmp.write(this->accounts[i].password, 30);
	}
	tmp.close();
}

void Account::readDate(char* login) {		//reading for cuurrent date of account
	ifstream date;
	date.open(login, ios::binary);
	if (!date.is_open()) {
		cout << Errors().getTheError(3);
	}
	date.read((char*)&this->thisAccount, sizeof(AccountDate));
	date.close();
}

void Account :: Questionary(bool& escape, bool& logOut) {					//anketa
startQuestionary:
	string tmp;
	char* _name = new char[30];
	char* _surname = new char[30];
	char* _address = new char[100];
	Menu().QuestionaryAccount(_name, _surname, _address);
isCorrectQuestionary:
	Menu().QuestionaryAccountSecond(_name, _surname, _address, tmp);
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
	else if (tmp == "e" || tmp == "E") {
		escape = true;
		Config().exit();
	}
	else {
		Errors().getTheError(1);
		Sleep(500);
		goto isCorrectQuestionary;
	}
}
 
void Account::userMenu(bool& escape, bool& logOut) {
startUserMenu:
	
	if (escape || logOut) {
		return;
	}
	if (!this->thisAccount.questionary) {
		Questionary(escape, logOut);
		goto startUserMenu;
	}
	
	string tmp; 
	Menu().accMenustart(tmp, this->thisAccount.Name);

	if (tmp == "1") {
		accTest(escape, logOut);
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
		cout << Errors().getTheError(1);
		Sleep(600);
	}
	goto startUserMenu;
}

void  Account:: AdminMenu(bool& escape, bool& logOut) {

}

void Account:: accMenu(bool& escape) {
	bool logOut = false;
	if (this->admin) {
		AdminMenu(escape, logOut);
	}
	else {
		userMenu(escape, logOut);
	}
}

void Account::accTest(bool& escape, bool& logOut) {
startAccTest:
	if (escape || logOut) {
		return;
	}
	string tmp;
	Menu().TestAccountMenu(tmp);
	string nameTest;

	if (tmp == "1") {
		nameTest = "Descret math test";
	}
	else if (tmp == "2") {
		nameTest = "Math analysis";
	}
	else if (tmp == "3") {
		nameTest = "mechanic";
	}
	else if (tmp == "4") {
		nameTest = "quantum physics test";
	}
	else if (tmp == "b" || tmp == "B") {
		return;
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
		Sleep(600);
	}
	TestForStudent(nameTest).MainMenuTask(this->thisAccount.numOfMathAnalisisDone, this->thisAccount.AnalisisMarks);
	goto startAccTest;


}