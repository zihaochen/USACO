/*
ID: zihaoch1
PROG: telecow
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
using namespace std; 

int source, sink, N, n, m; 
int d[300]; 
int c[300][300], r[300][300]; 
const int INF = 1000000; 
vector<int> ans; 
vector<int> e[300];

void init()
{
	int q[300], head = 0, tail = 0; 
	memset(d, 0, sizeof(d)); 
	memcpy(r, c, sizeof(c));
	q[tail++] = sink; 
	while (head < tail)
	{
		int u = q[head++], v; 
		for (int i = 0;i < e[u].size();i++)
		{
			v = e[u][i];
			if (d[v] == 0 && c[v][u] > 0 && v != sink)
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
	int top = source, pre[300], flow = 0, i, j, k, low[300]; 
	memset(low, 0, sizeof(low)); 
	while (d[source] < 2*n)
	{
		bool flag = 0; 
		low[source] = INF; 
		for (int tmp = 0; tmp < e[top].size(); tmp++)
		{
			i = e[top][tmp];
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
			for (int tmp = 0; tmp < e[top].size(); tmp++)
			{
				j = e[top][tmp];
				if (r[top][j] > 0 && tmpMin > d[j] + 1)
					tmpMin = d[j] + 1; 
			}
			d[top] = tmpMin; 
			if (top != source) top = pre[top]; 
		}
	}
	return flow; 
}


int main()
{
	ifstream cin("telecow.in"); 
	ofstream cout("telecow.out");
	int c1, c2; 
	cin >> n >> m >> c1 >> c2; 
	for (int i = 0; i < m; i++)
	{
		int x, y; 
		cin >> x >> y;
		c[2*x][2*y - 1] = c[2*y][2*x - 1] = INF;
		r[2*x][2*y - 1] = r[2*y][2*x - 1] = INF;
		e[2*x].push_back(2*y - 1);
		e[2*y].push_back(2*x - 1);
	}
	for (int i = 1; i <= n; i++)
	{
		e[2*i - 1].push_back(2*i);
		c[2*i - 1][2*i] = r[2*i - 1][2*i] = 1;
	}
	source = 2 * c1; 
	sink = 2 * c2 - 1;
	 
	int value = sap();

	for (int i = 1; i <= n; i++)
	{
		if (i == c1 || i == c2) continue; 
		c[2*i - 1][2*i] = 0;
		int tmp = sap(); 
		if (value - ans.size() == tmp + 1)
			 ans.push_back(i); 
		else  c[2*i - 1][2*i] = 1;

		if (ans.size() >= value) break;
	}

	cout << ans.size() << endl; 
	for (int i = 0; i < ans.size() - 1; i++)
		cout << ans[i] << ' ' ; 
	cout << ans[ans.size() - 1] << endl; 
	return 0;
}
