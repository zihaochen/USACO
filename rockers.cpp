/*
ID: zihaoch1
PROG: rockers
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int f[50][50][50]; 
int a[50]; 

int main()
{
	int n, t, m, x, num = 0; 
	ifstream cin("rockers.in"); 
	ofstream cout("rockers.out"); 
	cin >> n >> t >> m; 
	for (int i = 0; i < n; i++)
	{
		cin >> x; 
		if (x <= t) a[++num] = x; 
	}
	if (num <= m)
	{
		cout << num << endl; 
		return 0; 
	}
	for (int i = 1; i <= num;i++)
		for (int j = 1; j <= m;j++)
			for (int k = 1; k <= t; k++)
			{
				f[i][j][k] = f[i][j][k - 1];
				f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
				if (k >= a[i]) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - a[i]] + 1);
				if (k >= a[i]) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][t] + 1);
			}
	cout<<f[num][m][t]<<endl;
}

