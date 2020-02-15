// thongke.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fstream"
#include "Oxy.h"
#include "string"
#include "iostream"
#include "QLDG.h"
#include "QLS.h"
#include "windows.h"
#include "time.h"
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

struct listB
{
	NODEB *pHead;
	NODEB *pTail;
};
typedef struct listB LISTB;
LISTB l;

void createB(LISTB &l)
{
	l.pHead = l.pTail = NULL;
}

NODEB *createNodeB(BOOK x)
{
	NODEB *p = new NODEB;
	if (p == NULL)
		return NULL;
	p->book = x;
	p->pNext = NULL;
	return p;
}

void addL(LISTB &l, NODEB *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void readB(BOOK &book, ifstream &fi, LISTB &l, NODEB *p)
{
	createB(l);
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
		getline(fi, book.total);
		//		fi.ignore();
		p = createNodeB(book);
		addL(l, p);
	}
}

int NOB(LISTB &lb, BOOK book)
{
	int sum = 0;
	NODEB *p = lb.pHead;
	while (p != NULL)
	{
		sum += atoi(p->book.total.c_str());
		p = p->pNext;
	}
	return sum;
}

void kindbook(LISTB lb, BOOK book)
{
	int ch[1000], d[1000], res[1000], n = 0, u = 0, v, count = 0;
	string sl[1000];
	int tmp;
	int dem = 0;
	for (NODEB *i = lb.pHead; i != NULL; i = i->pNext)
	{
		n++;
		ch[n] = 0;
		d[n] = 0;
	}
	for (NODEB *i = lb.pHead; i != NULL; i = i->pNext)
	{
		u++; v = 0;
		bool bl = false;
		if (ch[u] != 0)
			continue;
		dem++;
		sl[dem] = i->book.kind;
		for (NODEB *j = lb.pHead; j != NULL; j = j->pNext)
		{
			v++;
			if (ch[v] != 0)
				continue;
			if (i->book.kind == j->book.kind)
			{
				ch[v] = dem;
			}
		}
	}
	for (int i = 1; i <= dem; i++)
	{
		int j = 0;
		for (NODEB *k = lb.pHead; k != NULL; k = k->pNext)
		{
			j++;
			tmp = atoi(k->book.total.c_str());
			if (i == ch[j])
				d[i] += tmp;
		}
	}
	int y = 5;
	for (int i = 1; i <= dem; i++)
	{
		gotoxy(20, y);
		cout << "- Kind: " << sl[i];
		gotoxy(45, y);
		cout << "- Total: " << d[i] << endl;
		y++;
	}
}

///////////////////////////////////

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
LISTR l2;

void createR(LISTR &l2)
{
	l2.pHead = l2.pTail = NULL;
}

NODER *createNodeR(READER x)
{
	NODER *p = new NODER;
	if (p == NULL)
		return NULL;
	p->reader = x;
	p->pNext = NULL;
	return p;
}

void addLR(LISTR &l, NODER *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void readR(LISTR &l, READER &reader, ifstream &fi, NODER *p)
{
	string tmp;
	createR(l);
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
		p = createNodeR(reader);
		addLR(l, p);
	}
}

int NOR(LISTR l2, READER reader)
{
	NODER *p;
	int sum = 0;
	p = l2.pHead;
	while (p != NULL)
	{
		sum++;
		p = p->pNext;
	}
	return sum;
}

void SOR(LISTR l2, READER reader)
{
	int a[2];
	int dm = 0, dn = 0;
	for (NODER *i = l2.pHead; i != NULL; i = i->pNext)
	{
		if (i->reader.sex == "Nam")
		{
			dm++;
			a[0] = dm;
		}
		else
			if (i->reader.sex == "Nu")
			{
				dn++;
				a[1] = dn;
			}
	}
	gotoxy(20, 5);
	cout << "_ Total Male Reader In The Library: " << a[0] << endl;
	gotoxy(20, 6);
	cout << "- Total Female Reader In The Library: " << a[1] << endl;
}

////////////////////////////////////////////////////////////

void PathBO(char filename[])
{
	wchar_t res[MAX_PATH];
	wstring s;
	s = wstring(res, GetModuleFileName(NULL, res, MAX_PATH));
	string st(s.begin(), s.end());
	st.erase(st.end() - 12, st.end());
	string sl = "BORROW.txt";
	st = st + sl;
	strcpy(filename, st.c_str());
}

typedef struct
{
	string MDG;
	date borr;
	date gures;
	string s[4];
} BO;

date count(date borr)
{
	bool bl = true;
	++borr.dd;
	switch (borr.mm)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case  12:
	{
		if (borr.dd > 31)
			bl = false;
		break;
	}
	case 4: case 6: case 9: case 11:
	{
		if (borr.dd > 30)
			bl = false;
		break;
	}
	case 2:
	{
		if (((borr.yyyy % 4 == 0) && (borr.yyyy % 100 != 0)) || (borr.yyyy % 400 == 0))
		{
			if (borr.dd > 29)
				bl = false;
		}
		else
		{
			if (borr.dd > 28)
				bl = false;
			break;
		}
	}
	}
	if (bl == false)
	{
		++borr.mm;
		borr.dd = 1;
	}
	if (borr.mm >12)
	{
		borr.mm = 1;
		++borr.yyyy;
	}
	date res;
	res.dd = borr.dd;
	res.mm = borr.mm;
	res.yyyy = borr.yyyy;
	return res;
}

struct Nodebo
{
	BO bo;
	struct Nodebo *pNext;
};
typedef struct Nodebo NODEBO;

struct Listbo
{
	NODEBO *pHead;
	NODEBO *pTail;
};
typedef struct Listbo LISTBO;
LISTBO lbr;

void CreateLBo(LISTBO &lbr)
{
	lbr.pHead = lbr.pTail = NULL;
}

void Addbo(LISTBO &l, NODEBO *p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

NODEBO *CreateNodeBo(BO x)
{
	NODEBO *p = new NODEBO;
	if (p == NULL)
		return NULL;
	p->bo = x;
	p->pNext = NULL;
	return p;
}

void ReadBo(BO &bo, ifstream &fi, LISTBO &lbr)
{
	int k = 0;
	string tmp;
	CreateLBo(lbr);
	while (fi.eof() == false)
	{
		getline(fi, bo.MDG, ',');
		getline(fi, tmp, '/');
		bo.borr.dd = atoi(tmp.c_str());
		getline(fi, tmp, '/');
		bo.borr.mm = atoi(tmp.c_str());
		getline(fi, tmp, ',');
		bo.borr.yyyy = atoi(tmp.c_str());
		getline(fi, tmp, '/');
		bo.gures.dd = atoi(tmp.c_str());
		getline(fi, tmp, '/');
		bo.gures.mm = atoi(tmp.c_str());
		getline(fi, tmp, ',');
		bo.gures.yyyy = atoi(tmp.c_str());
		getline(fi, tmp);
		int n = strlen(tmp.c_str());
		k = 1;
		for (int j = 0; j < n; j++)
		{
			if (tmp[j] == ',')
				k++;
			else
				bo.s[k] += tmp[j];
		}
		NODEBO* p = CreateNodeBo(bo);
		Addbo(lbr, p);
		for (int i = 1; i <= k; i++)
			bo.s[i].clear();
	}
	fi.close();
}

int totalborr(LISTBO lbr)
{
	int dem = 0;
	NODEBO *p = lbr.pHead;
	while (p != NULL)
	{
		int n = 1;
		while (n <= 3)
		{
			if (p->bo.s[n] != "")
				dem++;
			n++;
		}
		p = p->pNext;
	}
	return dem;
}

////////////////////////////////////////////////////////////////

bool findnumber(LISTR &l, string u)
{
	for (NODER *i = l.pHead; i != NULL; i = i->pNext)
		if (u == i->reader.number)
			return true;
	return false;
}

bool findisbn(LISTB &l, string x)
{
	for (NODEB *i = l.pHead; i != NULL; i = i->pNext)
		if (x == i->book.ISBN)
			if (atoi(i->book.total.c_str()) >= 1)
				return true;
	return false;
}

void BORR(LISTBO &lbr, LISTR &lr, LISTB &lb, BOOK book, READER reader, ifstream &fi)
{
	system("cls");
	BO a;
	ofstream fo;
	char filename[1000];
	bool bl = false;
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Borrow Book Tag \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	do
	{
		gotoxy(20, 4);
		cout << "Please type Code of reader: ";
		getline(cin, a.MDG);
		NODER *r = new NODER;
		PathDG(filename);
		fi.open(filename);
		readR(lr, reader, fi, r);
		fi.close();
		if (findnumber(lr, a.MDG) == false)
		{
			gotoxy(20, 6);
			cout << "           *** Not found This Code ***" << endl;
			gotoxy(20, 7);
			cout << "- Click 1 To Try Again Or Click 0 To Exit ... : [ ]";
			int v;
			gotoxy(69, 7);
			cin >> v;
			cin.ignore();
			if (v == 0)
				return;
			else
			{
				BORR(lbr, lr, lb, book, reader, fi);
				return;
			}
		}
		else
			bl = true;
	} while (bl == false);

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	a.borr.dd = tm.tm_mday;
	a.borr.mm = tm.tm_mon + 1;
	a.borr.yyyy = tm.tm_year + 1900;
	date tt = a.borr;
	for (int i = 1; i <= 7; i++)
	{
		date tmp = tt;
		tt = count(tmp);
	}
	a.gures = tt;
	int d, sum, k, sums = 0, ss = 0;
	BO bo;
	PathBO(filename);
	fi.open(filename);
	ReadBo(bo, fi, lbr);
	fi.close();
	for (NODEBO *j = lbr.pHead; j != NULL; j = j->pNext)
	{
		if (j->bo.MDG == a.MDG)
			ss++;
	}
	int dem = 0;
	for (NODEBO *j = lbr.pHead; j != NULL; j = j->pNext)
	{
		if (j->bo.MDG == a.MDG)
		{
			int u = 1;
			while (u <= 3)
			{
				if (j->bo.s[u] != "")
					dem++;
				u++;
			}
			sum = 3 - dem;
			sums++;
		}
		if (sums == ss)
			break;
	}
	if (sum == 0)
	{
		gotoxy(20, 6);
		cout << "-> You borrowed enough books. You can not borrow anymore" << endl;
		return;
	}
	else
		if (sum == 1)
		{
			gotoxy(30, 6);
			cout << "-> You can borrow 1 book";
			d = 1;
		}
		else
			if (sum == 2)
			{
				gotoxy(30, 6);
				cout << "-> You can borrow 1 book to 2 books" << endl;
				gotoxy(30, 7);
				cout << "- Please type total books want to borrow: ";
				cin >> d;
			}
			else
			{
				gotoxy(20, 6);
				cout << "-> You can borrow from 1 book to 3 books" << endl;
				gotoxy(20, 7);
				cout << "- Please type total books want to borrow: ";
				cin >> d;
			}


	cin.ignore();
	NODEB *q = new NODEB;
	PathDS(filename);
	fi.open(filename);
	readB(book, fi, lb, q);
	fi.close();
	int z = 0;
	for (int i = 0; i < d; i++)
	{
		do
		{
			bl = false;
			gotoxy(20, 9 + z);
			cout << "Please type book's ISBN want to borrow: ";
			getline(cin, a.s[i]);
			if (findisbn(lb, a.s[i]) == false)
			{
				gotoxy(20, 10 + z);
				cout << "    **** Not Found This Book ****" << endl;
				gotoxy(20, 11 + z);
				cout << "Click 1 To Try Again Or Click 0 To Exit ... : [ ]";
				int v;
				gotoxy(67, 11 + z);
				cin >> v;
				cin.ignore();
				if (v == 0)
					return;
				else
				{
					gotoxy(60, 9 + z);
					cout << "                                                    ";
					for (int i = 0; i <= 80; i++)
						for (int j = 10 + z; j <= 11 + z; j++)
						{
							gotoxy(i, j);
							cout << " ";
						}
				}
			}
			else
				bl = true;
			if (bl == true)
			{
				gotoxy(20, 10 + z);
				z += 2;
				cout << "**** You Borrowed Successfully ****";
				for (NODEB *j = lb.pHead; j != NULL; j = j->pNext)
					if (j->book.ISBN == a.s[i])
					{
						int sl = atoi(j->book.total.c_str());
						sl = sl - 1;
						j->book.total = to_string(sl);
						break;
					}
			}
		} while (bl == false);
	}
	PathDS(filename);
	fo.open(filename);
	for (NODEB *j = lb.pHead; j != NULL; j = j->pNext)
	{
		fo << j->book.ISBN << "," << j->book.name << "," << j->book.author << "," << j->book.pc << "," << j->book.py << "," << j->book.kind << "," << j->book.price << "," << j->book.total;
		if (j != lb.pTail)
			fo << endl;
	}
	fi.ignore();
	fo.close();

	system("cls");
	gotoxy(20, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Your Book Tag \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
	gotoxy(20, 4);
	cout << "- Number of reader: " << a.MDG << endl;
	gotoxy(20, 5);
	cout << "- Borrow date: " << a.borr.dd << "/" << a.borr.mm << "/" << a.borr.yyyy << endl;
	gotoxy(20, 6);
	cout << "- Expected return date: " << a.gures.dd << "/" << a.gures.mm << "/" << a.gures.yyyy << endl;
	int y = 7;
	for (int i = 0; i < d; i++)
	{
		for (NODEB *j = lb.pHead; j != NULL; j = j->pNext)
			if (a.s[i] == j->book.ISBN)
			{
				gotoxy(20, y);
				cout << "Name of Book Which You Borrowed: " << j->book.ISBN << " - " << j->book.name << endl;
				y++;
			}

	}
	NODEBO *p = CreateNodeBo(a);
	Addbo(lbr, p);
	PathBO(filename);
	fo.open(filename);
	for (NODEBO *i = lbr.pHead; i != NULL; i = i->pNext)
	{
		fo << i->bo.MDG << "," << i->bo.borr.dd << "/" << i->bo.borr.mm << "/" << i->bo.borr.yyyy << "," << i->bo.gures.dd << "/" << i->bo.gures.mm << "/" << i->bo.gures.yyyy << ",";
		for (int j = 1; j <= 3; j++)
		{
			fo << i->bo.s[j];
			if (j == 3)
				break;
			if (i->bo.s[j + 1] == "")
				break;
			fo << ",";
		}
		if (i != lbr.pTail)
			fo << endl;
	}
	fo.close();
}

/////////////////////////////////////////////////////////////////

typedef struct
{
	string s;
	string s1;
	date ntn;
}gb;

void Giveback(LISTBO &lbr, LISTR &lr, LISTB &lb, BOOK book, READER reader, ifstream &fi)
{
	gb m[4];
	int k = 0;
	char filename[1000];
	bool bl = false;
	string s1, s;
	gotoxy(0, 2);
	cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Click 1 to continue, Click 2 if reader lost our book or Click 0 to exit \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	//cout << "Click 1 to continue, Click 2 if reader lost our books, or Click 0 to exit .... : ";
	int v;
	gotoxy(35, 4);
	cout << "----------Your Choose [ ]----------";
	gotoxy(58, 4);
	cin >> v;
	cin.ignore();
	if (v == 0)
		return;
	if (v == 2)
	{
		do
		{
			gotoxy(20, 6);
			cout << "- Please type reader's code who lost the book: ";
			getline(cin, s1);
			NODER *r = new NODER;
			PathDG(filename);
			fi.open(filename);
			readR(lr, reader, fi, r);
			fi.close();
			if (findnumber(lr, s1) == false)
			{
				gotoxy(35, 8);
				cout << "Not found this code" << endl;
				gotoxy(35, 9);
				cout << "Click 1 to try again or click 0 to exit ... : ";
				int v;
				cin >> v;
				if (v == 0)
					return;
				else
				{
					gotoxy(67, 6);
					cout << "                                                                    ";
					for (int i = 0; i<100; i++)
						for (int j = 7; j <= 9; j++)
						{
							gotoxy(i, j);
							cout << " ";
						}
				}
				cin.ignore();
			}
			else
				bl = true;
		} while (bl == false);

		PathBO(filename);
		fi.open(filename);
		BO bo;
		ReadBo(bo, fi, lbr);
		fi.close();

		int y = 9;
		for (NODEBO *i = lbr.pHead; i != NULL; i = i->pNext)
			if (i->bo.MDG == s1)
			{
				bl = true;
				gotoxy(20, 8);
				cout << "On             ISBN      Book's name";
				//cout << "On " << i->bo.borr.dd << "/" << i->bo.borr.mm << "/" << i->bo.borr.yyyy << ", Reader borrowed: " << endl;
				gotoxy(20, y);
				cout << i->bo.borr.dd << "/" << i->bo.borr.mm << "/" << i->bo.borr.yyyy;
				for (int j = 1; j <= 3; j++)
				{
					if (i->bo.s[j] == "")
						break;
					PathDS(filename);
					fi.open(filename);
					NODEB *p = new NODEB;
					readB(book, fi, lb, p);
					fi.close();
					for (NODEB *u = lb.pHead; u != NULL; u = u->pNext)
						if (i->bo.s[j] == u->book.ISBN)
						{
							k++;
							m[k].s = u->book.name;
							m[k].s1 = u->book.ISBN;
							m[k].ntn.dd = i->bo.borr.dd;
							m[k].ntn.mm = i->bo.borr.mm;
							m[k].ntn.yyyy = i->bo.borr.yyyy;
							break;
						}
					gotoxy(35, y);
					//cout << i->bo.s[j] << "   " << m[k].s << endl;
					cout << i->bo.s[j];
					gotoxy(45, y);
					cout << m[k].s;
					y++;
				}
			}
		//cout << endl;
		gotoxy(20, 10 + k);
		cout << "- Please type book's code that reader lost: ";
		getline(cin, s);
		PathDS(filename);
		fi.open(filename);
		NODEB *p = new NODEB;
		readB(book, fi, lb, p);
		fi.close();
		int res;
		for (NODEB *i = lb.pHead; i != NULL; i = i->pNext)
			if (i->book.ISBN == s)
			{
				res = atoi(i->book.price.c_str());
				gotoxy(20, 11 + k);
				cout << "- You must pay: " << 2 * res << " dong" << endl;
				break;
			}

		PathBO(filename);
		fi.open(filename);
		ReadBo(bo, fi, lbr);
		for (NODEBO *u = lbr.pHead; u != NULL; u = u->pNext)
			if (u->bo.MDG == s1)
			{
				if (s == u->bo.s[1])
				{
					u->bo.s[1] = "";
					if (u->bo.s[1] == "")
					{
						u->bo.s[1] = u->bo.s[2];
						u->bo.s[2] = "";
					}
					if (u->bo.s[2] == "")
					{
						u->bo.s[2] = u->bo.s[3];
						u->bo.s[3] = "";
					}
					break;
				}
				if (s == u->bo.s[2])
				{
					u->bo.s[2] = "";
					if (u->bo.s[1] == "")
					{
						u->bo.s[1] = u->bo.s[2];
						u->bo.s[2] = "";
					}
					if (u->bo.s[2] == "")
					{
						u->bo.s[2] = u->bo.s[3];
						u->bo.s[3] = "";
					}
					break;
				}
				if (s == u->bo.s[3])
				{
					u->bo.s[3] = "";
					if (u->bo.s[1] == "")
					{
						u->bo.s[1] = u->bo.s[2];
						u->bo.s[2] = "";
					}
					if (u->bo.s[2] == "")
					{
						u->bo.s[2] = u->bo.s[3];
						u->bo.s[3] = "";
					}
					break;
				}
			}
		ofstream fo;
		PathBO(filename);
		fo.open(filename);
		for (NODEBO* u = lbr.pHead; u != NULL; u = u->pNext)
			if (u->bo.s[1] != "")
			{
				fo << u->bo.MDG << "," << u->bo.borr.dd << "/" << u->bo.borr.mm << "/" << u->bo.borr.yyyy << "," << u->bo.gures.dd << "/" << u->bo.gures.mm << "/" << u->bo.gures.yyyy << ",";
				for (int i = 1; i <= 3; i++)
				{
					fo << u->bo.s[i];
					if (i == 3)
						break;
					if (u->bo.s[i + 1] == "")
						break;
					fo << ",";
				}
				if (u != lbr.pTail)
					fo << endl;
			}
		return;
	}
	bl = false;
	do
	{
		gotoxy(20, 6);
		cout << "Please type reader's code, reader want to give book back: ";
		getline(cin, s1);
		NODER *r = new NODER;
		PathDG(filename);
		fi.open(filename);
		readR(lr, reader, fi, r);
		fi.close();
		if (findnumber(lr, s1) == false)
		{
			gotoxy(35, 8);
			cout << "Not found this code" << endl;
			gotoxy(35, 9);
			cout << "Click 1 to try again or click 0 to exit ... : ";
			int v;
			cin >> v;
			if (v == 0)
				return;
			else
			{
				gotoxy(78, 6);
				cout << "                                                                      ";
				for (int i = 0; i < 100; i++)
					for (int j = 7; j <= 9; j++)
					{
						gotoxy(i, j);
						cout << "  ";
					}
			}
			cin.ignore();
		}
		else
			bl = true;
	} while (bl == false);
	BO bo;
	string s2, s3;
	PathBO(filename);
	fi.open(filename);
	ReadBo(bo, fi, lbr);
	fi.close();
	bl = false;
	int y = 9;
	for (NODEBO *i = lbr.pHead; i != NULL; i = i->pNext)
		if (i->bo.MDG == s1)
		{
			bl = true;
			gotoxy(20, 8);
			cout << "On             ISBN      Book's Name ";
			gotoxy(20, y);
			cout << i->bo.borr.dd << "/" << i->bo.borr.mm << "/" << i->bo.borr.yyyy;
			//cout << "On " << i->bo.borr.dd << "/" << i->bo.borr.mm << "/" << i->bo.borr.yyyy << ", Reader borrowed: " << endl;
			for (int j = 1; j <= 3; j++)
			{
				if (i->bo.s[j] == "")
					break;
				PathDS(filename);
				fi.open(filename);
				NODEB *p = new NODEB;
				readB(book, fi, lb, p);
				fi.close();
				for (NODEB *u = lb.pHead; u != NULL; u = u->pNext)
					if (i->bo.s[j] == u->book.ISBN)
					{
						k++;
						m[k].s = u->book.name;
						m[k].s1 = u->book.ISBN;
						m[k].ntn.dd = i->bo.borr.dd;
						m[k].ntn.mm = i->bo.borr.mm;
						m[k].ntn.yyyy = i->bo.borr.yyyy;
						break;
					}
				gotoxy(35, y);
				cout << i->bo.s[j];
				gotoxy(45, y);
				cout << m[k].s;
				y++;
				//cout << i->bo.s[j] << "   " << m[k].s << endl;
			}
		}
	int number, dem;
	date x;
	number = 1;
	for (int i = 1; i <= number; i++)
	{
		gotoxy(20, 11 + k);
		cout << "Type book's code: ";
		getline(cin, s3);
		for (int j = 1; j <= k; j++)
			if (s3 == m[j].s1)
			{
				dem = 0;
				bool bl = true;
				time_t t = time(NULL);
				struct tm tm = *localtime(&t);
				x.dd = tm.tm_mday;
				x.mm = tm.tm_mon + 1;
				x.yyyy = tm.tm_year + 1900;
				date tmp = m[j].ntn;
				while (1 == 1)
				{
					dem++;
					tmp = count(tmp);
					if (tmp.dd == x.dd && tmp.mm == x.mm && tmp.yyyy == x.yyyy)
						break;
				}
				if (dem > 7)
				{
					gotoxy(30, 12 + k);
					cout << "- You must pay: " << (dem - 7) * 5000 << " dong" << endl;
				}
				else
				{
					gotoxy(30, 12 + k);
					cout << "You must pay: 0 dong" << endl;
				}
				for (NODEBO *u = lbr.pHead; u != NULL; u = u->pNext)
					if (u->bo.MDG == s1)
					{
						if (s3 == u->bo.s[1])
						{
							u->bo.s[1] = "";
							if (u->bo.s[1] == "")
							{
								u->bo.s[1] = u->bo.s[2];
								u->bo.s[2] = "";
							}
							if (u->bo.s[2] == "")
							{
								u->bo.s[2] = u->bo.s[3];
								u->bo.s[3] = "";
							}
							break;
						}
						if (s3 == u->bo.s[2])
						{
							u->bo.s[2] = "";
							if (u->bo.s[1] == "")
							{
								u->bo.s[1] = u->bo.s[2];
								u->bo.s[2] = "";
							}
							if (u->bo.s[2] == "")
							{
								u->bo.s[2] = u->bo.s[3];
								u->bo.s[3] = "";
							}
							break;
						}
						if (s3 == u->bo.s[3])
						{
							u->bo.s[3] = "";
							if (u->bo.s[1] == "")
							{
								u->bo.s[1] = u->bo.s[2];
								u->bo.s[2] = "";
							}
							if (u->bo.s[2] == "")
							{
								u->bo.s[2] = u->bo.s[3];
								u->bo.s[3] = "";
							}
							break;
						}
					}
				for (NODEB *u = lb.pHead; u != NULL; u = u->pNext)
					if (u->book.ISBN == s3)
					{
						int sl = atoi(u->book.total.c_str());
						sl = sl + 1;
						u->book.total = to_string(sl);
						break;
					}
			}
	}
	ofstream fo;
	PathBO(filename);
	fo.open(filename);
	for (NODEBO *u = lbr.pHead; u != NULL; u = u->pNext)
		if (u->bo.s[1] != "")
		{
			fo << u->bo.MDG << "," << u->bo.borr.dd << "/" << u->bo.borr.mm << "/" << u->bo.borr.yyyy << "," << u->bo.gures.dd << "/" << u->bo.gures.mm << "/" << u->bo.gures.yyyy << ",";
			for (int i = 1; i <= 3; i++)
			{
				fo << u->bo.s[i];
				if (i == 3)
					break;
				if (u->bo.s[i + 1] == "")
					break;
				fo << ",";
			}
			if (u != lbr.pTail)
				fo << endl;
		}
	fo.close();
	PathDS(filename);
	fo.open(filename);
	for (NODEB *j = lb.pHead; j != NULL; j = j->pNext)
	{
		fo << j->book.ISBN << "," << j->book.name << "," << j->book.author << "," << j->book.pc << "," << j->book.py << "," << j->book.kind << "," << j->book.price << "," << j->book.total;
		if (j != lb.pTail)
			fo << endl;
	}
	fo.close();
}

void thongke(LISTBO &lbr, LISTR &l2, READER reader, ifstream &fi)
{
	char filename[1000];
	date x;
	BO bo;
	time_t t = time(NULL);
	NODER *p = new NODER;
	struct tm tm = *localtime(&t);
	x.dd = tm.tm_mday;
	x.mm = tm.tm_mon + 1;
	x.yyyy = tm.tm_year + 1900;
	PathBO(filename);
	fi.open(filename);
	ReadBo(bo, fi, lbr);
	fi.close();
	PathDG(filename);
	fi.open(filename);
	readR(l2, reader, fi, p);
	int y = 4;
	for (NODEBO *i = lbr.pHead; i != NULL; i = i->pNext)
	{

		date tmp = i->bo.borr;
		int dem = 0;
		while (1 == 1)
		{
			dem++;
			tmp = count(tmp);
			if (tmp.dd == x.dd && tmp.mm == x.mm && tmp.yyyy == x.yyyy)
				break;
		}
		if (dem > 7)
		{
			for (NODER *u = l2.pHead; u != NULL; u = u->pNext)
			{
				gotoxy(20, 4);
				cout << "STT            Full Name";
				if (u->reader.number == i->bo.MDG)
				{
					y++;
					gotoxy(20, y);
					cout << y - 4;
					gotoxy(35, y);
					cout << u->reader.fullname << endl;
					break;
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////

void fixDG(string st, string sl)
{
	ifstream fi;
	ofstream fo;
	BO bo;
	LISTBO lbr;
	char filename[1000];
	PathBO(filename);
	fi.open(filename);
	ReadBo(bo, fi, lbr);
	fi.close();
	for (NODEBO *i = lbr.pHead; i != NULL; i = i->pNext)
		if (i->bo.MDG == st)
			i->bo.MDG = sl;
	fo.open(filename);
	for (NODEBO *i = lbr.pHead; i != NULL; i = i->pNext)
	{
		fo << i->bo.MDG << "," << i->bo.borr.dd << "/" << i->bo.borr.mm << "/" << i->bo.borr.yyyy << "," << i->bo.gures.dd << "/" << i->bo.gures.mm << "/" << i->bo.gures.yyyy << ",";
		for (int j = 1; j <= 3; j++)
		{
			fo << i->bo.s[j];
			if (j == 3)
				break;
			if (i->bo.s[j + 1] == "")
				break;
			fo << ",";
		}
		if (i != lbr.pTail)
			fo << endl;
	}
	fo.close();
}

void fixDS(string st, string sl)
{
	ifstream fi;
	ofstream fo;
	BO bo;
	LISTBO lbr;
	char filename[1000];
	PathBO(filename);
	fi.open(filename);
	ReadBo(bo, fi, lbr);
	fi.close();
	for (NODEBO *i = lbr.pHead; i != NULL; i = i->pNext)
	{
		for (int j = 1; j <= 3; j++)
			if (i->bo.s[j] == st)
				i->bo.s[j] = sl;
	}
	fo.open(filename);
	for (NODEBO *i = lbr.pHead; i != NULL; i = i->pNext)
	{
		fo << i->bo.MDG << "," << i->bo.borr.dd << "/" << i->bo.borr.mm << "/" << i->bo.borr.yyyy << "," << i->bo.gures.dd << "/" << i->bo.gures.mm << "/" << i->bo.gures.yyyy << ",";
		for (int j = 1; j <= 3; j++)
		{
			fo << i->bo.s[j];
			if (j == 3)
				break;
			if (i->bo.s[j + 1] == "")
				break;
			fo << ",";
		}
		if (i != lbr.pTail)
			fo << endl;
	}
	fo.close();

}

/////////////////////////////////////////////////////////////////
void Total(int number)
{
	cin.ignore();
	system("cls");
	LISTB l1;
	LISTR l2;
	LISTBO l3;
	BOOK book;
	READER reader;
	BO bo;
	NODEB *p = new NODEB;
	NODER *q = new NODER;
	NODEBO *r = new NODEBO;
	ifstream fi;
	int sum;
	char filename[1000];
	switch (number)
	{
	case 61:
	{

		PathDS(filename);
		fi.open(filename);
		readB(book, fi, l1, p);
		sum = NOB(l1, book);
		gotoxy(20, 2);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** Book statistics **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(20, 4);
		cout << "Total Book In The Library: " << sum << endl;
		kindbook(l1, book);
		fi.close();
		break;
	}
	/*case 62:
	{
	PathDS(filename);
	fi.open(filename);
	readB(book, fi, l1, p);
	kindbook(l1, book);
	fi.close();
	break;
	}*/
	case 62:
	{
		PathDG(filename);
		fi.open(filename);
		readR(l2, reader, fi, q);
		sum = NOR(l2, reader);
		gotoxy(20, 2);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** Reader Statistics**** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(20, 4);
		cout << "- Total Reader In The Library: " << sum << endl;
		SOR(l2, reader);
		fi.close();
		break;
	}
	/*case 64:
	{
	PathDG(filename);
	fi.open(filename);
	readR(l2, reader, fi, q);
	SOR(l2, reader);
	fi.close();
	break;
	}*/
	case 63:
	{
		PathBO(filename);
		fi.open(filename);
		ReadBo(bo, fi, lbr);
		sum = totalborr(lbr);
		gotoxy(20, 2);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** Borrow  Statistics**** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		gotoxy(20, 4);
		cout << "Total Books Have Been Borrowed: " << sum << endl;
		fi.close();
		break;
	}
	case 64:
	{
		gotoxy(20, 2);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 **** Over Limit Give Back Statistics **** \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
		thongke(l3, l2, reader, fi);
		fi.close();
		break;
	}
	case 4:
	{
		PathBO(filename);
		fi.open(filename);
		ReadBo(bo, fi, lbr);
		BORR(l3, l2, l1, book, reader, fi);
		break;
		fi.close();
	}
	case 5:
	{
		Giveback(l3, l2, l1, book, reader, fi);
		break;
		fi.close();
	}
	default:
	{
		return;
	}
	}
	fi.close();
}