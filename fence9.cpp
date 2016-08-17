/*
ID: zihaoch1
PROG: fence9
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std; 

int main()
{
	ifstream coioin("fence9.in"); 
	ofstream cout("fence9.out"); 
	int m, n, p, sum = 0; 
	cin >> n >> m >> p; 
	for (int y = 1; y < m; y++)
	{
		int tmp1 = (int) floor((double) (n - p) * y / m + p); 
		int tmp2 = (int) ceil( (double)n * y / m); 
		if (tmp2 * m == n * y) tmp2++;
		if ((tmp1 - p) * m == (n - p) * y) tmp1--;
		sum += tmp1 - tmp2 + 1; 
	}
	cout << sum << endl;
}

