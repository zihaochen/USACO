/*
ID: zihaoch1
PROG: ditch
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std; 

const int INF = 1000000000; 
int n, m, c[300][300], c1[300][300], r[300][300], source, sink; 
int d[300]; 

void init()
{
	int q[300], head = 0, tail = 0; 
	memset(d, 0, sizeof(d)); 
	q[tail++] = sink; 
	while (head < tail)
	{
		int u = q[head++], v; 
		for (v = 0; v <= sink; v++)
			if (d[v] == 0 && c1[u][v] > 0)
			{
				d[v] = d[u] + 1; 
				q[tail++] = v; 
			}
	}
//	for (int i = source;i <= sink;i++)	
//		cout<<d[i]<<' ';
//	cout<<endl;
}

int sap()
{
	init(); 
	int top = source, pre[300], flow = 0, i, j, k, low[300]; 
	memset(low, 0, sizeof(low)); 
	while (d[source] < n)
	{
		bool flag = 0; 
		low[source] = INF; 
		for (i = 0; i <= sink; i++)
		{
			if (r[top][i] > 0 && d[top] == d[i] + 1)
			{
				flag = 1; 
				break; 
			}
		}
		if (flag)
		{
			low[i] = r[top][i]; 
			low[i] = min(low[i], low[top]); 
			pre[i] = top; 
			top = i; 
			if (top == sink)
			{
				flow += low[sink]; 
				j = top; 
				while (j != source)
				{
					k = pre[j]; 
					r[k][j] -= low[sink]; 
					r[j][k] += low[sink];
					j = k;
				}
				top = source; 
				memset(low, 0, sizeof(low)); 

			}
		}
		else
		{
			int tmpMin = INF; 
			for (int j = 0; j <= sink; j++)
				if (r[top][j] > 0 && tmpMin > d[j] + 1)
					tmpMin = d[j] + 1; 
			d[top] = tmpMin; 
			if (top != source) top = pre[top]; 
		}
	}
	return flow; 
}

int main()
{
	ifstream cin("ditch.in"); 
	ofstream cout("ditch.out"); 
	cin >> n >> m; 
	source = 1; 
	sink = m; 
	for (int i = 0; i < n; i++)
	{
		int x, y, z; 
		cin >> x >> y >> z; 
		z += r[x][y];
		r[x][y] = c[x][y] = c1[y][x] = z; 
	}
	
	cout << sap() << endl; 
}

