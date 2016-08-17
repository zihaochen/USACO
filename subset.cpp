/*
ID: zihaoch1
PROG: subset
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

long long  a[50][1000]; 

int main()
{
	int n; 
	ifstream cin("subset.in"); 
	ofstream cout("subset.out"); 
	cin >> n; 
	int sum = (n + 1) * n / 2; 
	if (sum % 2 != 0)
		cout << 0 << endl; 
	else
	{
		a[0][0] = 1; 
		for (int i = 1; i <= n; i++)
		{
			for (int j = sum; j >= 0; j--)
			{
				a[i][j + i] += a[i - 1][j]; 
				a[i][j] = a[i - 1][j]; 
			}
		}
		cout << a[n][sum / 2] / 2 << endl; 
	}
}

