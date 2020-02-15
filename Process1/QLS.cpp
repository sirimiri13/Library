// quanlisach.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "string"
#include "Oxy.h"
#include "fstream"
#include "Total.h"
#include "iostream"

using namespace std;

typedef struct
{
	string ISBN;
	string name;
	string author;
	string pc;
	string py;
	string kind;
	string price;
	string total;
} BOOK;

struct NodeB
{
	BOOK book;
	struct NodeB *pNext;
};
typedef struct NodeB NODEB;

struct ListB
{
	NODEB *pHead;
	NODEB *pTail;
};
typedef struct ListB LISTB;
LISTB l;

void CreateB(LISTB &l)
{
	l.pHead = l.pTail = NULL;
}

NODEB *CreateNodeB(BOOK x)
{
	NODEB *p = new NODEB;
	if (p == NULL)
		return NULL;
	p->book = x;
	p->pNext = NULL;
	return p;
}

void AddL(LISTB &l, NODEB *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void PathDS(char filename[])
{
	wchar_t res[MAX_PATH];
	wstring s;
	s = wstring(res, GetModuleFileName(NULL, res, MAX_PATH));
	string st(s.begin(), s.end());
	st.erase(st.end() - 12, st.end());
	string sl = "DS.txt";
	st = st + sl;
	strcpy(filename, st.c_str());
}

void ReadB(BOOK &book, ifstream &fi, LISTB &l, NODEB *p)
{
	CreateB(l);
	while (fi.eof() == false)
	{
		getline(fi, book.ISBN, ',');
		if (book.ISBN == "")
			break;
		getline(fi, book.name, ',');
		getline(fi, book.author, ',');
		getline(fi, book.pc, ',');
		getline(fi, book.py, ',');
		getline(fi, book.kind, ',');
		getline(fi, book.price, ',');
		fi >> book.total;
		fi.ignore();
		p = CreateNodeB(book);
		AddL(l, p);
	}
}

void out(NODEB *p)
{
	gotoxy(20, 4);
	cout << "ISBN: " << p->book.ISBN << endl;
	gotoxy(20, 5);
	cout << "Book's name: " << p->book.name << endl;
	gotoxy(20, 6);
	cout << "Author: " << p->book.author << endl;
	gotoxy(20, 7);
	cout << "Publishing Company: " << p->book.pc << endl;
	gotoxy(20, 8);
	cout << "Publishing year: " << p->book.py << endl;
	gotoxy(20, 9);
	cout << "Kind: " << p->book.kind << endl;
	gotoxy(20, 10);
	cout << "Price: " << p->book.price << endl;
	gotoxy(20, 11);
	cout << "Total: " << p->book.total << endl;
	gotoxy(20, 13);
	cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
}

void FindISBN(LISTB &l, string x)
{
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** FIND BOOK BY ISBN **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20, 4);
	cout << "- Please Type Book's ID, Which You Want to find: ";
	cin.ignore();
	getline(cin, x);
	bool k = false;
	for (NODEB *i = l.pHead; i != NULL; i = i->pNext)
	{
		if (x == i->book.ISBN)
		{
			system("cls");
			gotoxy(20, 2);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** INFORMATION OF THIS BOOK **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			out(i);
			k = true;
		}
	}
	if (k == false)
	{
		gotoxy(30, 6);
		cout << "*****  Your request is not available  *****" << endl;
	}
}

void FindNameB(LISTB &l, string x)
{
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** FIND BOOK BY NAME **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20, 4);
	cout << "- Please Type Book's Name: ";
	cin.ignore();
	getline(cin, x);
	bool k = false;
	for (NODEB *i = l.pHead; i != NULL; i = i->pNext)
	{
		if (x == i->book.name)
		{
			system("cls");
			gotoxy(20, 2);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** INFORMATION OF THIS BOOK **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
			out(i);
			k = true;
			break;
		}
	}
	if (k == false)
	{
		gotoxy(30, 6);
		cout << "*****  Your request is not available *****" << endl;
	}
}

bool findISBN(LISTB &l, string x)
{
	bool bl = false;
	for (NODEB *i = l.pHead; i != NULL; i = i->pNext)
		if (x == i->book.ISBN)
			return false;
	return true;
}

void FixB(LISTB &l, BOOK book, string tmp, string q, int &d, ifstream &fi, ofstream &fo)
{
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** EDIT INFORMATION **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	bool bl = false;
	BOOK x;
	NODEB *s = new NODEB;
	gotoxy(20, 4);
	cout << "- Please Type Book's Name Want To Edit: ";
	cin.ignore();
	getline(cin, tmp);
	for (NODEB *i = l.pHead; i != NULL; i = i->pNext)
	{
		if (tmp == i->book.name)
		{
			bl = true;
			break;
		}
	}
	if (bl == true)
	{
		gotoxy(20, 6);
		cout << "- Please Choose Any Number Which You Want To Edit !!!" << endl;
		gotoxy(20, 7);
		cout << "1. ISBN" << endl;
		gotoxy(20, 8);
		cout << "2. Name" << endl;
		gotoxy(20, 9);
		cout << "3. Author" << endl;
		gotoxy(20, 10);
		cout << "4. Publishing company" << endl;
		gotoxy(20, 11);
		cout << "5. Publishing year" << endl;
		gotoxy(20, 12);
		cout << "6. Kind" << endl;
		gotoxy(20, 13);
		cout << "7. Price" << endl;
		gotoxy(20, 14);
		cout << "8. Total" << endl;
		gotoxy(20, 15);
		cout << "0. Exit" << endl;
		gotoxy(20, 16);
		cout << "Choose Number: [ ] ";
		gotoxy(36, 16);
		cin >> d;
		if (d == 0)
			return;
		cin.ignore();
		//gotoxy(30, 18);
		//cout << "Info: ";
		//getline(cin, q);
		for (NODEB *i = l.pHead; i != NULL; i = i->pNext)
		{
			if (tmp == i->book.name)
			{

				x.ISBN = i->book.ISBN;
				x.name = i->book.name;
				x.author = i->book.author;
				x.pc = i->book.pc;
				x.py = i->book.py;
				x.kind = i->book.kind;
				x.price = i->book.price;
				x.total = i->book.total;
				i->book.name = "T";
				if (d == 1)
				{
					do
					{
						gotoxy(20, 18);
						cout << "Your New Information Is Updated: ";
						getline(cin, q);
						if (findISBN(l, q) == false)
						{
							gotoxy(20, 20);
							cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  Your Request is not available  !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
							gotoxy(20, 21);
							cout << "0> Exit";
							gotoxy(20, 22);
							cout << "1> Try Again" << endl;
							gotoxy(20, 23);
							cout << "Your choice: [ ]";
							gotoxy(34, 23);
							int v;
							cin >> v;
							if (v == 0)
								return;
							cin.ignore();
							gotoxy(53, 18);
							cout << "                                    ";
							for (int i = 0; i <= 80; i++)
								for (int j = 19; j <= 24; j++)
								{
									gotoxy(i, j);
									cout << " ";
								}
						}
					} while (findISBN(l, q) == false);
					fixDS(x.ISBN, q);
					x.ISBN = q;
				}
				else
				{
					gotoxy(20, 18);
					cout << "Your New Information Is Updated: ";
					getline(cin, q);
				}
				if (d == 2)
					x.name = q;
				if (d == 3)
					x.author = q;
				if (d == 4)
					x.pc = q;
				if (d == 5)
					x.py = q;
				if (d == 6)
					x.kind = q;
				if (d == 7)
					x.price = q;
				if (d == 8)
					x.total = q;
				s = CreateNodeB(x);
			}
			char filename[1000];
			PathDS(filename);
			fo.open(filename);
			for (NODEB *i = l.pHead; i != NULL; i = i->pNext)
			{
				if ((i->book.name) != "T")
					fo << i->book.ISBN << "," << i->book.name << "," << i->book.author << "," << i->book.pc << "," << i->book.py << "," << i->book.kind << "," << i->book.price << "," << i->book.total;
				else
					fo << s->book.ISBN << "," << s->book.name << "," << s->book.author << "," << s->book.pc << "," << s->book.py << "," << s->book.kind << "," << s->book.price << "," << s->book.total;
				if (i != l.pTail)
					fo << endl;
			}
			fi.ignore();
			fo.close();
		}
		gotoxy(30, 20);
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
			FixB(l, book, tmp, q, d, fi, fo);
			return;
		}
		cin.ignore();
	}
}

void DelB(LISTB &l, BOOK book, string u, ifstream &fi, ofstream &fo)
{
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** DELETE A BOOK **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	bool bl = false;
	gotoxy(20, 4);
	cout << "- Please Type Book's Name, Which You Want To Delete: ";
	cin.ignore();
	getline(cin, u);
	for (NODEB *j = l.pHead; j != NULL; j = j->pNext)
		if (j->book.name == u)
		{
			bl = true;
			break;
		}

	if (bl == true)
	{
		char filename[1000];
		PathDS(filename);
		fo.open(filename);
		if (u == l.pTail->book.name)
		{
			for (NODEB *i = l.pHead; i != NULL; i = i->pNext)
			{
				if (i != l.pTail)
				{
					fo << i->book.ISBN << "," << i->book.name << "," << i->book.author << "," << i->book.pc << "," << i->book.py << "," << i->book.kind << "," << i->book.price << "," << i->book.total;
					if (i->pNext != l.pTail)
						fo << endl;
				}
				else
					break;
			}
		}
		else
			for (NODEB *i = l.pHead; i != NULL; i = i->pNext)
			{
				if (i->book.name != u)
				{
					fo << i->book.ISBN << "," << i->book.name << "," << i->book.author << "," << i->book.pc << "," << i->book.py << "," << i->book.kind << "," << i->book.price << "," << i->book.total;
					if (i != l.pTail)
						fo << endl;
				}
				else
					continue;
			}
		fo.close();
		gotoxy(30, 7);
		cout << "Delete Successfully!!!" << endl;
	}
	else
	{
		gotoxy(25, 7);
		cout << "*****  Your request is not available  ******" << endl;
	}
}

bool FindID(LISTB &l, string x)
{
	bool k = false;
	for (NODEB *i = l.pHead; i != NULL; i = i->pNext)
		if (x == i->book.ISBN)
			return false;
	return true;
}

void AddB(LISTB &l, BOOK book, BOOK &x, ifstream &fi, ofstream &fo)
{
	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** INFORMATION OF THE NEW BOOK **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20, 3);
	cout << "ISBN";
	gotoxy(20, 4);
	cout << "Book's name";
	gotoxy(20, 5);
	cout << "Author";
	gotoxy(20, 6);
	cout << "Publishing company";
	gotoxy(20, 7);
	cout << "Publishing year";
	gotoxy(20, 8);
	cout << "Kind";
	gotoxy(20, 9);
	cout << "Price";
	gotoxy(20, 10);
	cout << "Total";
	gotoxy(20, 12);
	cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
	for (int u = 3; u <= 10; u++)
	{
		gotoxy(40, u);
		cout << ":";
	}
	bool bl = false;
	do
	{
		gotoxy(42, 3);
		cin >> x.ISBN;
		if (FindID(l, x.ISBN) == false)
		{
			system("cls");
			gotoxy(30, 6);
			cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2 !!!!  IBSN Has Been Used Before  !!! \xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
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
				AddB(l, book, x, fi, fo);
				return;
			}
			cin.ignore();
		}
		else
			bl = true;
	} while (bl == false);
	gotoxy(42, 4);
	cin.ignore();
	getline(cin, x.name);
	gotoxy(42, 5);
	getline(cin, x.author);
	gotoxy(42, 6);
	getline(cin, x.pc);
	gotoxy(42, 7);
	getline(cin, x.py);
	gotoxy(42, 8);
	getline(cin, x.kind);
	gotoxy(42, 9);
	getline(cin, x.price);
	gotoxy(42, 10);
	getline(cin, x.total);
	NODEB *p = CreateNodeB(x);
	AddL(l, p);
	char filename[1000];
	PathDS(filename);
	fo.open(filename);
	for (NODEB *i = l.pHead; i != NULL; i = i->pNext)
	{
		fo << i->book.ISBN << "," << i->book.name << "," << i->book.author << "," << i->book.pc << "," << i->book.py << "," << i->book.kind << "," << i->book.price << "," << i->book.total;
		if (i != l.pTail)
			fo << endl;
	}
	fi.ignore();
	fo.close();
	fi.close();
	gotoxy(30, 11);
	cout << "Add Successfully!!!" << endl;
	return;
}

void output(ListB l)
{
	system("cls");
	int j = 1, y = 5;
	for (NODEB *p = l.pHead; p != NULL; p = p->pNext)
	{
		gotoxy(0, 2);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** LIST BOOK IN THE LIBRARY **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(1, 4);
		cout << "STT";
		gotoxy(5, 4);
		cout << "ISBN";
		gotoxy(11, 4);
		cout << "BOOK's name";
		gotoxy(40, 4);
		cout << "Author";
		gotoxy(60, 4);
		cout << "Producer";
		gotoxy(77, 4);
		cout << "Born";
		gotoxy(87, 4);
		cout << "Kind";
		gotoxy(102, 4);
		cout << "Price";
		gotoxy(112, 4);
		cout << "Total";
		gotoxy(1, y);
		cout << j;
		gotoxy(5, y);
		cout << p->book.ISBN << endl;
		gotoxy(11, y);
		cout << p->book.name << endl;
		gotoxy(40, y);
		cout << p->book.author << endl;
		gotoxy(60, y);
		cout << p->book.pc << endl;
		gotoxy(77, y);
		cout << p->book.py << endl;
		gotoxy(87, y);
		cout << p->book.kind << endl;
		gotoxy(102, y);
		cout << p->book.price << endl;
		gotoxy(112, y);
		cout << p->book.total << endl;
		y++;
		j++;
	}
}

void QLS(int number)
{
	string u, v;
	int n, k, d;
	BOOK x, book;
	LISTB l;
	NODEB *p = new NODEB;
	CreateB(l);
	ifstream fi;
	ofstream fo;
	char filename[1000];
	PathDS(filename);
	fi.open(filename);
	ReadB(book, fi, l, p);
	switch (number)
	{
	case 31:
	{
		output(l);
		break;
	}
	case 32:
	{
		AddB(l, book, x, fi, fo);
		break;
	}
	case 33:
	{
		FixB(l, book, u, v, d, fi, fo);
		break;
	}
	case 34:
	{
		DelB(l, book, u, fi, fo);
		break;
	}
	case 35:
	{
		FindISBN(l, u);
		break;
	}
	case 36:
	{
		FindNameB(l, u);
		break;
	}
defaut:
	return;
	}
}