/*
ID: zihaoch1
PROG: fence8
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std; 

int r[2000], b[60], tmp[60], sumR[2000]; 
int ddl; 
int m, n; 

bool cmp(int a, int b)
{
	return a > b;
}

bool dfs(int index, int limit, int last, int sum) // last 表示上一个放的位置
{
	if (index < 0) return 1; 
	//最关键剪枝
	if (sum > ddl) return 0;
	
	int i; 
	for (i = 0; i < n; i++)
		if (tmp[i] >= r[index]) break; 
	if (index < limit && r[index] == r[index + 1])
	{
		for (int j = last; j < n; j++)
			if (tmp[j] >= r[index])
			{
				tmp[j] -= r[index];
				if (dfs(index - 1, limit, j, sum + (tmp[j] >= r[0] ? 0 : tmp[j]))) return 1;
				tmp[j] += r[index];
			}
		return 0; 
	}

	for (int j = 0; j < n; j++)
		if (tmp[j] >= r[index])
		{
			tmp[j] -= r[index];
			if (dfs(index - 1, limit, j, sum + (tmp[j] >= r[0] ? 0 : tmp[j]))) return 1;
			tmp[j] += r[index];
		}
	return 0; 
}

int main()
{
	ifstream cin("fence8.in"); 
	ofstream cout("fence8.out"); 
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> b[i]; 
	cin >> m; 
	int tt = 0;
	for (int i = 0; i < m; i++)
		cin >> r[i]; 

	sort(b, b + n, cmp);
	sort(r, r + m); 
	
	for (int i = 0;i < m;i++)
	{
		tt += r[i];
		sumR[i] = tt;
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += b[i]; 
	
	int left, right;
	bool flag = 0;
	for (left = 0, right = m - 1; left <= right; )
	{
		int mid = (left + right) /2;	
		for (int i = 0; i < n; i++)
			tmp[i] = b[i];
		ddl = sum - sumR[mid]; 
		if (ddl >= 0 && dfs(mid, mid, -1, 0))
		{
			flag = 1;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	if (flag)
		cout << (left + right) / 2 + 1 << endl; 
	else 
		cout<<0<<endl;
}

