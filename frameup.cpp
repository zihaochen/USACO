/*
ID: zihaoch1
PROG: frameup
LANG: C++
*/
//#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<algorithm>
#define debug cout<<"not here\n"
using namespace std; 

struct node
{
	int maxI, maxJ, minI, minJ; 
} a[50]; 
bool m[50][50]; 
char ch[50][50]; 
int ans[50], d[50]; 
bool app[50], visited[50];
const int INF = 1000; 
int num;
vector<string> result;
ifstream cin("frameup.in"); 
ofstream cout("frameup.out"); 

void dfs(int x, int depth)
{
	ans[depth] = x;
	visited[x] = 1;
	if (depth >= num)
	{
		for (int i = 1; i <= num; i++)
			cout<<(char) (ans[i] + 'A' - 1);
		cout<<endl;
		return;
	}
	if (d[x] == 0)
	{
		for (int i =  1; i <= 26; i++)
			if (m[x][i] == 1) d[i]--;
	
		for (int i = 1; i <= 26; i++)
			if (app[i] && visited[i] == 0 && d[i] == 0)
			{
				dfs(i, depth + 1);
				visited[i] = 0;
			}
			
		for (int i = 1; i <= 26; i++)
			if (m[x][i] == 1) d[i]++;
	}
}

int main()
{
	int h, w; 
	cin >> h >> w; 
	for (int i = 1; i <= 26; i++)
	{
		a[i].maxI = a[i].maxJ = 0; 
		a[i].minI = INF;
		a[i].minJ = INF;
	}

	for (int i = 1;  i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cin >> ch[i][j];
			if (ch[i][j] == '.') continue;
			app[(int) (ch[i][j] - 'A' + 1)] = 1;
			int tmp = (int) (ch[i][j] - 'A' + 1); 
			a[tmp].maxI = max(a[tmp].maxI, i); 
			a[tmp].maxJ = max(a[tmp].maxJ, j); 
			a[tmp].minI = min(a[tmp].minI, i); 
			a[tmp].minJ = min(a[tmp].minJ, j); 
		}
	}
	for (int t = 1; t <= 26; t++)
	{
		if (!app[t]) continue;
		for (int i = a[t].minI; i <= a[t].maxI; i += a[t].maxI - a[t].minI)
			for (int j = a[t].minJ; j <= a[t].maxJ; j++)
			{
				if (ch[i][j] == '.') continue;
				if (ch[i][j] != (char)(t + 'A' - 1))
					m[t][(int) (ch[i][j] - 'A' + 1)] = 1; 
			}
	}
			
	for (int t = 1; t <= 26; t++)
	{
		if (!app[t]) continue;
		for (int j = a[t].minJ; j <= a[t].maxJ; j += a[t].maxJ - a[t].minJ)
			for (int i = a[t].minI; i <= a[t].maxI; i++)
			{
				if (ch[i][j] == '.') continue;
				if (ch[i][j] != (char)(t + 'A' - 1))
					m[t][(int) (ch[i][j] - 'A' + 1)] = 1; 
			}
	}
	
	for (int i = 1;i <= 26; i++)
		for (int j = 1;j <= 26;j++)
			if (m[i][j]) d[j]++;
			
	for (int i = 1; i <= 26; i++)
	{
		if (!app[i]) continue;
		num++;
	}
	for (int i = 1; i <= 26; i++)
		if (d[i] == 0 && app[i])
		{
			memset(visited, 0, sizeof(visited));
			dfs(i, 1);
		}
}

