/*
ID: zihaoch1
PROG: castle
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std; 

int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, -1, 0, 1}; 
bool e[100][100][4]; 
int sum[100][100], f[100][100], c[10005]; 
int m, n; 
int num = 0, cnt = 0, Max = 0; 

void dfs(int i, int j, int &num)
{
	if (i<1||i>m||j<1||j>n||sum[i][j]) return;
	f[i][j] = cnt;
	sum[i][j] = ++num ;  
	for (int t = 0; t < 4; t++)
		if (e[i][j][t] == 0)
			dfs(i + dy[t], j + dx[t], num); 
}

int main()
{
	int tmp;
	ifstream cin("castle.in"); 
	ofstream cout ("castle.out"); 
	cin >> n >> m; 
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> tmp; 
			for (int t = 0; t < 4; t++)
			{
				if (tmp % 2 == 1)
					e[i][j][t] = 1;  
				tmp /= 2; 
			}
		}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			{
				if (sum[i][j]) continue;
				++cnt;
				num = 0, dfs(i, j, num);
				Max = max(num, Max);
				c[cnt] = num;
			}	
	cout << cnt << endl; 
	cout << Max << endl; 
	int I, J, T, s = 0; 
	char ch; 
	
	for (int j = 1; j <= n; j++)
		for (int i = m; i >= 1; i--)
		{
			if (e[i][j][1] && f[i][j] != f[i - 1][j])
			{
				int x1 = f[i][j], x2 = f[i - 1][j]; 
				if (c[x1] + c[x2] > s) 
					s = c[x1] + c[x2], I = i, J = j, ch = 'N'; 
			}
			if (e[i][j][2] && f[i][j] != f[i][j + 1])
			{
				int x1 = f[i][j], x2 = f[i][j + 1]; 
				if (c[x1] + c[x2] > s) 
					s = c[x1] + c[x2], I = i, J = j, ch = 'E'; 
			}
		}

	cout << s << endl; 
	cout << I << ' ' << J << ' ' << ch << endl; 



}


