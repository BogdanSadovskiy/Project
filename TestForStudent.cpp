#include "TestForStudent.h"
void TestForStudent::numOfTasks() {						//num of task in test
	int tmp = 0;
	for (int i = 0; this->fullTest[i] != '\0'; i++) {
		if (fullTest[i] == '#') {
			tmp++;
		}
	}
	this->_numOfTasks = tmp;
}

TestForStudent::TestForStudent(string nameOfTest) {		//constructor
	ifstream tmp(nameOfTest + ".txt");
	while (tmp) {
		string str;
		getline(tmp, str);
		str += "\n";
		this->fullTest += str;
	}
	numOfTasks();
}



string TestForStudent:: getTestTask(int num, string& rightAnswer, int& markForAnswer) {
	string strTask;										
	int k = 0;
	for (int i = 0; this->fullTest[i] != '\0'; i++) {		//divide task from all tasks
		int j = 0;
		for (; this->fullTest[i] != '#'; j++) {
			strTask.push_back(this->fullTest[i]);
			i++;	
		}
		k++;
		i= i + 2;
		rightAnswer.push_back(this->fullTest[i - 1]);
		string mark;
		mark.push_back(this->fullTest[i - 1]);
		markForAnswer = stoi(mark);
		if (k == num) {
			return strTask;
		}
		strTask = "";
	}
	return strTask;
}

void Done() {
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\tDone\n";
}

void addMark(int mark, int*& marks) {			//adding marks
	int i = 0;
	for (; marks[i] != 69; i++);
	if (i == 19) {
		for (int i = 0; i < 18; i++) {
			marks[i] = marks[i + 1];
		}
	}
	marks[i] = mark;
	marks[i + 1] = 69;
}
void TestForStudent:: MainMenuTask(int& numOfDoneTests, int*& mark) {
	int _mark = 0;
	string rightAnswer;
	int markForAnswer;
	for (int i = 0; i < this->_numOfTasks; i++) {
		system("cls");
		cout << "\n\n";
		cout << getTestTask(i + 1, rightAnswer, markForAnswer);
		if (i > 0) { cout << "b - back / "; }
		cout << "e - exit\n";
		string answer; cin >> answer;
		if (i > 0) {
			if (answer == "b" || answer == "B") {
				i = i - 2;
				continue;
			}
		}
		if (answer == "e" || answer == "E") {
			return;
		}
		if (answer == rightAnswer) {
			_mark += markForAnswer;
		}
	}
	addMark(_mark, mark);
	numOfDoneTests++;
	Done();
}