/*
ID: zihaoch1
PROG: game1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int n, sum; 
int a[200], f[200][200];  

int main()
{
	ifstream cin("game1.in"); 
	ofstream cout("game1.out"); 
	cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
		sum += a[i]; 
	}

	for (int j = 1; j <= n; j++)
		for (int i = 1; i + j -1 <= n; i++)
		{
			if ((n - j) % 2 == 0)
				f[i][j] = max(a[i] + f[i + 1][j - 1], a[i + j - 1] + f[i][j - 1]); 
			else
				f[i][j] = min(f[i + 1][j - 1], f[i][j - 1]); 
		}

	cout << f[1][n] << ' ' << sum - f[1][n] << endl; 
}

