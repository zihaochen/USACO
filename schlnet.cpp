/*
ID: zihaoch1
PROG: schlnet
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

const int INF = 1000000; 
const int N = 200; 
int a[N][N], din[N], dout[N], loc[N]; 
bool visited[N]; 
int num;
int n; 

int main()
{
	ifstream cin("schlnet.in"); 
	ofstream cout("schlnet.out"); 
	cin >> n; 
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = INF; 

	for (int i = 1; i <= n; i++)
	{
		int u; 
		while (1)
		{
			cin >> u; 
			if (u == 0) break; 
			a[i][u] = 1; 
		}
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j]; 

	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue; 
		visited[i] = 1; 
		num++; 
		loc[i] = num; 
		for (int j = 1; j <= n; j++)
		{
			if (visited[j]) continue; 
			if (a[i][j] != INF && a[j][i] != INF)
			{
				visited[j] = 1; 
				loc[j] = num; 
			}
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (loc[i] == loc[j]) continue;
			if (a[i][j] != INF)
			{
				din[loc[j]]++; 
				dout[loc[i]]++; 
			}
		}

	int numIn, numOut; 
	numIn = numOut = 0; 
	for (int i = 1; i <= num; i++)
	{
		if (din[i] == 0) numIn++; 
		if (dout[i] == 0) numOut++; 
	}

	
	cout << numIn << endl;
	if (num != 1) cout << max(numIn, numOut) << endl; 
		else cout<<0<<endl;
}	

