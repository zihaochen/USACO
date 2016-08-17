/*
ID: zihaoch1
PROG: numtri
LANG: C++
*/
#include<fstream>
#include<iostream>
using namespace std; 

int f[1005][1005], a[1005][1005]; 

int main()
{
	int sum = 0, r; 
	ifstream fin("numtri.in"); 
	ofstream fout("numtri.out"); 
	fin >> r; 
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= i; j++)
			fin >> a[i][j]; 
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = max(f[i-1][j], f[i-1][j-1]) + a[i][j]; 
	for (int i = 1; i <= r; i++)
		sum = max(sum, f[r][i]); 
	fout << sum << endl; 
}

