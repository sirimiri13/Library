// Process1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Oxy.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "Windows.h"
#include "fstream"
#include "iostream"
#include "Oxy.h"
#include "string"
using namespace std;
const int N = 500;

void PathAccount(char filename[])
{
	wchar_t res[MAX_PATH];
	wstring s;
	s = wstring(res, GetModuleFileName(NULL, res, MAX_PATH));
	string st(s.begin(), s.end());
	st.erase(st.end() - 12, st.end());
	string sl = "Account.txt";
	st = st + sl;
	strcpy(filename, st.c_str());
}

void PathAdmin(char filename[])
{
	wchar_t res[MAX_PATH];
	wstring s;
	s = wstring(res, GetModuleFileName(NULL, res, MAX_PATH));
	string st(s.begin(), s.end());
	st.erase(st.end() - 12, st.end());
	string sl = "Admin.txt";
	st = st + sl;
	strcpy(filename, st.c_str());
}

void PathManager(char filename[])
{
	wchar_t res[MAX_PATH];
	wstring s;
	s = wstring(res, GetModuleFileName(NULL, res, MAX_PATH));
	string st(s.begin(), s.end());
	st.erase(st.end() - 12, st.end());
	string sl = "Manager.txt";
	st = st + sl;
	strcpy(filename, st.c_str());
}

void PathStaff(char filename[])
{
	wchar_t res[MAX_PATH];
	wstring s;
	s = wstring(res, GetModuleFileName(NULL, res, MAX_PATH));
	string st(s.begin(), s.end());
	st.erase(st.end() - 12, st.end());
	string sl = "Staff.txt";
	st = st + sl;
	strcpy(filename, st.c_str());
}

void process(char filename[], string user[], string pass[], string name[], string DOB[], string CMND[], string address[], string sex[], string state[], int &n)
{
	n = 0;
	string st, sl;
	ifstream fi;
	fi.open(filename);
	while (!fi.eof())
	{
		getline(fi, user[n], ' ');
		if (user[n] == "")
		{
			n--;
			break;
		}
		getline(fi, pass[n], ',');
		getline(fi, name[n], ',');
		getline(fi, DOB[n], ',');
		getline(fi, CMND[n], ',');
		getline(fi, address[n], ',');
		getline(fi, sex[n], ',');
		getline(fi, state[n]);
		n++;
	}
	fi.close();
}

bool Admin(string st, string sl, string &s1, string &s2, string &s3, string &s4, string &s5, string &s6)
{
	int m;
	string user[N], pass[N], name[N], DOB[N], CMND[N], address[N], sex[N], state[N];
	char filename[N];
	PathAdmin(filename);
	process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
	for (int i = 0; i < m; i++)
		if (user[i] == st && pass[i] == sl)
		{
			s1 = name[i];
			s2 = DOB[i];
			s3 = CMND[i];
			s4 = address[i];
			s5 = sex[i];
			s6 = state[i];
			return true;
		}
	return false;
}

bool Manager(string st, string sl, string &s1, string &s2, string &s3, string &s4, string &s5, string &s6)
{
	int m;
	string user[N], pass[N], name[N], DOB[N], CMND[N], address[N], sex[N], state[N];
	char filename[N];
	PathManager(filename);
	process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
	for (int i = 0; i < m; i++)
		if (user[i] == st && pass[i] == sl)
		{
			s1 = name[i];
			s2 = DOB[i];
			s3 = CMND[i];
			s4 = address[i];
			s5 = sex[i];
			s6 = state[i];
			return true;
		}
	return false;
}

bool Staff(string st, string sl, string &s1, string &s2, string &s3, string &s4, string &s5, string &s6)
{
	int m;
	string user[N], pass[N], name[N], DOB[N], CMND[N], address[N], sex[N], state[N];
	char filename[N];
	PathStaff(filename);
	process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
	for (int i = 0; i < m; i++)
		if (user[i] == st && pass[i] == sl)
		{
			s1 = name[i];
			s2 = DOB[i];
			s3 = CMND[i];
			s4 = address[i];
			s5 = sex[i];
			s6 = state[i];
			return true;
		}
	return false;
}

void classify(string st, string sl, int &level)
{
	string s1, s2, s3, s4, s5, s6;
	if (Admin(st, sl, s1, s2, s3, s4, s5, s6))
	{
		level = 1;
		return;
	}
	else
		if (Manager(st, sl, s1, s2, s3, s4, s5, s6))
		{
			level = 2;
			return;
		}
		else
			if (Staff(st, sl, s1, s2, s3, s4, s5, s6))
			{
				level = 3;
				return;
			}
}

void changepw(string st, string &sl, int &bl, int level)
{
	bool check = false;
	string s1, s2;
	cin.ignore();
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** CHANGE PASSWORD  **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20, 4);
	cout << "- Please Type Your Current Password: ";
	gotoxy(20, 5);
	cout << "- Type Your New Password: ";
	gotoxy(20, 6);
	cout << "- Re-Type Your New Password: ";
	do
	{
		//		cout << "- Please Type Your Current Password: ";
		gotoxy(58, 4);
		s1 = passwordInput(12);
		if (s1 == sl)
			check = true;
		if (check == false)
		{
			system("cls");
			gotoxy(30, 6);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  Your Current Password is incorrect  !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
			gotoxy(30, 7);
			cout << "0> Exit";
			gotoxy(30, 8);
			cout << "1> Try Again" << endl;
			gotoxy(30, 9);
			cout << "Your choice: [ ]";
			gotoxy(44, 9);
			int v;
			cin >> v;
			if (v == 0)
				return;
			else
			{
				changepw(st, sl, bl, level);
				return;
			}
			cin.ignore();
		}
	} while (check == false);
	check = false;
	do
	{
		//		cout << "Type your new password: ";
		gotoxy(47, 5);
		s1 = passwordInput(12);
		//		cout << "Re-type your new password: ";
		gotoxy(50, 6);
		s2 = passwordInput(12);
		if (s1 == s2)
		{
			check = true;
			sl = s1;
		}
		if (check == false)
		{
			gotoxy(20, 8);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  They are not same !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
			gotoxy(20, 9);
			cout << "0> Exit";
			gotoxy(20, 10);
			cout << "1> Try Again" << endl;
			gotoxy(20, 11);
			cout << "Your choice: [ ]";
			gotoxy(34, 11);
			int v;
			cin >> v;
			cin.ignore();
			if (v == 0)
				return;
			else
			{
				gotoxy(47, 5);
				cout << "                                ";
				gotoxy(50, 6);
				cout << "                                ";
				for (int i = 0; i <= 80; i++)
					for (int j = 8; j <= 12; j++)
					{
						gotoxy(i, j);
						cout << " ";
					}
			}
		}
	} while (check == false);
	bl = 1;

	int m;
	string user[N], pass[N], name[N], DOB[N], CMND[N], address[N], sex[N], state[N];
	char filename[N];
	PathAccount(filename);
	process(filename, user, pass, name, DOB, CMND, address, sex, state, m);

	ofstream fo;
	fo.open(filename);
	for (int i = 0; i < m; i++)
	{
		if (user[i] == st && pass[i] == sl)
		{
			fo << user[i] << " " << s1 << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
		}
		else
			fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
		if (i != m - 1)
			fo << endl;
	}
	fo.close();
	if (level == 1)
	{
		PathAdmin(filename);
		process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
		ofstream fo;
		fo.open(filename);
		for (int i = 0; i < m; i++)
		{
			if (user[i] == st && pass[i] == sl)
			{
				fo << user[i] << " " << s1 << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
			}
			else
				fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
			if (i != m - 1)
				fo << endl;
		}
	}
	else
		if (level == 2)
		{
			PathManager(filename);
			process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
			ofstream fo;
			fo.open(filename);
			for (int i = 0; i < m; i++)
			{
				if (user[i] == st && pass[i] == sl)
				{
					fo << user[i] << " " << s1 << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
				}
				else
					fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
				if (i != m - 1)
					fo << endl;
			}
		}
		else
		{
			PathStaff(filename);
			process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
			ofstream fo;
			fo.open(filename);
			for (int i = 0; i < m; i++)
			{
				if (user[i] == st && pass[i] == sl)
				{
					fo << user[i] << " " << s1 << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
				}
				else
					fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
				if (i != m - 1)
					fo << endl;
			}
		}
	fo.close();
	return;
}

bool Finduser(string s)
{
	string user[N], pass[N], name[N], DOB[N], CMND[N], address[N], sex[N], state[N];
	char filename[1000];
	int n = 0;
	PathAccount(filename);
	ifstream fi;
	fi.open(filename);
	while (!(fi.eof()))
	{
		getline(fi, user[n], ' ');
		if (user[n] == " ")
			break;
		getline(fi, pass[n], ',');
		getline(fi, name[n], ',');
		getline(fi, DOB[n], ',');
		getline(fi, CMND[n], ',');
		getline(fi, address[n], ',');
		getline(fi, sex[n], ',');
		getline(fi, state[n]);
		if (user[n] == s)
			return false;
		n++;
	}
	fi.close();
	return true;
}

void Creatuser(bool &check)
{
	system("cls");
	gotoxy(20, 1);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** Creating A New User **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	string s1, s2, s3, s33, s4, s5, s6, s7, s8;
	ofstream fo;
	bool bl = false;
	cin.ignore();
	do
	{
		gotoxy(20, 3);
		cout << "- Username: ";
		getline(cin, s1);
		if (Finduser(s1) == false)
		{
			system("cls");
			gotoxy(20, 4);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  This username Has Been Used Before  !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
			gotoxy(20, 5);
			cout << "0> Exit";
			gotoxy(20, 6);
			cout << "1> Try Again" << endl;
			gotoxy(20, 7);
			cout << "Your choice: [ ]";
			gotoxy(34, 7);
			int v;
			cin >> v;
			cin.ignore();
			if (v == 0)
				return;
			else
			{
				Creatuser(check);
				return;
			}
		}
		else
			bl = true;
	} while (bl == false);
	bl = false;
	do
	{
		gotoxy(20, 4);
		cout << "- Password: ";
		s2 = passwordInput(12);
		gotoxy(20, 5);
		cout << "- Re-type Password: ";
		s3 = passwordInput(12);
		if (s2 != s3)
		{
			gotoxy(20, 7);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  Your Re-type Password is not as same as Password  !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
			gotoxy(20, 8);
			cout << "0> Exit";
			gotoxy(20, 9);
			cout << "1> Try Again" << endl;
			gotoxy(20, 10);
			cout << "Your choice: [ ]";
			gotoxy(34, 10);
			int v;
			cin >> v;
			cin.ignore();
			if (v == 0)
				return;
			else
			{
				gotoxy(32, 4);
				cout << "                                                        ";
				gotoxy(40, 5);
				cout << "                                                        ";
				for (int i = 0; i <= 100; i++)
					for (int j = 6; j <= 10; j++)
					{
						gotoxy(i, j);
						cout << " ";
					}
			}
		}
		else
			bl = true;
	} while (bl == false);
	gotoxy(20, 6);
	cout << "- Full name: ";
	getline(cin, s33);
	gotoxy(20, 7);
	cout << "- Date Of Birth: ";
	getline(cin, s4);
	gotoxy(20, 8);
	cout << "- Identity Card: ";
	getline(cin, s5);
	gotoxy(20, 9);
	cout << "- Address: ";
	getline(cin, s6);
	gotoxy(20, 10);
	cout << "- Sex: ";
	getline(cin, s7);
	gotoxy(20, 11);
	cout << "- State: ";
	getline(cin, s8);
	gotoxy(20, 12);
	cout << "- Their LEVEL " << endl;
	cout << "- Click 1 if you want them to be Manager or Click 2 if you want them to be Staff: ";
	int v;
	cin >> v;
	cin.ignore();
	char filename[1000];
	string user[N], pass[N], name[N], DOB[N], CMND[N], address[N], sex[N], state[N];
	int m;
	if (v == 1)
	{
		PathManager(filename);
		process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
		fo.open(filename);
		for (int i = 0; i < m; i++)
			fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i] << endl;
		fo << s1 << " " << s2 << "," << s33 << "," << s4 << "," << s5 << "," << s6 << "," << s7 << "," << s8;
		check = true;
		fo.close();
	}
	else
		if (v == 2)
		{
			PathStaff(filename);
			process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
			fo.open(filename);
			for (int i = 0; i < m; i++)
				fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i] << endl;
			fo << s1 << " " << s2 << "," << s33 << "," << s4 << "," << s5 << "," << s6 << "," << s7 << "," << s8;
			check = true;
			fo.close();
		}
		else
			return;
	PathAccount(filename);
	process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
	fo.open(filename);
	for (int i = 0; i < m; i++)
		fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i] << endl;
	fo << s1 << " " << s2 << "," << s33 << "," << s4 << "," << s5 << "," << s6 << "," << s7 << "," << s8;
	fo.close();
}

void update(int level, bool &check, string st)
{
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** UPDATE INFORMATION OF USER  **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20, 4);
	cout << "- Please Choose Any Number Which You Want To Update !!!" << endl;
	gotoxy(20, 5);
	cout << "1. Your full name" << endl;
	gotoxy(20, 6);
	cout << "2. Date of birth" << endl;
	gotoxy(20, 7);
	cout << "3. Identity card" << endl;
	gotoxy(20, 8);
	cout << "4. Address" << endl;
	gotoxy(20, 9);
	cout << "5. Sex" << endl;
	gotoxy(20, 10);
	cout << "6. Exit" << endl;
	gotoxy(20, 11);
	cout << "Choose any number: [ ]";
	int number;
	gotoxy(40, 11);
	cin >> number;
	if (number == 6)
		return;
	check = true;
	gotoxy(20, 13);
	cout << "Type Your New Information Is Update: ";
	string s;
	cin.ignore();
	getline(cin, s);
	string user[N], pass[N], name[N], DOB[N], CMND[N], address[N], sex[N], state[N];
	int m;
	char filename[1000];
	PathAccount(filename);
	process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
	for (int i = 0; i < m; i++)
	{
		if (user[i] == st)
		{
			if (number == 1)
				name[i] = s;
			if (number == 2)
				DOB[i] = s;
			if (number == 3)
				CMND[i] = s;
			if (number == 4)
				address[i] = s;
			if (number == 5)
				sex[i] = s;
			break;
		}
	}
	ofstream fo;
	fo.open(filename);
	for (int i = 0; i < m; i++)
	{
		fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
		if (i != m - 1)
			fo << endl;
	}
	fo.close();
	if (level == 1)
	{
		PathAdmin(filename);
		process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
		for (int i = 0; i < m; i++)
		{
			if (user[i] == st)
			{
				if (number == 1)
					name[i] = s;
				if (number == 2)
					DOB[i] = s;
				if (number == 3)
					CMND[i] = s;
				if (number == 4)
					address[i] = s;
				if (number == 5)
					sex[i] = s;
				break;
			}
		}
		fo.open(filename);
		for (int i = 0; i < m; i++)
		{
			fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
			if (i != m - 1)
				fo << endl;
		}
		fo.close();
		check = true;
	}
	else
		if (level == 2)
		{
			PathManager(filename);
			process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
			for (int i = 0; i < m; i++)
			{
				if (user[i] == st)
				{
					if (number == 1)
						name[i] = s;
					if (number == 2)
						DOB[i] = s;
					if (number == 3)
						CMND[i] = s;
					if (number == 4)
						address[i] = s;
					if (number == 5)
						sex[i] = s;
					break;
				}
			}
			fo.open(filename);
			for (int i = 0; i < m; i++)
			{
				fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
				if (i != m - 1)
					fo << endl;
			}
			fo.close();
			check = true;
		}
		else
			if (level == 3)
			{
				PathStaff(filename);
				process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
				for (int i = 0; i < m; i++)
				{
					if (user[i] == st)
					{
						if (number == 1)
							name[i] = s;
						if (number == 2)
							DOB[i] = s;
						if (number == 3)
							CMND[i] = s;
						if (number == 4)
							address[i] = s;
						if (number == 5)
							sex[i] = s;
						break;
					}
				}
				fo.open(filename);
				for (int i = 0; i < m; i++)
				{
					fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
					if (i != m - 1)
						fo << endl;
				}
				fo.close();
				check = true;
			}
}

bool finduser(string s, char filename[])
{
	string user[N], pass[N], name[N], DOB[N], CMND[N], address[N], sex[N], state[N];
	int m;
	process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
	for (int i = 0; i < m; i++)
		if (user[i] == s)
			return true;
	return false;
}

void Distribute(bool &check)
{
	bool bl;
	cin.ignore();
	string s;
	char filename[1000];
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** DISTRIBUTION OF USER **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	PathAccount(filename);
	do
	{
		bl = false;
		gotoxy(20, 4);
		cout << "- Type User You Want To Distribute: ";
		getline(cin, s);
		if (finduser(s, filename) == false)
		{
			gotoxy(20, 6);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  THIS USER IS NOT AVAILABLE  !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
			gotoxy(20, 7);
			cout << "0> Exit";
			gotoxy(20, 8);
			cout << "1> Try Again" << endl;
			gotoxy(20, 9);
			cout << "Your choice: [ ]";
			gotoxy(34, 9);
			int v;
			cin >> v;
			if (v == 0)
				return;
			else
			{
				Distribute(check);
				return;
			}
		}
		else
			bl = true;
	} while (bl == false);
	gotoxy(20, 5);
	cout << "+ Click 1 for them to be Manager ";
	gotoxy(20, 6);
	cout << "+ Click 2 for them to be Staff ";
	gotoxy(20, 7);
	cout << "+ Click 0 to exit ";
	gotoxy(20, 8);
	cout << "Your choice: [ ]";
	gotoxy(34, 8);
	int number;
	cin >> number;
	if (number == 0)
		return;
	string user[N], pass[N], name[N], DOB[N], CMND[N], address[N], sex[N], state[N];
	string s1, s2, s3, s4, s5, s6, s7, s8;
	int m;
	PathAccount(filename);
	process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
	for (int i = 0; i < m; i++)
		if (user[i] == s)
		{
			s1 = user[i];
			s2 = pass[i];
			s3 = name[i];
			s4 = DOB[i];
			s5 = CMND[i];
			s6 = address[i];
			s7 = sex[i];
			s8 = state[i];
		}
	ofstream fo;
	if (number == 1)
	{
		PathManager(filename);
		if (finduser(s, filename) == false)
		{
			process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
			fo.open(filename);
			for (int i = 0; i < m; i++)
				fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i] << endl;
			fo << s1 << " " << s2 << "," << s3 << "," << s4 << "," << s5 << "," << s6 << "," << s7 << "," << s8;
			fo.close();

			PathStaff(filename);
			process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
			fo.open(filename);
			for (int i = 0; i < m; i++)
				if (user[i] != s)
				{
					fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
					if (i != m - 1)
						fo << endl;
				}
			fo.close();
		}
	}
	if (number == 2)
	{
		PathStaff(filename);
		if (finduser(s, filename) == false)
		{
			process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
			fo.open(filename);
			for (int i = 0; i < m; i++)
				fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i] << endl;
			fo << s1 << " " << s2 << "," << s3 << "," << s4 << "," << s5 << "," << s6 << "," << s7 << "," << s8;
			fo.close();

			PathManager(filename);
			process(filename, user, pass, name, DOB, CMND, address, sex, state, m);
			fo.open(filename);
			for (int i = 0; i < m; i++)
				if (user[i] != s)
				{
					fo << user[i] << " " << pass[i] << "," << name[i] << "," << DOB[i] << "," << CMND[i] << "," << address[i] << "," << sex[i] << "," << state[i];
					if (i != m - 1)
						fo << endl;
				}
			fo.close();
		}
	}
	check = true;
}

bool DangNhap(string st, string sl, int &level, bool &kt)
{
	int n = 0;
	bool bl;
	string user[N], pass[N], name[N], DOB[N], CMND[N], address[N], sex[N], state[N];
	char filename[N];
	PathAccount(filename);
	process(filename, user, pass, name, DOB, CMND, address, sex, state, n);
	bl = false;
	for (int i = 0; i < n; i++)
		if (st == user[i] && sl == pass[i])
		{

			//				cout << "Login Account Successfully!!!" << endl;
			if (state[i] == "block")
				kt = false;
			bl = true;
			classify(st, sl, level);
			return true;
		}
	//	if (bl == false)
	//			cout << "Login Account Failed, please try again!!!" << endl;
	return false;
}

void INFO(string st, int level)
{
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** YOUR INFORMATION **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	int n;
	string user[N], pass[N], name[N], DOB[N], CMND[N], address[N], sex[N], state[N];
	//string s1, s2, s3, s4, s5, s6;
	ifstream fi;
	char filename[N];
	PathAccount(filename);
	fi.open(filename);
	process(filename, user, pass, name, DOB, CMND, address, sex, state, n);
	for (int i = 0; i<n; i++)
		if (user[i] == st)
		{
			gotoxy(20, 4);
			if (level == 1)
				cout << "- Your Position  : Admin" << endl;
			if (level == 2)
				cout << "- Your Position  : Manager" << endl;
			if (level == 3)
				cout << "- Your Position  : Staff" << endl;
			gotoxy(20, 5);
			cout << "- Fullname       : " << name[i] << endl;
			gotoxy(20, 6);
			cout << "- Date of Birth  : " << DOB[i] << endl;
			gotoxy(20, 7);
			cout << "- ID             : " << CMND[i] << endl;
			gotoxy(20, 8);
			cout << "- Address        : " << address[i] << endl;
			gotoxy(20, 9);
			cout << "- Sex            : " << sex[i] << endl;
			gotoxy(20, 10);
			cout << "- State          : " << state[i] << endl;
			break;
		}
}