/*
ID: zihaoch1
PROG: crypt1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

bool check(int); 
int n,p[10];

int main()
{
int a,b,c,d,e,sum = 0;
	ifstream fin("crypt1.in"); 
	ofstream fout("crypt1.out"); 
	fin >> n; 
	for (int i = 0; i < n ; i++)
		fin >> p[i]; 
	for (a = 0; a < n; a++)
		for (b = 0; b < n; b++)
			for (c = 0; c < n; c++)
				for (d = 0; d < n; d++)
					for (e = 0; e < n; e++)
					{
						if ((check(p[e] * (100 * p[a] + 10 * p[b] + p[c]))) && (check(p[d] * (100 * p[a] + 10 * p[b] + p[c]))) && check((10 * p[d] + p[e]) * (100 * p[a] + 10 * p[b] + p[c])) && ((p[e] * (100 * p[a] + 10 * p[b] + p[c])) >=100) && ((p[e] * (100 * p[a] + 10 * p[b] + p[c])) <= 999) && (p[d] * (100 * p[a] + 10 * p[b] + p[c]) >= 100) && ((p[d] * (100 * p[a] + 10 * p[b] + p[c])) <= 999) && (((10 * p[d] + p[e]) * (100 * p[a] + 10 * p[b] + p[c])) >= 1000) && (((10 * p[d] + p[e]) * (100 * p[a] + 10 * p[b] + p[c])) <= 9999) )
							sum++;
					}
	fout << sum << endl; 
}

bool check(int m)
{
bool flag = 1, tmp = 0;
int r; 
	while (m >= 10)
	{
		r = m % 10; 
		tmp = 0; 
		for (int i = 0; i < n; i++)
			if (p[i] == r) tmp = 1; 
		m = m / 10; 
		if (!tmp) 
		{
			flag = 0; 
			break; 
		}
	}
	tmp = 0;
	for (int i = 0; i < n; i++)
		if (p[i] == m) tmp = 1; 
	return (flag && tmp); 
}

