/*
ID: zihaoch1
PROG: snail
LANG: C++
*/
#include<iostream>
#include<fstream>
#define beyondBound(x, y) (!(x >= 1 && x <= n && y >= 1 && y <= n))
using namespace std; 

enum gird{EMPTY, VISITED, BARRIER}; 
int di[4] = {0, 0, -1, 1}; 
int dj[4] = {1, -1, 0, 0}; 
int a[150][150]; 
int n, m, maxNum; 

void dfs(int i, int j, int direction, int num)
{
	//cout<<i<< ' '<<j << ' '<<num<<endl;
	a[i][j] = VISITED; 
	int tmp = a[i + di[direction]][j + dj[direction]]; 
	if (tmp == EMPTY && (!beyondBound(i + di[direction], j + dj[direction])))
	{
		dfs(i + di[direction], j + dj[direction], direction, num + 1); 
		a[i + di[direction]][j + dj[direction]] = EMPTY;
		return; 
	}
	bool flag = 0; 
	if (tmp == BARRIER|| beyondBound(i + di[direction], j + dj[direction]))
	{
		for (int t = 0; t < 4; t++)
		{
			if (t == direction) continue; 
			int tmp2 = a[i + di[t]][j + dj[t]]; 
			if (tmp2 != EMPTY || beyondBound(i + di[t], j + dj[t]))
				continue; 
			flag = 1; 
			dfs(i + di[t], j + dj[t], t, num + 1); 
			a[i + di[t]][j + dj[t]] = EMPTY; 
		}
	}
	if (tmp == VISITED || flag == 0)
	{
		maxNum = max(maxNum, num); 
		return; 
	}
}

int main()
{
	ifstream cin("snail.in"); 
	ofstream cout("snail.out"); 
	cin >> n >> m; 
	for (int i = 0; i < m; i++)
	{
		string tmp; 
		cin >> tmp; 
		int tmpJ = (int)(tmp[0] - 'A' + 1); 
		int tmpI = 0; 
		for (int t = 1; t < tmp.size(); t++)
			tmpI = tmpI * 10 + (int)(tmp[t] - '0'); 
		a[tmpI][tmpJ] = BARRIER; 
	}
	dfs(1, 1, 0, 1);
	dfs(1, 1, 2, 1);
	cout << maxNum << endl; 
}

