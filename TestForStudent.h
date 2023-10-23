#pragma once
#include "Config.h"
class TestForStudent
{
private:
	string fullTest;
	int _numOfTasks;
	void numOfTasks();
public:
	TestForStudent(string nameOfTest);
	void  MainMenuTask(int& numOfDoneTests, int*& _mark);
	string getTestTask(int num, string& rightAnswer, int& markForAnswer);
};

