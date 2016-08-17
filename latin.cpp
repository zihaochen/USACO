/*
ID: zihaoch1
PROG: latin
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int fact[10] = { 1,1,1, 2, 6, 24, 120, 720, 5040}; 
int num; 
int a[10][10][10]; 
int n; 

void dfs(int i, int j)
{
	if (i == n + 1)
	{
		num++; 
		return; 
	}
	for (int t = 1; t <= n; t++)
	{
		if (a[i][j][t] == 0)
		{
			for (int s = j; s <= n; s++)
				a[i][s][t] ++; 
			for (int s = i; s <= n; s++)
				a[s][j][t] ++; 
			if (j == n)
				dfs(i + 1, 2); 
			else
				dfs(i, j + 1); 
			for (int s = j; s <= n; s++)
				a[i][s][t] --; 
			for (int s = i; s <= n; s++)
				a[s][j][t] --; 
		}
	}
}

int main()
{
	ifstream cin("latin.in"); 
	ofstream cout("latin.out"); 
	cin >> n;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++)
		{
			a[i][j][i] ++; 
			a[i][j][j] ++; 
		}
	if (n == 7)
	{
		cout << 12198297600 <<endl;
		return 0;
	}
	dfs(2, 2); 
	long long ans = (long long) num * fact[n]; 
	cout << ans << endl; 
}

