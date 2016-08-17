/*
ID: zihaoch1
PROG: nuggets
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#define debug cout<<"not here\n"
using namespace std; 

int a[20]; 
int n; 
int d[300];
int r[300];
bool visited[300];
const int INF = 200000000;

int dijkstra()
{
	d[0] = 0;
	visited[0] = 1;
	int tmpMin;
	int tmpIndex;
	for (int i = 1; i < a[0]; i++)
		d[i] = r[i];
	for (int i = 0; i < a[0] - 1; i++)
	{
		tmpMin = INF;
		for (int j = 1; j < a[0]; j++)
			if (d[j] < tmpMin && visited[j] == 0)
			{
				tmpMin = d[j];
				tmpIndex = j;
			}
		visited[tmpIndex] = 1;
		for (int j = 1; j < a[0]; j++)
			if (visited[j] == 0 && d[j] > d[tmpIndex] + r[(j > tmpIndex) ? j - tmpIndex : ((j - tmpIndex + a[0]) % a[0])])
					d[j] = d[tmpIndex] + r[(j > tmpIndex) ? j - tmpIndex : ((j - tmpIndex + a[0]) % a[0])];
	}
	int result = 0;
	for (int i = 0; i < a[0]; i++)
		result = max(d[i], result);
		
	return result;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b) ;
}

int main()
{
	ifstream cin("nuggets.in"); 
	ofstream cout("nuggets.out"); 
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	sort(a, a + n); 
	if (a[0] == 1)
	{
		cout << 0 << endl; 
		return 0; 
	}
	for (int i = 1; i < n; i++)
	{
		if (gcd(a[i] % a[0] % 2, a[0]) == 1) break; 
		if (i == n - 1)
		{
			cout << 0 << endl; 
			return 0; 
		}
	}

	for (int i = 0;i < a[0];i++)
		r[i] = INF;
	for (int i = 0; i < n; i++)
		r[a[i] % a[0]] = min(r[a[i] % a[0]], a[i]);
	
	cout << dijkstra() - a[0] << endl;
}

