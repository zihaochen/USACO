/*
ID: zihaoch1
PROG: milk
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int divide(int, int); 
void qsort(int, int); 

int p[6000], a[6000]; 

int main()
{
int n, m, i, tmp, sum = 0; 	
	ifstream fin("milk.in"); 
	ofstream fout("milk.out"); 
	fin >> n >> m; 
	for (i = 0; i < m ; i++)
		fin >> p[i]  >> a[i]; 
	qsort(0, m - 1);
	i = 0; 
	while (n > 0)
	{
		if (a[i] > 0)
		{
			tmp = a[i]; 
			a[i] = max(0, a[i] - n); 
			n = n - (tmp - a[i]); 
			sum += (tmp - a[i]) * p[i]; 
		}
		i++; 
	}
	cout << sum << endl; 
}

int divide(int low, int high)
{
	int k = p[low]; 
	int q = a[low]; 
	while (low < high)
	{
		while (low < high && p[high] >= k)
			high--; 
		if (low < high)
		{
			p[low] = p[high]; 
			a[low] = a[high];
		}
		while (low < high && p[low] <= k)
			low++; 
		if (low < high)
		{
			p[high] = p[low]; 
			a[high] = a[low]; 
		}
	}
	p[low] = k; 
	a[low] = q; 
	return low; 
}

void qsort(int low, int high)
{
	if (low >= high) return; 
	int mid = divide(low, high); 
	qsort(low, mid); 
	qsort(mid + 1, high); 
}

