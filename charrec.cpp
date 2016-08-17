/*
ID: zihaoch1
PROG: charrec
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std; 

string letter = " abcdefghijklmnopqrstuvwxyz"; 
int font[30][30][30]; 
int data[2000][30]; 
int dis[30][30][2000]; 
int cost[2000][4]; 
int path[2000][4]; 
int ans[50];
int g[2000], f[2000];
const int INF = 1000000;

int main()
{
	ifstream fin("font.in"); 
	ifstream cin("charrec.in"); 
	ofstream cout("charrec.out"); 
	
	int n;
	fin >> n;
	for (int i = 1; i <= 27; i++)
		for (int j = 1; j <= 20; j++)
		{
			for (int k = 1; k <= 20; k++)
				font[i][j][k] = fin.get(); 
			fin.get(); 
		}
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 20; j++)
			data[i][j] = cin.get(); 
		cin.get(); 
	}

	for (int i = 1; i <= 27; i++)
		for (int j = 1; j <= 20; j++)
			for (int k = 1; k <= n; k++)
				for (int t = 1; t <= 20; t++)
					dis[i][j][k] += (font[i][j][t] != data[k][t]); 

	for (int i = 1; i <= n; i++)
	{
		cost[i][1] = cost[i][2] = cost[i][3] = INF; 
		if (i + 18 <= n)
			for (int j = 1; j <= 27; j++)
			{
				int total = 0; 
				for (int k = 2; k <= 20; k++)
					total += dis[j][k][i + k -2]; 
				if (total < cost[i][1])
				{
					cost[i][1] = total; 
					path[i][1] = j; 
				}
				for (int k = 2; k <= 20; k++)
				{
					total -= dis[j][k][i + k - 2]; 
					total += dis[j][k - 1][i + k - 2]; 
					if (total < cost[i][1])
					{
						cost[i][1] = total; 
						path[i][1] = j; 
					}
				}
			}

		if (i + 19 <= n)
			for (int j = 1; j <= 27; j++)
			{
				int total = 0; 
				for (int k = 1; k <= 20; k++)
					total += dis[j][k][i + k -1]; 
				if (total < cost[i][2])
				{
					cost[i][2] = total;  
					path[i][2] = j; 
				}
			}

		if (i + 20 <= n)
			for (int j = 1; j <= 27; j++)
			{
				int total = dis[j][1][i]; 
				for (int k = 2; k <= 20; k++)
					total += dis[j][k][i + k]; 
				if (total < cost[i][3])
				{
					cost[i][3] = total; 
					path[i][3] = j; 
				}
				for (int k = 2; k <= 20; k++)
				{
					total += dis[j][k][i + k - 1]; 
					total -= dis[j][k][i + k]; 
					if (total < cost[i][3])
					{
						cost[i][3] = total;  
						path[i][3] = j; 
					}
				}
			}
	}

	f[0] = 0; 
	for (int i = 1; i <= n; i++)
		f[i] = INF; 
	for (int i = 19; i <= n; i++)
	{
		if (i >= 19 && f[i] > f[i - 19] + cost[i - 18][1])
		{
			f[i] = f[i - 19] + cost[i - 18][1]; 
			g[i] = 19; 
		}
		if (i >= 20 && f[i] > f[i - 20] + cost[i - 19][2])
		{
			f[i] = f[i - 20] + cost[i - 19][2]; 
			g[i] = 20; 
		}
		if (i >= 21 && f[i] > f[i - 21] + cost[i - 20][3])
		{
			f[i] = f[i - 21] + cost[i - 20][3]; 
			g[i] = 21; 
		}
	}

	int num = 0; 
	for (int i = n; i >= 1; i -= g[i])
		ans[num++] = path[i - g[i] + 1][g[i] - 18]; 

	for (int i = num - 1; i >= 0; i--)
		cout << letter[ans[i] - 1]; 
	cout << endl; 


}

