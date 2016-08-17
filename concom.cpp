/*
ID: zihaoch1
PROG: concom
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int f[200][200], con[200][200], num[200],old[200][200]; 

void effect(int a, int b)
{
	for (int i = 1; i <= 100; i++)
	{
		int tmp = f[a][i]; 
		f[a][i] += old[b][i];
		if (tmp <= 50 && f[a][i] >50)
		{
			con[i][num[i]++] = a;		
			effect(a, i); 
		}
	}
}

int main()
{
	int n,a,b,c;
	ifstream cin("concom.in"); 
	ofstream cout("concom.out"); 
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c; 
		old[a][b] = f[a][b] = c; 
		if (c > 50)
			con[b][num[b]++] = a; 
		
	}
	for (int i = 1; i <= 100; i++)
		for (int j = 0; j < num[i]; j++)
			effect(con[i][j], i); 

	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (f[i][j] > 50 && i != j)
				cout << i << ' ' << j << endl; 
}


