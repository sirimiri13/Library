// docgia.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "fstream"
#include "string"
#include "iostream"
#include "Oxy.h";
#include "time.h"
#include "Total.h"
#include "windows.h"
using namespace std;

struct date {
	int dd;
	int mm;
	int yyyy;
};

typedef struct
{
	string number;
	string fullname;
	string ID;
	string DOB;
	string sex;
	string mail;
	string address;
	date borr;
	date res;
}READER;

struct NodeR
{
	READER reader;
	struct NodeR *pNext;
};
typedef struct NodeR NODER;

struct ListR
{
	NODER *pHead;
	NODER *pTail;
};
typedef struct ListR LISTR;
LISTR l;

void PathDG(char filename[])
{
	wchar_t res[MAX_PATH];
	wstring s;
	s = wstring(res, GetModuleFileName(NULL, res, MAX_PATH));
	string st(s.begin(), s.end());
	st.erase(st.end() - 12, st.end());
	string sl = "DG.txt";
	st = st + sl;
	strcpy(filename, st.c_str());
}

void CreateR(LISTR &l)
{
	l.pHead = l.pTail = NULL;
}

NODER *CreateNodeR(READER x)
{
	NODER *p = new NODER;
	if (p == NULL)
		return NULL;
	p->reader = x;
	p->pNext = NULL;
	return p;
}

void AddLR(LISTR &l, NODER *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void ReadR(LISTR &l, READER &reader, ifstream &fi, NODER *p)
{
	string tmp;
	CreateR(l);
	while (fi.eof() == false)
	{
		getline(fi, reader.number, ',');
		getline(fi, reader.fullname, ',');
		getline(fi, reader.ID, ',');
		getline(fi, reader.DOB, ',');
		getline(fi, reader.sex, ',');
		getline(fi, reader.mail, ',');
		getline(fi, reader.address, ',');
		getline(fi, tmp, '/');
		reader.borr.dd = atoi(tmp.c_str());
		getline(fi, tmp, '/');
		reader.borr.mm = atoi(tmp.c_str());
		getline(fi, tmp, ',');
		reader.borr.yyyy = atoi(tmp.c_str());
		getline(fi, tmp, '/');
		reader.res.dd = atoi(tmp.c_str());
		getline(fi, tmp, '/');
		reader.res.mm = atoi(tmp.c_str());
		getline(fi, tmp);
		reader.res.yyyy = atoi(tmp.c_str());
		p = CreateNodeR(reader);
		AddLR(l, p);
	}
}

bool FindNumber(LISTR &l, string u)
{
	bool bl = false;
	for (NODER *i = l.pHead; i != NULL; i = i->pNext)
		if (u == i->reader.number)
			return false;
	return true;
}

void AddR(LISTR &l, READER reader, READER x, NODER *p, ofstream &fo)
{
	system("cls");
	bool bl = false;
	cin.ignore();
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** INFORMATION READER **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20, 3);
	cout << "Number";
	gotoxy(20, 4);
	cout << "FullName";
	gotoxy(20, 5);
	cout << "ID";
	gotoxy(20, 6);
	cout << "DOB";
	gotoxy(20, 7);
	cout << "Sex";
	gotoxy(20, 8);
	cout << "Email";
	gotoxy(20, 9);
	cout << "Address";
	gotoxy(20, 11);
	cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
	for (int u = 3; u <= 9; u++)
	{
		gotoxy(40, u);
		cout << ":";
	}
	do
	{
		gotoxy(42, 3);
		getline(cin, x.number);
		if (FindNumber(l, x.number) == false)
		{
			system("cls");
			gotoxy(30, 6);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  The Number Has Been Used Before  !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
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
				AddR(l, reader, x, p, fo);
				return;
			}
			cin.ignore();
		}
		else
			bl = true;
	} while (bl == false);
	gotoxy(42, 4);
	getline(cin, x.fullname);
	gotoxy(42, 5);
	getline(cin, x.ID);
	gotoxy(42, 6);
	getline(cin, x.DOB);
	gotoxy(42, 7);
	getline(cin, x.sex);
	gotoxy(42, 8);
	getline(cin, x.mail);
	gotoxy(42, 9);
	getline(cin, x.address);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	x.borr.dd = tm.tm_mday;
	x.borr.mm = tm.tm_mon + 1;
	x.borr.yyyy = tm.tm_year + 1900;
	x.res.dd = x.borr.dd;
	x.res.mm = x.borr.mm;
	x.res.yyyy = x.borr.yyyy + 4;
	p = CreateNodeR(x);
	AddLR(l, p);
	char filename[1000];
	PathDG(filename);
	fo.open(filename);
	for (NODER *i = l.pHead; i != NULL; i = i->pNext)
	{
		fo << i->reader.number << "," << i->reader.fullname << "," << i->reader.ID << "," << i->reader.DOB << "," << i->reader.sex << "," << i->reader.mail << "," << i->reader.address << "," << i->reader.borr.dd << "/" << i->reader.borr.mm << "/" << i->reader.borr.yyyy << "," << i->reader.res.dd << "/" << i->reader.res.mm << "/" << i->reader.res.yyyy;
		if (i != l.pTail)
			fo << endl;
	}
	fo.close();
	gotoxy(30, 10);
	cout << "Add Successfully!!!" << endl;
}

void outputR(LISTR l)
{
	system("cls");
	int k = 1, y = 5;
	for (NODER *i = l.pHead; i != NULL; i = i->pNext)
	{
		gotoxy(0, 2);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** LIST READER IN THE LIBRARY **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(1, 4);
		cout << "STT";
		gotoxy(5, 4);
		cout << "Number";
		gotoxy(12, 4);
		cout << "FullName";
		gotoxy(33, 4);
		cout << "ID";
		gotoxy(45, 4);
		cout << "DOB";
		gotoxy(57, 4);
		cout << "Sex";
		gotoxy(61, 4);
		cout << "Email";
		gotoxy(85, 4);
		cout << "Address";
		gotoxy(100, 4);
		cout << "Begin";
		gotoxy(111, 4);
		cout << "End";
		gotoxy(1, y);
		cout << k;
		gotoxy(5, y);
		cout << i->reader.number << endl;
		gotoxy(12, y);
		cout << i->reader.fullname << endl;
		gotoxy(33, y);
		cout << i->reader.ID << endl;
		gotoxy(45, y);
		cout << i->reader.DOB << endl;
		gotoxy(57, y);
		cout << i->reader.sex << endl;
		gotoxy(61, y);
		cout << i->reader.mail << endl;
		gotoxy(85, y);
		cout << i->reader.address << endl;
		gotoxy(100, y);
		cout << i->reader.borr.dd << "/" << i->reader.borr.mm << "/" << i->reader.borr.yyyy << endl;
		gotoxy(110, y);
		cout << i->reader.res.dd << "/" << i->reader.res.mm << "/" << i->reader.res.yyyy << endl;
		y++;
		k++;
	}
}

void FixR(LISTR &l, READER reader, string x, string y, ifstream &fi, ofstream &fo)
{
	system("cls");
	int k;
	bool bl = false, bll = false;
	READER tmp;
	NODER *p = new NODER;
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** EDIT INFORMATION OF READER **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20, 4);
	cout << "- Please Type Reader's Name Want To Edit: ";
	cin.ignore();
	getline(cin, x);
	for (NODER *i = l.pHead; i != NULL; i = i->pNext)
		if (i->reader.fullname == x)
		{
			bl = true;
			break;
		}
	if (bl == true)
	{
		gotoxy(20, 5);
		cout << "- Please Choose Information Want To Edit !!!" << endl;
		gotoxy(20, 6);
		cout << "1. Number's reader" << endl;
		gotoxy(20, 7);
		cout << "2. Fullname's reader" << endl;
		gotoxy(20, 8);
		cout << "3. ID's reader" << endl;
		gotoxy(20, 9);
		cout << "4. Date of birth" << endl;
		gotoxy(20, 10);
		cout << "5. Sex" << endl;
		gotoxy(20, 11);
		cout << "6. Email" << endl;
		gotoxy(20, 12);
		cout << "7. Address" << endl;
		gotoxy(20, 13);
		cout << "0. Exit" << endl;
		gotoxy(20, 14);
		cout << "Choose Number: [ ] ";
		gotoxy(36, 14);
		cin >> k;
		if (k == 0)
			return;
		cin.ignore();
		for (NODER *i = l.pHead; i != NULL; i = i->pNext)
			if (x == i->reader.fullname)
			{
				tmp.number = i->reader.number;
				tmp.fullname = i->reader.fullname;
				tmp.ID = i->reader.ID;
				tmp.DOB = i->reader.DOB;
				tmp.sex = i->reader.sex;
				tmp.mail = i->reader.mail;
				tmp.address = i->reader.address;
				tmp.borr = i->reader.borr;
				tmp.res = i->reader.res;
				i->reader.fullname = "T";
				if (k == 1)
				{
					do
					{
						gotoxy(20, 16);
						cout << "Your New Information Is Updated: ";
						getline(cin, y);
						if (FindNumber(l, y) == false)
						{
							gotoxy(20, 18);
							cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  The Number Has Been Used Before  !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
							gotoxy(20, 19);
							cout << "0> Exit";
							gotoxy(20, 20);
							cout << "1> Try Again" << endl;
							gotoxy(20, 21);
							cout << "Your choice: [ ]";
							gotoxy(34, 21);
							int v;
							cin >> v;
							if (v == 0)
								return;
							cin.ignore();
							gotoxy(53, 16);
							cout << "                                           ";
							for (int i = 0; i <= 80; i++)
								for (int j = 17; j <= 21; j++)
								{
									gotoxy(i, j);
									cout << " ";
								}

						}
					} while (FindNumber(l, y) == false);
					fixDG(tmp.number, y);
					tmp.number = y;
				}
				else
				{
					gotoxy(20, 16);
					cout << "Your New Information Is Updated: ";
					getline(cin, y);
				}
				if (k == 2)
					tmp.fullname = y;
				if (k == 3)
					tmp.ID = y;
				if (k == 4)
					tmp.DOB = y;
				if (k == 5)
					tmp.sex = y;
				if (k == 6)
					tmp.mail = y;
				if (k == 7)
					tmp.address = y;
				p = CreateNodeR(tmp);
				break;
			}
		char filename[1000];
		PathDG(filename);
		fo.open(filename);
		for (NODER *i = l.pHead; i != NULL; i = i->pNext)
		{
			if (i->reader.fullname == "T")
				fo << p->reader.number << "," << p->reader.fullname << "," << p->reader.ID << "," << p->reader.DOB << "," << p->reader.sex << "," << p->reader.mail << "," << p->reader.address << "," << p->reader.borr.dd << "/" << p->reader.borr.mm << "/" << p->reader.borr.yyyy << "," << p->reader.borr.dd << "/" << p->reader.borr.mm << "/" << p->reader.borr.yyyy;
			else
				fo << i->reader.number << "," << i->reader.fullname << "," << i->reader.ID << "," << i->reader.DOB << "," << i->reader.sex << "," << i->reader.mail << "," << i->reader.address << "," << i->reader.borr.dd << "/" << i->reader.borr.mm << "/" << i->reader.borr.yyyy << "," << i->reader.res.dd << "/" << i->reader.res.mm << "/" << i->reader.res.yyyy;
			if (i != l.pTail)
				fo << endl;
		}
		fi.ignore();
		fo.close();
		gotoxy(30, 17);
		cout << "Edit Successfully!!!" << endl;
	}
	else
	{
		system("cls");
		gotoxy(30, 6);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  Your Request is not available  !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
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
			FixR(l, reader, x, y, fi, fo);
			return;
		}
		cin.ignore();
	}
}

void DelR(LISTR &l, READER reader, string u, ofstream &fo)
{
	int kt = 0;
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** DELETE A READER **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	bool bl = false;
	gotoxy(20, 4);
	cout << "- Please Type Reader's Name Want To Delete: ";
	cin.ignore();
	getline(cin, u);
	for (NODER *i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i->reader.fullname == u)
			bl = true;
	}

	if (bl == true)
	{

		char filename[1000];
		PathDG(filename);
		fo.open(filename);
		if (u == l.pTail->reader.fullname)
		{
			for (NODER *i = l.pHead; i != NULL; i = i->pNext)
			{
				if (i != l.pTail)
				{
					fo << i->reader.number << "," << i->reader.fullname << "," << i->reader.ID << "," << i->reader.DOB << "," << i->reader.sex << "," << i->reader.mail << "," << i->reader.address << "," << i->reader.borr.dd << "/" << i->reader.borr.mm << "/" << i->reader.borr.yyyy << "," << i->reader.res.dd << "/" << i->reader.res.mm << "/" << i->reader.res.yyyy;
					if (i->pNext != l.pTail)
						fo << endl;
				}
				else
					break;
			}
		}
		else
			for (NODER *i = l.pHead; i != NULL; i = i->pNext)
			{
				if (i->reader.fullname != u)
					fo << i->reader.number << "," << i->reader.fullname << "," << i->reader.ID << "," << i->reader.DOB << "," << i->reader.sex << "," << i->reader.mail << "," << i->reader.address << "," << i->reader.borr.dd << "/" << i->reader.borr.mm << "/" << i->reader.borr.yyyy << "," << i->reader.res.dd << "/" << i->reader.res.mm << "/" << i->reader.res.yyyy;
				else
					continue;
				if (i != l.pTail)
					fo << endl;
			}

		fo.close();
		gotoxy(30, 5);
		cout << "Delete Successfully !!!" << endl;
	}
	else
	{
		gotoxy(18, 5);
		cout << "Your request is not available, This User Is not Available !!!" << endl;
	}
}

void FindID(LISTR &l, READER reader, string u)
{
	system("cls");
	bool bl = false;
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** FIND READER BY CODE **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20, 4);
	cout << "- Please Type Reader's CODE, Which You Want To Find: ";
	cin.ignore();
	getline(cin, u);
	for (NODER *i = l.pHead; i != NULL; i = i->pNext)
		if (u == i->reader.number)
		{
			system("cls");
			gotoxy(20, 2);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** INFORMATION OF THIS READER **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			bl = true;
			gotoxy(20, 4);
			cout << "- Number: " << i->reader.number << endl;
			gotoxy(20, 5);
			cout << "- Fullname: " << i->reader.fullname << endl;
			gotoxy(20, 6);
			cout << "- Address: " << i->reader.ID << endl;
			gotoxy(20, 7);
			cout << "- Date of birth: " << i->reader.DOB << endl;
			gotoxy(20, 8);
			cout << "- Sex: " << i->reader.sex << endl;
			gotoxy(20, 9);
			cout << "- Email: " << i->reader.mail << endl;
			gotoxy(20, 10);
			cout << "- Date of Creating Card: " << i->reader.borr.dd << "/" << i->reader.borr.mm << "/" << i->reader.borr.yyyy << endl;
			gotoxy(20, 11);
			cout << "- Time of Limit: " << i->reader.res.dd << "/" << i->reader.res.mm << "/" << i->reader.res.yyyy << endl;
			break;
		}
	if (bl == false)
	{
		gotoxy(30, 6);
		cout << "*****  Your request is not available  *****" << endl;
	}
}

void FindNameR(LISTR &l, READER reader, string u)
{
	;
	bool bl = false;
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** FIND READER BY NAME **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20, 4);
	cout << "- Please Type Book's Name, Which You Want To FIND: ";
	cin.ignore();
	getline(cin, u);
	for (NODER *i = l.pHead; i != NULL; i = i->pNext)
		if (u == i->reader.fullname)
		{
			bl = true;
			system("cls");
			gotoxy(20, 2);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** INFORMATION OF THIS READER **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			gotoxy(20, 4);
			cout << "- Number: " << i->reader.number << endl;
			gotoxy(20, 5);
			cout << "- Fullname: " << i->reader.fullname << endl;
			gotoxy(20, 6);
			cout << "- ID: " << i->reader.ID << endl;
			gotoxy(20, 7);
			cout << "- Date of birth: " << i->reader.DOB << endl;
			gotoxy(20, 8);
			cout << "- Sex: " << i->reader.sex << endl;
			gotoxy(20, 9);
			cout << "- Email: " << i->reader.mail << endl;
			gotoxy(20, 10);
			cout << "- Date of Creating Card: " << i->reader.borr.dd << "/" << i->reader.borr.mm << "/" << i->reader.borr.yyyy << endl;
			gotoxy(20, 11);
			cout << "- Time of Limit: " << i->reader.res.dd << "/" << i->reader.res.mm << "/" << i->reader.res.yyyy << endl;
			break;
		}
	if (bl == false)
	{
		gotoxy(30, 6);
		cout << "*****  Your request is not available *****" << endl;
	}
}

void QLDG(int number)
{
	ifstream fi;
	ofstream fo;
	string u, v;
	bool bl = false;
	LISTR l;
	READER reader, x;
	NODER* p = new NODER;
	NODER* q = new NODER;
	CreateR(l);
	char filename[1000];
	PathDG(filename);
	fi.open(filename);
	ReadR(l, reader, fi, p);
	switch (number)
	{
	case 21:
	{
		outputR(l);
		break;
	}
	case 22:
	{
		AddR(l, reader, x, q, fo);
		break;
	}
	case 23:
	{
		FixR(l, reader, u, v, fi, fo);
		break;
	}
	case 24:
	{
		DelR(l, reader, u, fo);
		break;
	}
	case 25:
	{
		FindID(l, reader, u);
		break;
	}
	case 26:
	{
		FindNameR(l, reader, u);
		break;
	}
	default:
		return;
	}
}