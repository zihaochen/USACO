/*
ID: zihaoch1
PROG: ttwo
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int di[4] = {-1, 0, 1, 0}; 
int dj[4] = {0, 1, 0, -1}; 
int d[4]; 
int m[11][11]; 
int ci, cj, fi, fj; 

void walk(int i, int j, int type)
{
	if (i + di[d[type]] >= 1 && i + di[d[type]] <= 10 && j + dj[d[type]] >= 1\
	 && j + dj[d[type]] <= 10 && m[i + di[d[type]]][j + dj[d[type]]] != 1)
	{
		m[i][j] = 0; 
		i += di[d[type]]; 
		j += dj[d[type]]; 
		m[i][j] = type; 
	}
	else
		d[type] = (d[type] + 1) % 4; 
	if (type == 2)
	{
		ci = i; 
		cj = j; 
	}
	if (type == 3)
	{
		fi = i; 
		fj = j; 
	}
}

int main()
{
	ifstream cin("ttwo.in"); 
	ofstream cout("ttwo.out"); 
	char ch; 
	for (int i = 1 ; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
		{
			cin >> ch; 
			if (ch == '*') m[i][j] = 1; 
			if (ch == '.') m[i][j] = 0;
			if (ch == 'C') 
			{
				m[i][j] = 2; 
				ci = i; 
				cj = j; 
			}
			if (ch == 'F')
			{
				m[i][j] = 3; 
				fi = i; 
				fj = j; 
			}
		}
	int count = 0; 
	while (1)
	{
		count++; 
		walk(ci, cj, 2); 
		walk(fi, fj, 3);
		if (ci == fi && cj == fj)
		{
			cout << count << endl; 
			return 0; 
		}
		if (count >= 100000)
		{
			cout << 0 << endl;
			return 0;	
		}
	}
}

