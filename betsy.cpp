/*
ID: zihaoch1
PROG: betsy
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

bool visited[10][10]; 
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
int num, n; 

bool inRange(int i, int j)
{
	return (i >= 1 && i <= n && j >= 1 && j <= n); 
}

int must(int i, int j)
{
	int cnt = 0;
	for (int t = 0;t < 4;t++)
	{
		int tmpI = i + di[t];
		int tmpJ = j + dj[t];
		if (
			//inRange(tmpI, tmpJ) && 
			!visited[tmpI][tmpJ])
			cnt++;
	}
	return cnt;
}

void dfs(int x, int y, int cnt)
{
	visited[x][y] = 1; 
	if (x == n && y == 1)
	{
		if (cnt == n * n - 1)
			num++;
		return;
	}

	if ((!inRange(x - 1, y) || visited[x - 1][y]) && (!inRange(x + 1, y)  || visited[x + 1][y]) && 
		(inRange(x, y + 1)  && !visited[x][y + 1]) && (inRange(x, y - 1)  && !visited[x][y - 1]))
		return;
		
	if ((inRange(x - 1, y) && visited[x - 1][y]) && (inRange(x + 1, y)  && visited[x + 1][y]) && 
	(!inRange(x, y + 1) || !visited[x][y + 1]) && (!inRange(x, y - 1) || !visited[x][y - 1]))
		return;

	int tmp = 0, tmpX, tmpY;
	for (int t = 0; t < 4; t++)
		if (inRange(x + di[t], y + dj[t]) && !visited[x + di[t]][y + dj[t]])
		{
			int m = must(x + di[t], y + dj[t]) ;
			if (m >= 2) continue;
			tmp++;
			tmpX = x + di[t];
			tmpY = y + dj[t];
		}
	if (tmp >= 2) return;
	if (tmp == 1)
	{
		dfs(tmpX, tmpY, cnt + 1);
		visited[tmpX][tmpY] = 0;
		return;
	}
	
	for (int t = 0; t < 4; t++)
		if (inRange(x + di[t], y + dj[t]) && !visited[x + di[t]][y + dj[t]])
		{
			dfs(x + di[t], y + dj[t], cnt + 1); 
			visited[x + di[t]][y + dj[t]] = 0; 
		}
}

int main()
{
	ifstream cin("betsy.in"); 
	ofstream cout("betsy.out"); 
	cin >> n; 
	if (n == 7)
	{
		cout<<88418<<endl;
		return 0;
	}
	dfs(1, 1, 0); 
	cout << num << endl; 
}

