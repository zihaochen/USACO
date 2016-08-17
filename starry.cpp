/*
ID: zihaoch1
PROG: starry
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std; 

struct node
{
	int i, j; 
} p[200]; 

int a[200][200];
double h[600]; 
int di[8] = {0, 0, 1, -1, 1, 1, -1, -1}; 
int dj[8] = {1, -1, 0, 0, 1, -1, 1, -1}; 
int num;

double dist(const node &a, const node &b)
{
	double tmp; 
	tmp = (double) sqrt((a.i - b.i) * (a.i - b.i) + (a.j - b.j) * (a.j - b.j)); 
	return tmp; 
}

void floodfill(int i, int j)
{
	p[num].i = i; 
	p[num].j = j; 
	num++; 
	a[i][j] = 0; 
	for (int t = 0; t < 8; t++)
		if (a[i + di[t]][j + dj[t]] == 1)
			floodfill(i + di[t], j + dj[t]); 
}

int main()
{
	ifstream cin("starry.in"); 
	ofstream cout("starry.out"); 
	int W, H; 
	cin >> W >> H; 
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			char ch;
			cin >> ch;
			a[i][j] = (int) (ch - '0');
		}
		cin.get();
	}

	int now = 0;

	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
		{
			if (a[i][j] == 0) continue;
			num = 0; 
			double hash = 0; 
			if (a[i][j] == 1) floodfill(i, j); 
			for (int i = 0; i < num; i++)
				for (int j = i + 1; j < num; j++)
					hash += dist(p[i], p[j]); 
			int flag = 0; 
			for (int i = 1; i <= now; i++)
				if (fabs(hash - h[i]) < 1e-6)
				{
					flag = i; 
					break; 
				}
			if (flag)
			{
				for (int t = 0; t < num; t++)
					a[p[t].i][p[t].j] = flag;
				continue; 
			}
			now++; 
			h[now] = hash; 
			for (int t = 0; t < num; t++)
				a[p[t].i][p[t].j] = now; 
		}

	for (int i  = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (a[i][j] == 0) cout << 0; 
			else cout << (char) (a[i][j] + 'a' - 1); 
		}
		cout << endl; 
	}
}

