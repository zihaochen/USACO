/*
ID: zihaoch1
PROG: stamps
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std; 

const int MAX = 2000000;
const int INF = 100000000; 
int f[3000000], p[300]; 

int main()
{
	int n, k; 
	ifstream cin("stamps.in"); 
	ofstream cout("stamps.out"); 
	cin >> n >> k; 
	for (int i = 0; i < k; i++)
		cin >> p[i]; 
	fill_n(f, 3000000, INF);  
	f[0] = 0;
		for (int j = 0; j < MAX; j++)
			for (int t = 0; t < k; t++)
				if (j - p[t] >= 0) 
					f[j] = min(f[j], f[j - p[t]] + 1 ); 
	for (int i = 1; i <= MAX; i++)
		if (f[i] > n)
		{
			cout << i - 1<< endl; 
			return 0; 
		}

}

