/*
ID: zihaoch1
PROG: comehome
LANG: C++
*/
#include<iostream>
#include<fstream>
#define debug cout<<"not here\n"
using namespace std; 

const int MAX_INT = 10000000; 
int a[100][100]; 
int d[100]; 
bool visited[100]; 

int main()
{
	ifstream cin("comehome.in"); 
	ofstream cout("comehome.out"); 
	int n; 
	cin >> n; 

	for (int i = 0; i < 58; i++)
		for (int j = 0; j < 58; j++)
			a[i][j] = MAX_INT;

	char ch1, ch2; 
	int x; 
	for (int i = 0; i < n; i++)
	{
		cin >> ch1 >> ch2 >> x; 
		x = min(a[ch1 - 'A'][ch2 - 'A'], x); 
		a[ch1 - 'A'][ch2 - 'A'] = a[ch2 - 'A'][ch1 - 'A'] = x; 
	} 
	
	for (int i = 0; i <= 57;i++)
	{
		if (a[25][i] < MAX_INT)
			d[i] = a[25][i]; 
		else 
			d[i] = MAX_INT; 
	}
	d[25] = 0;
	visited[25] = 1; 
	for (int t = 0; t <= 57; t++)
	{
		int tmp = MAX_INT; 
		int index; 
		for (int i = 0; i <= 57; i++)
			if (visited[i] == 0 && tmp > d[i])
			{
				tmp = d[i]; 
				index = i; 
			}
		visited[index] = 1; 
		for (int i = 0; i <= 57; i++)
			if (visited[i] == 0)
				d[i] = min(d[i], d[index] + a[i][index]); 
	}

	int tmp = MAX_INT; 
	int index; 
	for (int i = 0; i < 25; i++)
	{
		if (tmp > d[i] && i != 25)
		{
			tmp = d[i]; 
			index = i; 
		}
	}
	char result = index + 'A';
	cout << result <<' '<< d[index] << endl; 
	
}

