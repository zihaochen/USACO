/*
ID: zihaoch1
PROG: runround
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int a[15], b[15], num[15];
bool flag[15];

bool check(int n)
{
	int length = 0; 
	for (int i = 0; i < 10; i++)
		num[i] = 0;
	while (n > 0)
	{
		a[length++] = n % 10;
		num[n % 10]++; 
		n /= 10; 
	}
	for (int i = 0; i < 10; i++)
		if (num[i] > 1) return 0;
		
	for (int i = 0; i < length; i++)
		b[i] = a[length - 1 - i]; 
	
	int cursor = 0; 
	for (int i = 0; i < length; i++)
		flag[i] = 0;
		
	while (1)
	{
		bool tmp = 1;
		for (int i = 0; i < length; i++)
			tmp = tmp && flag[i];
		if (tmp == 1) break;
		if (flag[cursor] == 1) return 0;
			else flag[cursor] = 1;
		cursor = (cursor + b[cursor]) % length;
	}
	return (cursor == 0); 
}

int main()
{
	int n; 
	ifstream cin("runround.in"); 
	ofstream cout("runround.out"); 
	cin >> n; 
	n++;
	while (!check(n)) n++; 
	cout << n << endl; 
}

