#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string"
#include "windows.h"
#include "iostream"
using namespace std;

void gotoxy(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

string passwordInput(unsigned maxLength)
{
	std::string pw;
	for (char c; (c = _getch()); )
	{
		if (c == '\n' || c == '\r') {
			std::cout << "\n";
			break;
		}
		else if (c == '\b') {
			std::cout << "\b \b";
			if (!pw.empty()) pw.erase(pw.size() - 1);
		}
		else if (c == -32) {
			_getch();
		}
		else if (isprint(c) && pw.size() < maxLength) {
			std::cout << '*';
			pw += c;
		}
	}
	return pw;
}