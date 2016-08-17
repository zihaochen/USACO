/*
ID: zihaoch1
PROG: sprime
LANG: C++
*/
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std; 

bool isPrime(int x)
{
	if (x % 2 == 0) return 0; 
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return 0; 
	return 1; 
}

void solve(int); 
int num;
	ifstream fin("sprime.in"); 
	ofstream fout("sprime.out"); 
int main()
{
	int n; 

	fin >> n;
	num = (int) pow(10, n - 1); 
	solve(2); 
	solve(3); 
	solve(5); 
	solve(7); 
}

void solve(int x)
{
	
	if (x / num > 9) return; 
	for (int i = 1; i <= 9; i += 2)
	{
		int y = 10 * x + i; 
		if (isPrime(y))
		{
			if (y / num > 0 && y / num < 10) fout << y << endl; 
			solve(y); 
		}
	}
}

