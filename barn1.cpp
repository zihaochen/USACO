/*
ID: zihaoch1
PROG: barn1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std; 

int a[210], crevice[210]; 
int main()
{
int m, s, c, i, t, sum; 
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	fin >> m >> s >> c; 
	for (i = 0; i < c; i++)
		fin >> a[i];
	t = 0; 
	sort(a,a + c);
	for (i = 1; i < c; i++)
	{
		if ((a[i] - a[i - 1]) > 1)
			crevice[++t] = a[i] - a[i - 1] - 1; 
	}
	sort(crevice,crevice + t + 1); 
	sum = a[c - 1] - a[0] + 1;
	while (m > 1)
	{ 
		if (t >= 1)
			sum -= crevice[t--]; 
		m--; 
	}
	fout << sum << endl; 
}
