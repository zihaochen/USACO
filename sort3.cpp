/*
ID: zihaoch1
PROG: sort3
LANG: C++
*/
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std; 
const int MaxNum = 1005; 

int x[MaxNum]; 
int num[4], a[4], b[4], c[4]; 

int main()
{
	int n, sum = 0; 
	ifstream cin("sort3.in"); 
	ofstream cout("sort3.out"); 
	cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i]; 
		num[x[i]]++; 
	}
	for (int i = 1; i <= num[1]; i++)
	{
		if (x[i] == 2) a[2]++; 
		if (x[i] == 3) a[3]++; 
	}
	for (int i = num[1] + 1; i <= num[1] + num[2]; i++)
	{
		if (x[i] == 1) b[1] ++; 
		if (x[i] == 3) b[3]++; 
	}
	for (int i = num[1] + num[2] + 1; i <= num[1] + num[2] + num[3]; i++)
	{
		if (x[i] == 1) c[1]++; 
		if (x[i] == 2) c[2]++;  
	}
	sum = a[2] + a[3] + max(b[3], c[2]); 
	cout << sum << endl; 
}

