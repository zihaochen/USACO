/*
ID: zihaoch1
PROG: buylow
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std; 

struct BigInteger
{
	int s[500];
	int size;
	
	void plus (BigInteger &x1)
	{
		for (int i = 0; i < max(size, x1.size); i++)
			s[i] = s[i] + x1.s[i];
		for (int i = 0; i < max(size, x1.size); i++)
		{
			s[i + 1] += s[i] / 10;
			s[i] = s[i] % 10;
		}
		if (s[max(size, x1.size)] != 0)
			size = max(size, x1.size) + 1;
		else
			size = max(size, x1.size);
	}
	
	BigInteger& operator = (const BigInteger &x1)
	{
		memset(s, 0, sizeof(s));
		size = x1.size;
		for (int i = 0;i < size;i++)
			s[i] = x1.s[i]; 
		return (*this);
	}
	
	BigInteger()
	{
		size = 0;
	}
} num[5003];

long long f[5003], a[5003], next[5003];
int main()
{
	ifstream cin("buylow.in"); 
	ofstream cout("buylow.out"); 
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n;j++)
		{
			if (a[j] == a[i])
			{
				next[i] = j;
				break;
			}
		}
	f[0] = 1;
	num[0].size = 1;
	num[0].s[0] = 1; 
	int Max = 1; 
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1; 
		num[i].size = 1;
		num[i].s[0] = 1;
		for (int j = 0; j < i; j++)
		{
			if (i > next[j] && next[j] != 0) continue;
			if (a[j] > a[i] && f[i] == f[j] + 1)
				num[i].plus(num[j]);
			if (a[j] > a[i] && f[i] < f[j] + 1) 
			{
				f[i] = max(f[j] + 1, f[i]); 
				num[i] = num[j];
			}
		}
	}
	
	cout << f[n] - 1 << ' ' ;
	for (int i = num[n].size - 1; i >= 0; i--)
		cout<<num[n].s[i];
	cout<<endl; 
}

