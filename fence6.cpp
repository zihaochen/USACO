/*
ID: zihaoch1
PROG: fence6
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#define debug cout<<"not here\n"
using namespace std; 

bool visited[200], Merge[200]; 
int a[200][200]; 
int c[200], l[200], n1[200], n2[200]; 
vector<int> v[200], e[200], node[200];  
int minimum = 10000000; 

void dfs(int root, int now, int value, int pre)
{
//	cout<<"now"<<now<<"value"<<value<<endl;
	if (value >= minimum) return; 
	if (value > 0 && now == root) 
	{
		minimum = min(minimum, value); 
		return; 
	}
	
	for (int i = 0; i < v[now].size(); i++)
	{
		int tmp = v[now][i]; 
		if (tmp == pre) continue;
		if (visited[tmp] && !(tmp == root)) continue; 
		visited[tmp] = 1; 
		dfs(root, tmp, value + a[tmp][now], now); 
		visited[tmp] = 0; 
	}
}

int main()
{
	ifstream cin("fence6.in"); 
	ofstream cout("fence6.out"); 

	int n, x, y; 
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i] >> y >> n1[i] >> n2[i]; 
		l[c[i]] = y;
		node[2 * i - 1].push_back(c[i]); 
		node[2 * i].push_back(c[i]); 
		for (int j = 0; j < n1[i]; j++)
		{
			cin >> x; 
			node[2 * i - 1].push_back(x); 
		}
		for (int j = 0; j < n2[i]; j++)
		{
			cin >> x; 
			node[2 * i].push_back(x); 
		}
	}
	
	for (int i = 1; i <= 2 * n; i++)
		sort(node[i].begin(), node[i].end()); 

	for (int i = 1; i <= 2 * n; i++)
	{
		if (Merge[i]) continue; 
		for (int j = 1; j <= 2 * n; j++)
			if (node[j][0] == node[i][0] && node[j][1] == node[i][1] && i != j)
				Merge[j] = 1; 
	}
	
	int num = 0; 
	for (int i = 1; i <= 2 * n; i++)
		if (!Merge[i])
			v[++num] = node[i]; 

	for (int i = 1; i <= num; i++)
	{
		while (!v[i].empty())
		{
			int tmp = v[i].back();
			v[i].pop_back(); 
			e[tmp].push_back(i); 
		}
	}

	for (int i = 1; i <= n; i++)
	{
		
		int tmp1 = e[c[i]][0]; 
		int tmp2 = e[c[i]][1]; 
		a[tmp1][tmp2] = a[tmp2][tmp1] = l[c[i]]; 
		v[tmp1].push_back(tmp2); 
		v[tmp2].push_back(tmp1); 
	}

	// Ô¤´¦ÀíÍê±Ï

	
	for (int i = 1; i <= num; i++)
		{
			visited[i] = 1;
			dfs(i, i, 0, 0);
			visited[i] = 0; 
		}

	cout << minimum << endl; 
}
/*
10
1 16 2 2
2 7
10 6
2 3 2 2
1 7
8 3
3 3 2 1
8 2
4
4 8 1 3
3
9 10 5
5 8 3 1
9 10 4
6
6 6 1 2 
5 
1 10
7 5 2 2 
1 2
8 9
8 4 2 2
2 3
7 9
9 5 2 3
7 8
4 5 10
10 10 2 3
1 6
4 9 5
*/

