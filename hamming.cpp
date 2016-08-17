/*
ID: zihaoch1
PROG: hamming
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 
int n, b, d; 
int result[1000]; 

bool check(int x, int y)
{
	int cnt = 0; 
	for (int i = 0; i < b; i++)
		if (((x  >>  i) & 1) != ((y >> i) & 1)) cnt++; 
	if (cnt >= d) return 1; 
	else return 0; 
}

int main()
{
	int cnt; 
	bool flag; 
	ifstream cin("hamming.in"); 
	ofstream cout("hamming.out"); 
	cin >> n >> b >> d; 
	cnt = 1; 
	result[1] = 0; 
	for (int i = 1; i < (2 << b); i++)
	{
		if (cnt == n) break; 
		flag = 1; 
		for (int j = 1; j <= cnt; j++)
			if (!check(i, result[j])) 
				{
					flag = 0;  break; 
				}		
		if (flag) result[++cnt] = i;
	}
	for (int i = 1; i < cnt; i++)
		cout << result[i] << ((i % 10 == 0) ? "\n" : " "); 
	cout << result[cnt] << endl; 
}

