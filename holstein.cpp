/*
ID: zihaoch1
PROG: holstein
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std; 

int V, n, num = 10000; 
int a[30][30], v[30], result[30], sum[30], tmp[30]; 

void dfs(int t, int cnt)
{
	if (t == n + 1)
	{
		if (cnt >= num) return; 
		fill_n(sum, 30, 0); 
		for (int i = 0; i < V; i++)
		{
			for (int j = 1; j <= cnt; j++)
				sum[i] += a[tmp[j]][i]; 
			if (sum[i] < v[i]) return; 
		}
		if (cnt < num)
		{
			for (int i = 1; i <= cnt; i++)
				result[i] = tmp[i]; 
			num = cnt;
		}
		return; 
	}
	tmp[cnt + 1] = t; 
	dfs(t + 1, cnt + 1); 
	dfs(t + 1, cnt); 
}

int main()
{
	ifstream cin("holstein.in"); 
	ofstream cout("holstein.out"); 
	cin >> V; 
	for (int i = 0; i < V; i++)
		cin >> v[i]; 
	cin >> n; 
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < V; j++)
			cin >> a[i][j]; 
	dfs(1, 0);
	cout<<num<<' ';
	for (int i = 1; i <= num - 1; i++)
		cout << result[i]  <<  ' '; 
	cout << result[num] << endl; 

}

