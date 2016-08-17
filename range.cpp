/*
ID: zihaoch1
PROG: range
LANG: C++
*/
#include<iostream>
#include<fstream>
#define debug cout<<"not here\n"
using namespace std; 

int n; 
int a[300][300], f[300][300]; 
int num[300]; 

int main()
{
	char ch;
	ifstream cin("range.in"); 
	ofstream cout("range.out"); 
	cin >> n; 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> ch;
			a[i][j] = (int) ch - '0';
		}


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j]; 
			
	for (int i = 0; i <= n - 2; i++)
		for (int j = 0; j <= n - 2; j++)
			for (int t = 2; t <= min(n - i, n - j); t++)
				if (f[i + t][j + t] -f[i][j + t] - f[i + t][j] + f[i][j]  == t * t)
					num[t]++; 

	for (int i= 2; i <= n; i++)
	{
		if (num[i])
			cout << i << ' ' << num[i] << endl; 
		else 
			break; 
	}
}

