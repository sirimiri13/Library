// Process2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Oxy.h"
#include "windows.h"
#include "stdlib.h"
#include "string"
#include "conio.h"
#include "iostream"
#include "Login.h"
#include "QLS.h"
#include "QLDG.h"
#include "Total.h"
using namespace std;

void dangnhap(string &st, string &sl, bool &bl, int &level, bool &kt)
{
	do
	{
		gotoxy(30, 5);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(73, 5);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 5);
		cout << "Welcome To Our Library" << endl;
		gotoxy(30, 7);
		cout << "--------------------------------------------------------------- " << endl;
		gotoxy(50, 8);
		cout << "Please log in your account" << endl;
		gotoxy(38, 9);
		cout << "Username";
		gotoxy(47, 9);
		cout << ": ";
		gotoxy(38, 10);
		cout << "Password";
		gotoxy(47, 10);
		cout << ": ";
		gotoxy(50, 9);
		getline(cin, st);
		gotoxy(50, 10);
		sl = passwordInput(12);
		bl = DangNhap(st, sl, level, kt);
		if (bl == false)
		{
			gotoxy(30, 12);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Something Went Wrong \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			gotoxy(30, 13);
			int x;
			cout << "0> Exit";
			gotoxy(30, 14);
			cout << "1> Log in Account again" << endl;
			gotoxy(30, 15);
			cout << "Your choice: [ ]";
			gotoxy(44, 15);
			cin >> x;
			if (x == 0)
				return;
			cin.ignore();
			system("cls");
		}
	} while (bl == false);
}

void Admin(int number, int &check, string st, string &sl)
{
	float n;
	bool bl;
	switch (number)
	{
	case 1:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "1.1 Log Out" << endl;
		gotoxy(30, 9);
		cout << "1.2 Change Password" << endl;
		gotoxy(30, 10);
		cout << "1.3 Update Information" << endl;
		gotoxy(30, 11);
		cout << "1.4 Create New User" << endl;
		gotoxy(30, 12);
		cout << "1.5 Distribute User" << endl;
		gotoxy(30, 13);
		cout << "0. Back to menu";
		gotoxy(60, 15);
		cout << "Choose any number: [ ";
		gotoxy(83, 15);
		cout << "]" << endl;
		gotoxy(80, 15);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 11:
		{
			system("cls");
			gotoxy(30, 6);
			cout << "******** Log out Account Successfully *******" << endl;
			check = 2;
			return;
		}
		case 12:
		{
			changepw(st, sl, check, 1);
			return;
			break;
		}
		case 13:
		{
			bl = false;
			update(1, bl, st);
			if (bl == true)
				cout << "                                  Update Successfully !!!" << endl;
			else
				cout << "                                  Update Unsuccessfully !!!" << endl;
			break;
		}
		case 14:
		{
			bl = false;
			Creatuser(bl);
			if (bl == true)
				cout << "                                   Create New User Successfully !!!" << endl;
			else
				cout << "                                   Create New User Unsuccessfully !!!" << endl;
			break;
		}
		case 15:
		{
			bl = false;
			Distribute(bl);
			if (bl == true)
				cout << "                                   Distribute successfully !!!" << endl;
			else
				cout << "                                   Distribute unsuccessfully !!!" << endl;
			break;
		}
		case 0:
		{
			return;
		}
		}

		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Admin(number, check, st, sl);
		break;
	}
	case 2:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "2.1 List of Reader" << endl;
		gotoxy(30, 9);
		cout << "2.2 Add Reader" << endl;
		gotoxy(30, 10);
		cout << "2.3 Update Information of Reader" << endl;
		gotoxy(30, 11);
		cout << "2.4 Delete Reader" << endl;
		gotoxy(30, 12);
		cout << "2.5 Find Reader by ID" << endl;
		gotoxy(30, 13);
		cout << "2.6 Find Reader by Fullname" << endl;
		gotoxy(30, 14);
		cout << "0. Back to menu";
		gotoxy(60, 16);
		cout << "Choose any number: [ ";
		gotoxy(83, 16);
		cout << "]" << endl;
		gotoxy(80, 16);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 21:
		{
			QLDG(21);
			break;
		}
		case 22:
		{
			QLDG(22);
			break;
		}
		case 23:
		{
			QLDG(23);
			break;
		}
		case 24:
		{
			QLDG(24);
			break;
		}
		case 25:
		{
			QLDG(25);
			break;
		}
		case 26:
		{
			QLDG(26);
			break;
		}
		case 0:
		{
			return;
		}
		}
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Admin(number, check, st, sl);
		break;
	}
	case 3:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "3.1 List of Book" << endl;
		gotoxy(30, 9);
		cout << "3.2 Add Book" << endl;
		gotoxy(30, 10);
		cout << "3.3 Update Information of Book" << endl;
		gotoxy(30, 11);
		cout << "3.4 Delete Book" << endl;
		gotoxy(30, 12);
		cout << "3.5 Find Book by ISBN" << endl;
		gotoxy(30, 13);
		cout << "3.6 Find Book by Name" << endl;
		gotoxy(30, 14);
		cout << "0. Back to menu";
		gotoxy(60, 16);
		cout << "Choose any number: [ ";
		gotoxy(83, 16);
		cout << "]" << endl;
		gotoxy(80, 16);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 31:
		{
			QLS(31);
			break;
		}
		case 32:
		{
			QLS(32);
			break;
		}
		case 33:
		{
			QLS(33);
			break;
		}
		case 34:
		{
			QLS(34);
			break;
		}
		case 35:
		{
			QLS(35);
			break;
		}
		case 36:
		{
			QLS(36);
			break;
		}
		case 0:
		{
			return;
		}
		}
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Admin(number, check, st, sl);
		break;
	}
	case 4:
	{
		Total(4);
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		return;
		break;
	}
	case 5:
	{
		Total(5);
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		return;
		break;
	}
	case 6:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "6.1 Statistics of books in the library" << endl;
		gotoxy(30, 9);
		cout << "6.2 Statistics of readers in the library" << endl;
		gotoxy(30, 10);
		cout << "6.3 Show number of books which was borrowed" << endl;
		gotoxy(30, 11);
		cout << "6.4 Show number of reader whose borrowing time is late" << endl;
		gotoxy(30, 12);
		cout << "0. Back to menu";
		gotoxy(60, 14);
		cout << "Choose any number: [ ";
		gotoxy(83, 14);
		cout << "]" << endl;
		gotoxy(80, 14);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 61:
		{
			Total(61);
			break;
		}
		case 62:
		{
			Total(62);
			break;
		}
		case 63:
		{
			Total(63);
			break;
		}
		case 64:
		{
			Total(64);
			break;
		}
		case 0:
		{
			return;
		}
		}
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Admin(number, check, st, sl);
	}
	case 7:
	{
		INFO(st, 1);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
	}
	default:
	{
		break;
	}
	}
}

void Manager(int number, int &check, string st, string &sl)
{
	float n;
	bool bl;
	switch (number)
	{
	case 1:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "1.1 Log Out" << endl;
		gotoxy(30, 9);
		cout << "1.2 Change Password" << endl;
		gotoxy(30, 10);
		cout << "1.3 Update Information" << endl;
		gotoxy(30, 11);
		cout << "0. Back to menu";
		gotoxy(60, 13);
		cout << "Choose any number: [ ";
		gotoxy(83, 13);
		cout << "]" << endl;
		gotoxy(80, 13);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 11:
		{
			system("cls");
			gotoxy(30, 6);
			cout << "******** Log out Account Successfully *******" << endl;
			check = 2;
			return;
		}
		case 12:
		{
			changepw(st, sl, check, 1);
			return;
			break;
		}
		case 13:
		{
			bl = false;
			update(1, bl, st);
			if (bl == true)
				cout << "                                  Update Successfully !!!" << endl;
			else
				cout << "                                  Update Unsuccessfully !!!" << endl;
			break;
		}
		case 0:
		{
			return;
		}
		}

		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Manager(number, check, st, sl);
		break;
	}
	case 2:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "2.1 List of Reader" << endl;
		gotoxy(30, 9);
		cout << "2.2 Add Reader" << endl;
		gotoxy(30, 10);
		cout << "2.3 Update Information of Reader" << endl;
		gotoxy(30, 11);
		cout << "2.4 Delete Reader" << endl;
		gotoxy(30, 12);
		cout << "2.5 Find Reader by ID" << endl;
		gotoxy(30, 13);
		cout << "2.6 Find Reader by Fullname" << endl;
		gotoxy(30, 14);
		cout << "0. Back to menu";
		gotoxy(60, 16);
		cout << "Choose any number: [ ";
		gotoxy(83, 16);
		cout << "]" << endl;
		gotoxy(80, 16);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 21:
		{
			QLDG(21);
			break;
		}
		case 22:
		{
			QLDG(22);
			break;
		}
		case 23:
		{
			QLDG(23);
			break;
		}
		case 24:
		{
			QLDG(24);
			break;
		}
		case 25:
		{
			QLDG(25);
			break;
		}
		case 26:
		{
			QLDG(26);
			break;
		}
		case 0:
		{
			return;
		}
		}
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Manager(number, check, st, sl);
		break;
	}
	case 3:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "3.1 List of Book" << endl;
		gotoxy(30, 9);
		cout << "3.2 Add Book" << endl;
		gotoxy(30, 10);
		cout << "3.3 Update Information of Book" << endl;
		gotoxy(30, 11);
		cout << "3.4 Delete Book" << endl;
		gotoxy(30, 12);
		cout << "3.5 Find Book by ISBN" << endl;
		gotoxy(30, 13);
		cout << "3.6 Find Book by Name" << endl;
		gotoxy(30, 14);
		cout << "0. Back to menu";
		gotoxy(60, 16);
		cout << "Choose any number: [ ";
		gotoxy(83, 16);
		cout << "]" << endl;
		gotoxy(80, 16);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 31:
		{
			QLS(31);
			break;
		}
		case 32:
		{
			QLS(32);
			break;
		}
		case 33:
		{
			QLS(33);
			break;
		}
		case 34:
		{
			QLS(34);
			break;
		}
		case 35:
		{
			QLS(35);
			break;
		}
		case 36:
		{
			QLS(36);
			break;
		}
		case 0:
		{
			return;
		}
		}
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Manager(number, check, st, sl);
		break;
	}
	case 4:
	{
		Total(4);
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		return;
		break;
	}
	case 5:
	{
		Total(5);
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		return;
		break;
	}
	case 6:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "6.1 Statistics of books in the library" << endl;
		gotoxy(30, 9);
		cout << "6.2 Statistics of readers in the library" << endl;
		gotoxy(30, 10);
		cout << "6.3 Show number of books which was borrowed" << endl;
		gotoxy(30, 11);
		cout << "6.4 Show number of reader whose borrowing time is late" << endl;
		gotoxy(30, 12);
		cout << "0. Back to menu";
		gotoxy(60, 14);
		cout << "Choose any number: [ ";
		gotoxy(83, 14);
		cout << "]" << endl;
		gotoxy(80, 14);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 61:
		{
			Total(61);
			break;
		}
		case 62:
		{
			Total(62);
			break;
		}
		case 63:
		{
			Total(63);
			break;
		}
		case 64:
		{
			Total(64);
			break;
		}
		case 0:
		{
			return;
		}
		}
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Manager(number, check, st, sl);
	}
	case 7:
	{
		INFO(st, 2);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
	}
	default:
	{
		break;
	}
	}

}

void Staff(int number, int &check, string st, string &sl)
{
	float n;
	bool bl;
	switch (number)
	{
	case 1:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "1.1 Log Out" << endl;
		gotoxy(30, 9);
		cout << "1.2 Change Password" << endl;
		gotoxy(30, 10);
		cout << "1.3 Update Information" << endl;
		gotoxy(30, 11);
		cout << "0. Back to menu";
		gotoxy(60, 13);
		cout << "Choose any number: [ ";
		gotoxy(83, 13);
		cout << "]" << endl;
		gotoxy(80, 13);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 11:
		{
			system("cls");
			gotoxy(30, 6);
			cout << "******** Log out Account Successfully *******" << endl;
			check = 2;
			return;
		}
		case 12:
		{
			changepw(st, sl, check, 1);
			return;
			break;
		}
		case 13:
		{
			bl = false;
			update(1, bl, st);
			if (bl == true)
				cout << "                                  Update Successfully !!!" << endl;
			else
				cout << "                                  Update Unsuccessfully !!!" << endl;
			break;
		}
		case 0:
		{
			return;
		}
		}

		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Staff(number, check, st, sl);
		break;
	}
	case 2:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "2.1 List of Reader" << endl;
		gotoxy(30, 9);
		cout << "2.2 Add Reader" << endl;
		gotoxy(30, 10);
		cout << "2.3 Update Information of Reader" << endl;
		gotoxy(30, 11);
		cout << "2.5 Find Reader by ID" << endl;
		gotoxy(30, 12);
		cout << "2.6 Find Reader by Fullname" << endl;
		gotoxy(30, 13);
		cout << "0. Back to menu";
		gotoxy(60, 15);
		cout << "Choose any number: [ ";
		gotoxy(83, 15);
		cout << "]" << endl;
		gotoxy(80, 15);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 21:
		{
			QLDG(21);
			break;
		}
		case 22:
		{
			QLDG(22);
			break;
		}
		case 23:
		{
			QLDG(23);
			break;
		}
		case 25:
		{
			QLDG(25);
			break;
		}
		case 26:
		{
			QLDG(26);
			break;
		}
		case 0:
		{
			return;
		}
		}
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Staff(number, check, st, sl);
		break;
	}
	case 3:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "3.5 Find Book by ISBN" << endl;
		gotoxy(30, 8);
		cout << "3.6 Find Book by Name" << endl;
		gotoxy(30, 9);
		cout << "0. Back to menu";
		gotoxy(60, 11);
		cout << "Choose any number: [ ";
		gotoxy(83, 11);
		cout << "]" << endl;
		gotoxy(80, 11);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 35:
		{
			QLS(35);
			break;
		}
		case 36:
		{
			QLS(36);
			break;
		}
		case 0:
		{
			return;
		}
		}
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Staff(number, check, st, sl);
		break;
	}
	case 4:
	{
		Total(4);
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		return;
		break;
	}
	case 5:
	{
		Total(5);
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		return;
		break;
	}
	case 6:
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(59, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(50, 6);
		cout << "FUNCTION";
		gotoxy(30, 8);
		cout << "6.3 Show number of books which was borrowed" << endl;
		gotoxy(30, 9);
		cout << "6.4 Show number of reader whose borrowing time is late" << endl;
		gotoxy(30, 10);
		cout << "0. Back to menu";
		gotoxy(60, 12);
		cout << "Choose any number: [ ";
		gotoxy(83, 12);
		cout << "]" << endl;
		gotoxy(80, 12);
		cin >> n;
		int Number = int(10 * n);
		switch (Number)
		{
		case 63:
		{
			Total(63);
			break;
		}
		case 64:
		{
			Total(64);
			break;
		}
		case 0:
		{
			return;
		}
		}
		cout << endl;
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
		Staff(number, check, st, sl);
	}
	case 7:
	{
		INFO(st, 3);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Continuous .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		_getch();
	}
	default:
	{
		break;
	}
	}
}

int main(int argc, char *argv[])
{
	int level;
	do
	{
		system("cls");
		string st; string sl;
		bool bl = false;
		bool kt = true;
		if (argc > 1)
		{
			bool b = false;
			for (int i = 0; i < argc; i++)
			{
				if (i == 1)
					st = argv[1];
				if (i == 2)
					sl = argv[2];
			}
			bl = DangNhap(st, sl, level, kt);
		}
			else
				dangnhap(st, sl, bl, level, kt);
		if (bl == false)
		{
			gotoxy(30, 16);
			cout << "******************* Goodbye, See You Later !!! ****************" << endl;
			return 0;
		}
		if (kt == false)
		{
			system("cls");
			gotoxy(20, 2);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** YOUR ACCOUNT WAS BLOCKED **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			int v;
			gotoxy(20, 4);
			cout << "> Click 1 to Show Your Information";
			gotoxy(20, 5);
			cout << "> Click 0 to exit";
			gotoxy(20, 7);
			cout << "-> Your Choice: [ ]";
			gotoxy(37, 7);
			cin >> v;
			if (v == 0)
			{
				gotoxy(20, 9);
				cout << "******************* Goodbye, See You Later !!! ****************" << endl;
				return 0;
			}
			else
			{
				INFO(st, level);
				cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Please Press Any Key To Exit .... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
				_getch();
				gotoxy(20, 12);
				cout << "******************* Goodbye, See You Later !!! ****************" << endl;
				return 0;
			}
			gotoxy(20, 16);
		}
		int number;
		cout << endl;
		int check = 0;
		do
		{
			system("cls");
			gotoxy(30, 6);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			gotoxy(59, 6);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			gotoxy(50, 6);
			cout << "FUNCTION";
			gotoxy(30, 8);
			cout << "1> Account Management" << endl;
			gotoxy(30, 9);
			cout << "2> Reader Management" << endl;
			gotoxy(30, 10);
			cout << "3> Book Management" << endl;
			gotoxy(30, 11);
			cout << "4> Borrow Book" << endl;
			gotoxy(30, 12);
			cout << "5> Give Book BacK" << endl;
			gotoxy(30, 13);
			cout << "6> Statistic " << endl;
			gotoxy(30, 14);
			cout << "7> Your Information" << endl;
			gotoxy(30, 15);
			cout << "0> Exit";
			gotoxy(56, 17);
			cout << "Choose any number: [ ]";
			gotoxy(76, 17);
			cin >> number;
			if (number == 0)
			{
				gotoxy(25, 19);
				cout << "***************** Goodbye, See You Later !!! ****************" << endl;
				return 0;
			}
			check = false;
			if (level == 1)
				Admin(number, check, st, sl);
			else
				if (level == 2)
					Manager(number, check, st, sl);
				else
					Staff(number, check, st, sl);
			if (check == 1)
			{
				system("cls");
				gotoxy(30, 6);
				cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  Your Password Is Changed Successfully  !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
				gotoxy(30, 7);
				cout << "0> Log Out This Account";
				gotoxy(30, 8);
				cout << "1> Continue This Account";
				gotoxy(30, 9);
				cout << "Your choice: [ ]";
				int x;
				gotoxy(44, 9);
				cin >> x;
				if (x == 0)
				{
					gotoxy(40, 10);
					cout << "Log out Account Successfully" << endl;
					check = 2;
					break;
				}
				else
					check = 0;
			}
		} while (check == 0);
		system("cls");
		gotoxy(30, 7);
		int x;

		cout << "0> Exit";
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  Your Account was Loged Out !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
		gotoxy(30, 8);
		cout << "1> Log in Account Again" << endl;
		gotoxy(30, 9);
		cout << "Your choice: [ ]";
		gotoxy(44, 9);
		cin >> x;
		cin.ignore();
		if (x == 0)
		{
			gotoxy(30, 18);
			cout << "******************* Goodbye, See You Later !!! ****************" << endl;
			return 0;
		}
		system("cls");
	} while (1 == 1);
	return 0;
}