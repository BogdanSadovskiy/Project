#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#include <conio.h>
#include<vector>

void desMath(int numOfTests) 
	{
		// Get a handle to the console window for setting text attributes
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		int textColor = 11;  // Initial text color
		int bgColor = 0;    // Initial background color
		int steps = 500;    // Number of color transition steps
		int delay = 50;     // Delay between color transitions in milliseconds

		// Set the console output to support UTF-8 characters
		SetConsoleOutputCP(CP_UTF8);

		// Define the console font size
		CONSOLE_FONT_INFOEX fontInfo = { sizeof(CONSOLE_FONT_INFOEX) };
		GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
		fontInfo.dwFontSize.X = 30;
		fontInfo.dwFontSize.Y = 30;
		SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

		// Set the initial text attributes (color)
		SetConsoleTextAttribute(hConsole, WORD(textColor | (bgColor << 4)));

		// Define the ASCII art for the logo as an array of wide characters
		vector<const wchar_t*> arr;

		// Fill the array with the logo ASCII art
		// (each element in the array represents a line of the logo)

		arr.push_back(L"\n\n\n\t\t\t█████████████████████████████████████████████████████████████");
		arr.push_back(L"\n\t\t\t█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░██░░░░░░█░░░░░░░░░░░░░░█");
		arr.push_back(L"\n\t\t\t█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█");
		arr.push_back(L"\n\t\t\t█░░░░░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█");
		arr.push_back(L"\n\t\t\t█████████░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█");
		arr.push_back(L"\n\t\t\t█░░░░░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█");
		arr.push_back(L"\n\t\t\t█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█");
		arr.push_back(L"\n\t\t\t█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█");
		arr.push_back(L"\n\t\t\t█░░▄▀░░░░░░░░░░█░░▄▀░░██░░▄▀░░█░░░░░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█");
		arr.push_back(L"\n\t\t\t█░░▄▀░░█████████░░▄▀░░██░░▄▀░░█████████░░▄▀░░█░░▄▀░░██░░▄▀░░█");
		arr.push_back(L"\n\t\t\t█░░▄▀░░░░░░░░░░█░░▄▀░░░░░░▄▀░░█████████░░▄▀░░█░░▄▀░░░░░░▄▀░░█");
		arr.push_back(L"\n\t\t\t█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█████████░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█");
		arr.push_back(L"\n\t\t\t█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█████████░░░░░░█░░░░░░░░░░░░░░█");
		arr.push_back(L"\n\t\t\t█████████████████████████████████████████████████████████████\n\t\t\t");

		// Loop through the array and write each line to the console
		for (const wchar_t* a : arr)
		{
			WriteConsoleW(hConsole, a, wcslen(a), nullptr, nullptr);
		}

		// Perform a color transition animation
		for (int i = steps; i > 0; i--) {

			if (_kbhit()) {
				break;
			}
			textColor -= i;
			bgColor -= i;

			// Set the new text attributes (color) for the console
			SetConsoleTextAttribute(hConsole, WORD(textColor | (bgColor >> 4)));

			// Clear the console screen
			system("cls");

			// Redraw the logo with the new colors
			for (int j = 0; j < 14; j++)
			{
				WriteConsoleW(hConsole, arr[j], wcslen(arr[j]), nullptr, nullptr);
			}

			// Pause briefly to display the animation
			Sleep(delay);
		}

		// Restore the console text attributes to the default
		SetConsoleTextAttribute(hConsole, 7);
	
}