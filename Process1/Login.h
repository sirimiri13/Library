#include "string"
#include "iostream"
using namespace std;
bool DangNhap(string st, string sl, int &level, bool &kt);
void changepw(string st, string &sl, int &bl, int level);
void Creatuser(bool &check);
void update(int level, bool &check, string st);
void Distribute(bool &check);
void INFO(string st, int level);