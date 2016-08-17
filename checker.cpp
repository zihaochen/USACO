/*
ID: zihaoch1
PROG: checker
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

ifstream fin("checker.in"); 
ofstream fout("checker.out"); 

int col[15], n, num, sum; 
bool down[50], up[50], hor[15]; 

void solve(int x)
{
	if (x == n + 1 && num < 3)
	{
		num++; 
		for (int i = 1; i <= n - 1; i++)
			fout << col[i] << ' ';
			fout << col[n] << endl; 
	}
	if (x == n + 1) sum++;
	if (x <= n)
	for (int i = 1; i <= n; i++)
	{
		if (!hor[i] && !up[n - x + i] && !down[x + i])
		{
			col[x] = i; 
			hor[i] = up[n - x + i] = down[x + i] = 1; 
			solve(x + 1); 
			hor[i] = up[n - x + i] = down[x + i] = 0;  
		}
	}
}

int main()
{
	fin >> n; 
	solve(1);
	fout << sum<< endl; 
}

