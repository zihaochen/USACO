/*
ID: zihaoch1
PROG: fence
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int n, minIndex = 100000, maxIndex, num; 
int rec[10000]; 
int a[600][600];
int d[600];

void euler(int index)
{
	for (int i = minIndex; i <= maxIndex; i++)
		if (a[i][index] > 0)
		{		
			a[i][index]--; a[index][i]--; 
			euler(i); 
		}
	rec[num++] = index; 
}

int main()
{
	ifstream cin("fence.in"); 
	ofstream cout("fence.out"); 
	
	cin >> n; 
	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y; 
		d[x]++;
		d[y]++;
		a[x][y]++; a[y][x]++;
		minIndex = min(minIndex, min(x, y)); 
		maxIndex = max(maxIndex, max(x, y)); 
	}
	
	int tmp = 0;
	for (int i = minIndex;i <= maxIndex;i++)
		if (d[i] % 2 == 1)
		{
			tmp = i;
			break;
		}
		
	if (tmp == 0)	euler(minIndex);
		else  euler(tmp);
	
	for (int i = num - 1; i >= 0; i--)
		cout << rec[i] << endl; 
}

