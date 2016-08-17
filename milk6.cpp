/*
ID: zihaoch1
PROG: milk6
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std; 

struct node
{
	int x, y; 
	long long v;
} e[1005]; 

int source, sink, n, m; 
long long  d[100]; 
long long c1[100][100], c[100][100], r[100][100], C1[100][100], C[100][100], R[100][100]; 
const long long  INF = 2000000000000;


void init()
{
	memcpy(c, C, sizeof(C));
	memcpy(c1, C1, sizeof(C1));
	memcpy(r, R, sizeof(R));
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
}

long long sap()
{
	init(); 
	int top = source, pre[300], i, j, k;
	long long low[300], flow = 0; 
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
			int tmpMin = 1001; 
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
	ifstream cin("milk6.in"); 
	ofstream cout("milk6.out"); 
	cin >> n >> m; 
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		long long z; 
		cin >> x >> y >> z; 
		z = z * 1001 + 1;  
		e[i].x = x; 
		e[i].y = y; 
		e[i].v = z;
		z += R[x][y];
		R[x][y] = C[x][y] = C1[y][x] = z; 
	}
	source = 1; 
	sink = n; 
	long long  value = sap(); 
	cout << value / 1001 << ' '<< value % 1001<<endl;
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int x = e[i].x;
		int y = e[i].y;
		C[x][y] -= e[i].v;
		R[x][y] = C[x][y];
		C1[y][x] = C[x][y];
		long long tmp = sap();
		if (tmp + e[i].v == value)
		{
		//	cout<<tmp/1001<<' ' <<e[i].v/1001 << ' '<< value/1001<<endl;
			if (cnt == value % 1001) break;
			cnt++;
			cout<<i<<endl;
		}
		C[x][y] += e[i].v;	
		R[x][y] = C[x][y];
		C1[y][x] = C[x][y];
	}

	
}

