/*
ID: zihaoch1
PROG: inflate
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int f[10002]; 
int a[10002], b[10002]; 

int main()
{
	int m, n; 
	ifstream cin("inflate.in"); 
	ofstream cout("inflate.out"); 
	cin >> m >> n; 
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i]; 
	for (int i = 1; i <= n; i++)
		for (int v = b[i]; v <= m; v++)
			f[v] = max(f[v], f[v - b[i]] + a[i]); 
	cout << f[m] << endl; 
}

