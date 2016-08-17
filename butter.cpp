/*
ID: zihaoch1
PROG: butter
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std; 

const int MAX_INT = 100000000; 
int a[900][900], loc[900], d[900]; 
vector<int> v[900];
int n, p, c; 

struct data
{
	int t;
	bool operator < (const data &x) const
	{
		return d[t] > d[x.t];
	}
	data(int x)
	{
		t = x;
	}
};

bool visited[900]; 
void spfa(int x)
{
	priority_queue<data> q;
	q.push(x);
	d[x] = 0; 
	visited[x] = 1; 
	while (q.empty() == 0)
	{
		int tmp = q.top().t;
		q.pop();
		for (int j = 0;j < v[tmp].size(); j++)
		{
			int i = v[tmp][j];
			if (i == tmp) continue;
			int relax = d[i];
			d[i] = min(d[tmp] + a[tmp][i], d[i]);
			if (visited[i] == 0 && relax != d[i])
			{
				q.push(i);
				visited[i] = 1;
			}
		}
		visited[tmp] = 0;
	}
}

int main()
{
	ifstream cin("butter.in"); 
	ofstream cout("butter.out"); 
	cin >> n >> p >> c; 
	for (int i = 1; i <= n; i++)
		cin >> loc[i]; 
	for (int i = 1; i <= p; i++)
		for (int j = 1; j <= p; j++)
			a[i][j] = MAX_INT; 

	int x, y, z;
	for (int i = 1; i <= c; i++)
	{
		cin >> x >> y >> z; 
		a[x][y] = a[y][x] = z; 
		v[x].push_back(y);
		v[y].push_back(x);
	}

	int tmp, num = MAX_INT; 

	for (int i = 1; i <= p; i++)
	{
		tmp = 0; 
		for (int j = 1; j <= p; j++)
			d[j] = MAX_INT; 
		fill_n(visited, 900, 0); 
		spfa(i); 
		for (int j = 1; j <= n; j++)
			tmp += d[loc[j]]; 
		num = min(tmp, num); 
	}

	cout << num << endl; 
}

