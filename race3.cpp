/*
ID: zihaoch1
PROG: race3
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
using namespace std;  

vector <int> q1, q2, v[60]; 
int visited[60]; 
int a[60][60];
bool flag; 
int n;

bool dfs1(int index)
{
	visited[index] = 1; 
	if (index == n) return 1; 
	for (int i = 0; i < v[index].size(); i++)
	{
		int tmp = v[index][i]; 
		if (!visited[tmp]) 
			if (dfs1(tmp)) 
				return 1;  
	}
	return 0; 
}

void dfs2(int index)
{
	visited[index] = 1; 
	for (int i = 0; i < v[index].size(); i++)
	{
		int tmp = v[index][i]; 
		if (!visited[tmp]) dfs2(tmp); 
	}
}

void dfs2(int index, int limit)
{
	if (index == 0 && visited[index] == 1) 
	{
		flag = 1;
		return;
	}
	if (flag) return; 
	visited[index] = 2; 
	for (int i = 0; i < v[index].size(); i++)
	{
		int tmp = v[index][i]; 
		if (!visited[tmp]) dfs2(tmp, limit); 
		if (visited[tmp] == 1 && tmp != limit)
		{
			flag = 1; 
			return; 
		}
	}
}

int main()
{
	ifstream cin("race3.in"); 
	ofstream cout("race3.out"); 
	for (int i = 0; ; i++)
	{
		int x; 
		cin >> x; 
		if (x  == -1) 
		{
			n = i - 1; 
			break; 
		}
		if (x == -2) continue; 
		v[i].push_back(x); 
		a[i][x] = 1;
		while (1)
		{
			cin >> x; 
			if (x == -2) break; 
			a[i][x] = 1;
			v[i].push_back(x); 
		}
	}
	
	for (int i = 1; i < n; i++)
	{
		memset(visited, 0, sizeof(visited)); 
		visited[i] = 1; 
		if (!dfs1(0)) q1.push_back(i); 
	}

	for (int i = 0; i < q1.size(); i++)
	{
		memset(visited, 0, sizeof(visited)); 
		int tmp = q1[i];
		flag = 0; 
		dfs2(tmp); 
		dfs2(0, tmp);
		if (!flag) q2.push_back(tmp); 
	}

	if (q1.size() != 0)
	{
		cout << q1.size() << ' '; 
		for (int i = 0; i < q1.size() - 1; i++)
			cout << q1[i] <<  ' '; 
		cout << q1[q1.size() - 1] << endl; 
	}
	else cout<<0<<endl;
	
	if (q2.size() != 0)
	{
		cout << q2.size()  <<  ' '; 
		for (int i = 0; i < q2.size() - 1; i++)
			cout << q2[i] <<  ' '; 
		cout << q2[q2.size() - 1] << endl; 
	}
	else cout<<0<<endl;
}

