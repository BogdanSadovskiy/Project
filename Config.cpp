#include "Config.h"

Config::Config() {
	this->numberOfAcc = this->getNumberOfAcc();
}

int Config::getNumberOfAcc() {				//reading how many accounts we have
	ifstream num;
	num.open("numberOfAcc", ios::binary);
	if (!num.is_open()) {
		cout << Errors().getTheError(3);
	}
	num.read((char*)&this->numberOfAcc, 10);
	num.close();
	cout << numberOfAcc;
	Sleep(1000);
	return numberOfAcc;
}

void Config::pushNumberOfAcc() {		//saving new amount of accounts
	ofstream add;
	add.open("numberOfAcc", ios::binary);
	if (!add.is_open()) {
		cout << Errors().getTheError(3);
		Errors().~Errors();
	}
	add.write((char*)&this->numberOfAcc, 10);
	add.close();
}

bool Config:: isEmailTrue(char* Email){			
	for (int i = 0; Email[i] != '\0'; i++) {
		if (Email[i] == '@') {
			while (Email[i] != '\0') {
				if (Email[i] == '.'&& Email[i+1] == 'c'&& Email[i+2] == 'o'&& Email[i+3] == 'm') {
					if (Email[i + 4] == '\0') {
						return true;
					}
				}
				i++;
			}
		}
	}
	return false;
}
bool Config::isPassSave(char* pass) {
	if (strlen(pass) < 6) {
		cout << Errors().getTheError(8);
		return false;
	}
	bool Uppercase = false;
	bool lowercase = false;
	bool otherSymbol = false;
	for (int i = 0; pass[i] != '\0'; i++) {
		if ((int)pass[i] > 64 && (int)pass[i] < 91) {
			Uppercase = true;
		}
		else if ((int)pass[i] > 96 && (int)pass[i] < 123) {
			lowercase = true;
		}
		else  {
			otherSymbol = true;
		}
	}
	cout << Uppercase << " " << lowercase << " " << otherSymbol << endl;
	if (!Uppercase || !lowercase || !otherSymbol) {
		cout << Errors().getTheError(10);
		Errors().~Errors();
		return false;
	}
	return true;
}
bool isAdmin(bool& access, char* login, char* password, char* readedLog, char* readedPass) {		//are u admin?
	ifstream tmp;
	tmp.open("Admin", ios::binary);
	if (!tmp.is_open()) {
		cout << Errors().getTheError(3);
	}
	tmp.read(readedLog, 30);
	tmp.read(readedPass, 30);
	tmp.close();
	if (Setup().isSameChars(readedLog, login) && Setup().isSameChars(readedPass, password)) {	
		access = true;
		return true;
	}
	return false;
}

bool Config::isLogAndPassTrue(bool& access, char* login, char* password) {					
	ifstream tmp;
	char* readedLog = new char[30];
	char* readedPass = new char[30];
	if (isAdmin(access, login, password, readedLog, readedPass)) {
		return true;
	}
	if (this->numberOfAcc == 0) {
		return false;
	}
	tmp.open("Logs", ios::binary);
	if (!tmp.is_open()) {
		cout << Errors().getTheError(3);
	}
	for (int i = 0; i < numberOfAcc; i++) {
		tmp.read(readedLog, 30);
		tmp.read(readedPass, 30);
		if (Setup().isSameChars(readedLog, login) && Setup().isSameChars(readedPass, password)) {
			access = false;
			tmp.close();
			return true;
		}
	}
	tmp.close();
	return false;
}

bool Config:: isLogExist(char* login) {
	ifstream tmp;
	char* readedLog = new char[30];
	tmp.open("Logs", ios::binary);
	if (!tmp.is_open()) {
		cout << Errors().getTheError(3);
	}
	for (int i = 0; i < numberOfAcc; i++) {
		char* c = new char [30];
		tmp.read(readedLog, 30);
		Sleep(500);
		tmp.read(c, 30);
		if (Setup().isSameChars(readedLog, login)) {
			tmp.close();
			cout << Errors().getTheError(5);
			Sleep(1000);
			return true;
		}
	}
	tmp.close();
	tmp.open("Admin", ios::binary);
	if (!tmp.is_open()) {
		cout << Errors().getTheError(3);
	}

	tmp.read(readedLog, 30);
	tmp.close();
	if (Setup().isSameChars(readedLog, login)) {
		cout << Errors().getTheError(5);
		Sleep(1000);
		return true;
	}
	return false;
}

char* Config:: hashing(char* password) {
	char* hash = new char[30];
	int i = 0;
	int salt = 32, _salt = 32;
	for (; password[i] != '\0'; i++) {
		unsigned num = ((int)password[i] * 31) / 30;			//hashing of password
		hash[i] = num;
	}
	cout << endl;
	for (; i != 29; i++) {								//salting of password
		if (salt > 125) {
			salt = _salt + 2;
		}
		hash[i] = salt;
		salt += 9;
	}
	hash[i] = '\0';
	cout << endl;
	return hash;
}

void Config::createAccount(char* login,  char* password) {			// creatin new account
	ofstream newAcc;
	newAcc.open("Logs", ios::app | ios::binary);
	if (!newAcc.is_open()) {
		cout << Errors().getTheError(3);
		Errors().~Errors();
	}
	newAcc.write(login, 30);
	newAcc.write(password, 30);
	newAcc.close();
	this->numberOfAcc++;          //+1 acc
	pushNumberOfAcc();//we have added +1 acc
}

void Config::exit() {
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tBye\n\n\n\n\n\n\n\n\n";
	Sleep(800);
}

void Config::enterMenu() {			// main menu/first page
	bool escape = false; string input;
entermenu:
	if (escape) {			// checking for exit
		return ;
	}
	Menu().mainMenu(input);
	if (input == "1") {
		logIn(escape);
	}
	else if (input == "2") {
		sighUp(escape);
	}
	else if (input == "e" || input == "E") {
		exit(); return;
	}
	else {
		;
		cout << "\t\t\t\t\t\t" << Errors().getTheError(1);  //gets the error from config class
		Sleep(500);
	}
	goto entermenu;
}

void Config::logIn(bool& escape) {
	if (escape) {
		return;
	}
startLoging:
	string tmp;
	Menu().LoginingLog(tmp);
	char* login = new char[30]; 
	if (tmp == "b" || tmp == "B") {
		return;
	}
	else if (tmp == "e" || tmp == "E") {
		exit();
		escape = true; return;
	}
	Setup().stringToChar(tmp, login);

	Menu().LoginingPass(tmp, login);
	char* pass = new char[30]; 
	if (tmp == "b" || tmp == "B") {
		goto startLoging;
	}
	else if (tmp == "e" || tmp == "E") {
		exit();
		escape = true; return;
	}
	Setup().stringToChar(tmp, pass);
	pass = hashing(pass);
	bool access = false;
	if (isLogAndPassTrue(access, login, pass)) {
		Account (access, this->numberOfAcc, login, pass).accMenu(escape);
	}
	else {
		cout << Errors().getTheError(4);
		goto startLoging;
		Sleep(500);
	}
}
void Config::sighUp(bool& escape) {
startSighUp:
	char* login = new char[30];
	string tmp;  
	Menu().SighUpLog(tmp);
	if (tmp == "b" || tmp == "B") {
		return;
	}
	else if (tmp == "e" || tmp == "E") {
		exit();
		escape = true;  return;
	}
	Setup().stringToChar(tmp, login);
	if (!isEmailTrue(login)) {
		cout << "\t\t\t\t\t\t" << Errors().getTheError(2);
		Sleep(500);
		goto startSighUp;
	}
	if (isLogExist(login)) {
		goto startSighUp;
	}

startSighPass:
	Menu().SighUpPass(tmp, login);
	char* pass = new char[30]; 
	if (tmp == "b" || tmp == "B") {
		goto startSighUp;
	}
	else if (tmp == "e" || tmp == "E") {
		escape = true;
		exit(); return;
	}
	Setup().stringToChar(tmp, pass);
	cout << "\t\t\t\t\t\t";
	if (!isPassSave(pass)) {
		Sleep(800);
		goto startSighPass;
	}
	pass = hashing(pass); //hashing of pass
	createAccount(login, pass);
	Account newAcc(login);
	cout <<"\n\n\n\n\n\n\n\t\t\t\t\t\tGREAT\n";
	Sleep(1000);
	logIn(escape);
}