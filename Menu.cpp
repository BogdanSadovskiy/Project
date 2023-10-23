#include "Menu.h"


void Menu::mainMenu(string& tmp) {
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t1) Sigh in\n";
	cout << "\t\t\t\t\t\t2) Sigh up\n";
	cout << "\t\t\t\t\t\te) - exit\n\n\t\t\t\t\t\t";
	cin >> tmp;
}

void Menu::LoginingLog(string& tmp) {
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\tInput Email:\n";
	cout << "\t\t\t\t\t\tb) - back / e - exit\n";
	cout << "\t\t\t\t\t\t";
	cin >> tmp;
}

void Menu::LoginingPass(string& tmp, char* login) {
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\tEmail: " << login << endl;
	cout << "\t\t\t\t\t\tInput password\n";
	cout << "\t\t\t\t\t\tb) - back / e - exit\n";
	cout << "\t\t\t\t\t\t";
	cin >> tmp;
}

void Menu::SighUpLog(string& tmp) {
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\tInput Email\n";
	cout << "\t\t\t\t\t\tb) - back / e - exit\n";
	cout << "\t\t\t\t\t\t";
	cin >> tmp;
}

void Menu::SighUpPass(string& tmp, char* login) {
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\tEmail: " << login << endl;
	cout << "\t\t\t\t\t\tCreate password\n";
	cout << "\t\t\t\t\t\tb) - back / e - exit\n";
	cout << "\t\t\t\t\t\t";
	cin >> tmp;
}

void Menu::accMenustart(string& tmp, char* name) {
	system("cls");
	cout << "\n\n\t\t\t\tWelcome " << name << endl;
	cout << "\t\tTest ------- 1\n";
	cout << "\t\tYour marks - 2\n";
	cout << "\t\tYour date -- 3\n";
	cout << "\t\te ------- exit\n";
	cout << "\t\tl ----- logOut\n";
	cin >> tmp;
}

void Menu:: QuestionaryAccount(char*& name, char*& surname, char*& address) {
	system("cls");
	cout << "\n\n\t\tYour Name: ";
	cin >> name;
	cout << "\t\tYour Surname: ";
	cin >> surname;
	cout << "\t\tYour home address:\n\t\t";
	string tmp;
	getline(cin, tmp);
	Setup().stringToChar(tmp, address);
}

void Menu::QuestionaryAccountSecond(char* name, char* surname, char* address, string& tmp) {
	system("cls");
	cout << "\n\n\t\tName: ";
	cout << name << endl;
	cout << "\t\tSurname: ";
	cout << surname << endl;
	cout << "\t\tHome address: ";
	cout << address << endl << endl;
	cout << "\t\tIs everything correct?\n\t\t1 - yes , 0 - to  correct date\n";
	cout << "\t\tl - log out, e - exit\n\t\t";
	cin >> tmp;
}

void Menu::TestAccountMenu(string& tmp) {
	system("cls");
	cout << "\n\n\t\tDiscrete math ---- 1\n";
	cout << "\t\tMath analysis ---- 2\n";
	cout << "\t\tMechanic physics - 3\n";
	cout << "\t\tQuantum physics -- 4\n";
	cout << "\t\tb - back / e - exit / l - logOut\n";
	cin >> tmp;
}