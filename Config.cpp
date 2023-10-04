#include "Config.h"

Config::Config() {
	this->access.log = false;
	this->access.password = false;
	this->access.permission = false;
}

bool Config:: isEmailTrue(string Email){

	for (int i = 0; Email[i] != '\n'; i++) {
		if (Email[i] == '@') {
			while (Email[i] != '\n') {
				if (Email[i] == '.'&& Email[i+1] == 'c'&& Email[i+2] == 'o'&& Email[i+3] == 'm') {
					if (Email[i + 4] == '\n') {
						return true;
					}
				}
				i++;
			}
		}
	}
	return false;
}
bool Config::isPassSave(string pass) {
	if (pass.length() < 6) {
		cout << Errors().getTheError(8);
		return false;
	}
	bool Uppercase = false;
	bool lowercase = false;
	bool otherSymbol = false;
	for (int i = 0; pass[i] != '\n'; i++) {
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
	if (!Uppercase || !lowercase || !otherSymbol) {
		cout << Errors().getTheError(10);
		return false;
	}
	return true;
}

void stringToChar(string login, string password, char*& _login, char*& _password) {
	int i = 0;
	for (; login != "\n"; i++) {
		_login[i] = login[i];
	}
	_login[i] = '\0';
	for (i = 0; login != "\n"; i++) {
		_password[i] = password[i];
	}
	_password[i] = '\0';
}
void Config::createAccount(string login, string password) {			
	ifstream newAcc;
	char* _login = new char[30];
	char* _password  = new char [30];
	stringToChar(login, password, _login, _password);
	newAcc.open("Logs", ios::app | ios::binary);
}

void Config::exit() {
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tBye\n";
}

void Config::enterMenu() {			// main menu/first page
	bool escape = false;
entermenu:
	if (escape == true) {			// checking for exit
		return;
	}
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t1) Sigh in\n";
	cout << "\t\t\t\t\t\t2) Sigh up\n";
	cout << "\t\t\t\t\t\te) - exit\n\n\t\t\t\t\t\t";
	string input;
	cin >> input;
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
startLoging:
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\tInput login (Email)\n";
	cout << "\t\t\t\t\t\tb) - back / e - exit\n";
	cout << "\t\t\t\t\t\t";
	string login; cin >> login;
	if (login == "b" || login == "B") {
		return;
	}
	else if (login == "e" || login == "E") {
		exit();
		escape = true; return;
	}
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\tLogin: " << login << endl;
	cout << "\t\t\t\t\t\tInput password\n";
	cout << "\t\t\t\t\t\tb) - back / e - exit\n";
	cout << "\t\t\t\t\t\t";
	string pass; cin >> pass;
	if (login == "b" || login == "B") {
		goto startLoging;
	}
	else if (login == "e" || login == "E") {
		exit();
		escape = true; return;
	}
	
}
void Config::sighUp(bool& escape) {
startSighUp:
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\tInput Email (it will be your login)\n";
	cout << "\t\t\t\t\t\tb) - back / e - exit\n";
	cout << "\t\t\t\t\t\t";
	string login; cin >> login;
	if (login == "b" || login == "B") {
		return;
	}
	else if (login == "e" || login == "E") {
		exit();
	}
	if (!isEmailTrue(login)) {
		cout << "\t\t\t\t\t\t" << Errors().getTheError(2);
		Sleep(500);
	}
	system("cls");
startSighPass:
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\tLogin: " << login << endl;
	cout << "\t\t\t\t\t\tCreate password\n";
	cout << "\t\t\t\t\t\tb) - back / e - exit\n";
	cout << "\t\t\t\t\t\t";
	string pass; cin >> pass;
	if (login == "b" || login == "B") {
		goto startSighUp;
	}
	else if (login == "e" || login == "E") {
		exit();
	}
	cout << "\t\t\t\t\t\t";
	if (!isPassSave(pass)) {
		Sleep(800);
		goto startSighPass;
	}
	Sleep(500);
	cout <<"\n\n\n\n\n\n\n\t\t\t\t\t\tGREAT\n";
	logIn(escape);
}