/*
ID: zihaoch1
PROG: cowtour
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#define debug cout<<"not here\n"
using namespace std; 

const double INF = 10000000.0; 
double f[200][200], m[200]; 
int fa[200]; 
int n; 

struct node
{
	int x,y;
}a[200];

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

int main()
{
	ifstream cin("cowtour.in"); 
	ofstream cout("cowtour.out"); 
	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y; 
	
	for (int i = 1; i <= n; i++)
		fa[i] = -1; 

	char x; 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> x;
			if (x == '1') 
			{
				f[i][j] = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + \
								(a[i].y - a[j].y) * (a[i].y - a[j].y));
				
				//Union(i, j); 
			}
			else f[i][j] = INF; 
		}
		
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]); 
	
	for (int i = 1; i <= n;i++)
		for (int j = 1;j <= n;j++)
		{
			if (f[i][j] < INF && (i != j))
				m[i] = max(m[i], f[i][j]); 
		}		
		
	double len = INF; 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			//if (find(i) == find(j)) continue; 
			if (f[i][j] <INF || i == j) continue;
			double tmp =  sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + \
								(a[i].y - a[j].y) * (a[i].y - a[j].y)); 
			len = min(tmp + m[i] + m[j], len); 
		}
	for (int i = 1;i <= n;i++)
		len = max(len,m[i]);
	//cout<<len<<endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << len << endl; 	
}

