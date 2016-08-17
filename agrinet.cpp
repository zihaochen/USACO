/*
ID: zihaoch1
PROG: agrinet
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std; 

struct edge
{
	int s, e; 
	int value; 

	bool operator < (const edge &x) const
	{
		return (value < x.value); 
	}
} b[10000];
int a[1003][1003]; 
int Count; 
int fa[1003]; 
int n, num; 

int find(int i)
{
	if (fa[i] < 0) return i; 
	else return (fa[i] = find(fa[i])); 
}

void Union(int u, int v)
{
	if (u == v) return; 
	if (fa[u] > fa[v])
	{
		fa[v] += fa[u];
		fa[u] = v; 
	}
	else
	{
		fa[u] += fa[v]; 
		fa[v] = u; 
	}
}

void kruskal()
{
	for (int i = 1; i <= n; i++)
		fa[i] = -1; 
	int cnt = 0;
	int tmp = 0; 
	while (cnt < n - 1 && tmp < num)
	{
		int u = find(b[tmp].s); 
		int v = find(b[tmp].e); 
		if (u != v)
		{
			Union(u, v); 
			cnt++;
			Count += b[tmp].value; 
		}
		tmp++; 
	}
}

int main()
{
	ifstream cin("agrinet.in"); 
	ofstream cout("agrinet.out"); 
	cin >> n; 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j]; 

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			if (a[i][j] == 0) continue; 
			b[num].s = i; 
			b[num].e = j; 
			b[num].value = a[i][j]; 
			num++; 
		}

	sort(b, b + num); 

	kruskal(); 
	
	cout << Count << endl; 

}

