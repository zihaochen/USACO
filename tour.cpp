/*
ID: zihaoch1
PROG: tour
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

const int N = 105; 
int a[N][N], f[N][N]; 
string s[N]; 

int main()
{
	ifstream cin("tour.in"); 
	ofstream cout("tour.out"); 

	int n, m; 
	cin >> n >> m; 
	for (int i = 1; i <= n; i++)
		cin >> s[i]; 
	for (int i = 0; i < m; i++)
	{
		string s1, s2; 
		int tmp1, tmp2; 
		cin >> s1 >> s2; 
		for (int j = 1; j <= n; j++)
		{
			if (s[j] == s1) tmp1 = j; 
			if (s[j] == s2) tmp2 = j; 
		}
		a[min(tmp1, tmp2)][max(tmp1, tmp2)] = 1; 
	}

	f[1][1] = 1; 
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = 1; k < j; k++)
			{
				if (f[i][k] && a[k][j])
					f[j][i] = f[i][j] = max(f[i][j], f[i][k] + 1); 
			}

	int maxNum = 1; 
	for (int i = 1; i < n; i++)
		if (a[i][n]) maxNum = max(maxNum, f[i][n]); 

	cout << maxNum << endl; 
}

