/*
ID: zihaoch1
PROG: rect1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int a, b, n, x1[2502], x2[2502], y1[2502], y2[2502], area[2502], color[2502]; 

void cover(int i1, int j1, int i2, int j2, int floor, int col)
{
	while (floor <= n && (i2 <= x1[floor] || i1 >= x2[floor] || j2 <= y1[floor] || j1 >= y2[floor]))
		floor++; 
	if (floor == n + 1)
	{
		area[col] += (i2 - i1) * (j2 - j1); 
		return;
	}
		if (i1 < x1[floor])
		{ 
			cover(i1, j1, x1[floor], j2, floor + 1, col);
			i1 = x1[floor]; 
		}
		if (i2 > x2[floor])
		{
			cover(x2[floor], j1, i2, j2, floor + 1, col);
			i2 = x2[floor]; 
		}
		if (j2 > y2[floor])
		{
			cover(i1, y2[floor], i2, j2, floor + 1, col);
			j2 = y2[floor]; 
		}
		if (j1 < y1[floor])
		{
			cover(i1, j1, i2, y1[floor], floor + 1, col);
			j1 = y1[floor]; 
		}
}

int main()
{
	ifstream cin("rect1.in"); 
	ofstream cout("rect1.out"); 
	cin >> a >> b >> n; 
	x1[0] = y1[0] = 0; 
	x2[0] = a; 
	y2[0] = b; 
	color[0] = 1;
	for (int i = 1; i <= n; i++)
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i] >> color[i]; 
	for (int i = n; i >= 0; i--)
		cover(x1[i], y1[i], x2[i], y2[i], i + 1, color[i]); 
	for (int i = 0; i < 2501; i++)
		if (area[i])
			cout << i << ' ' << area[i] << endl; 
}

