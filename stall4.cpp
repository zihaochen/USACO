/*
ID: zihaoch1
PROG: stall4
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#define debug cout<<"not here\n"
using namespace std; 

int c[500][500], c1[500][500], r[500][500]; 
int d[500]; 
int q[300], low[500], pre[500]; 
int source, sink; 
int m, n; 
int num;
const int INF = 100000000; 

void init()
{
	int head = 0, tail = 0; 
	q[tail++] = sink; 
	while (head < tail)
	{
		int u = q[head++]; 
		for (int v = 0; v <= sink; v++)
		{
			if (c1[u][v] > 0 && d[v] == 0)
			{
				d[v] = d[u] + 1; 
				q[tail++] = v; 
			}
		}
	}
}

int sap()
{
	init(); 
	int flow = 0, i, j, k; 
	memset(low, 0, sizeof(low)); 
	int top = source; 
	while (d[source] < num)
	{
		low[source] = INF; 
		bool flag = 0; 
		for (i = 0; i <= sink; i++)
			if (r[top][i] > 0 && d[top] == d[i] + 1)
			{
				flag = 1; 
				break; 
			}
		if (flag)
		{
			low[i] = r[top][i]; 
			low[i] = min(low[i], low[top]); 
			pre[i] = top; 
			top = i; 
			if (top == sink)
			{
				flow += low[top]; 
				j = top; 
				while (j != source)
				{
					k = pre[j]; 
					r[k][j] -= low[top];
					r[j][k] += low[top]; 
					j = k; 
				}
				top = source; 
				memset(low, 0, sizeof(low)); 
			}
		}
		else
		{
			int tmpMin = INF; 
			for (int i = 0; i <= sink; i++)
				if (r[top][i] > 0 && tmpMin > d[i] + 1)
					tmpMin = d[i] + 1; 
			d[top] = tmpMin; 
			if (top != source) top = pre[top]; 
		}
	}
	return flow;
}

int main()
{
	ifstream cin("stall4.in"); 
	ofstream cout("stall4.out"); 
	cin >> n >> m; 
	for (int i = 1; i <= n; i++)
	{
		int tmp, x; 
		cin >> tmp;
		num += tmp; 
		for (int j = 0; j < tmp; j++)
		{
			cin >> x; 
			c[i][x + n] = c1[x + n][i] = r[i][x + n] = 1; 
		}
		c[0][i] = c1[i][0] = r[0][i] = 1; 
	}
	source = 0; 
	sink = m + n + 1;
	for (int i = n + 1; i <= m + n; i++)
		c[i][m + n + 1] = c1[m + n + 1][i] = r[i][m + n + 1] = 1;  
	num = num + n + m;
	cout << sap() << endl; 
}

