/*
ID: zihaoch1
PROG: dualpal
LANG: C++
*/
#include<fstream>
#include<iostream>
#include<cstring>

using namespace std; 

char ch[100]; 

bool isPal(int base, int m); 
bool check(int m); 

int main()
{
	ifstream fin ("dualpal.in"); 
	ofstream fout ("dualpal.out"); 
	int N, s; 
	int i = 1; 
	fin >> N >> s; 
	while (N > 0)
	{
		if (check(i + s))
		{
			fout << i + s << endl;
			N--; 
		}
		i++; 
	}
}

bool check(int m)
{
int  flag = 0; 
	for (int base = 2; base <= 10; base++)
	{
		if (isPal(base, m))
			flag += 1;  
		if (flag == 2) break;
	}
	if (flag == 2)
		return 1;
	return 0; 
}

bool isPal(int base, int m)
{
int t = 0;
bool flag = 1; 
	while (m != 0)
	{
		ch[t] = m % base; 
		m =  m / base; 
		t++; 
	}
	for (int j = 0; j <= t - 1; j++)
		if (ch[j] != ch[t - 1 - j])
		{
			flag = 0; 
			break; 
		}
	return flag; 
}

