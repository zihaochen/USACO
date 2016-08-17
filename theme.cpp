/*
ID: zihaoch1
PROG: theme
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int a[6000]; 
int len[6000];
int main()
{
	ifstream cin("theme.in"); 
	ofstream cout("theme.out"); 

	int n, maxLen = 0; 
	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> a[i]; 
	for (int i = 1; i < n; i++)
	{
		len[i] = 1;
		a[i] = a[i + 1] - a[i]; 
	//	cout<<a[i]<< ' ';
	//	if (i % 20 == 0) cout<<endl;
	}
	//cout<<endl;
	for (int i =  1; i <= n - maxLen *  2; i++)
	{
		if (i + maxLen - 1 >= n - 1) break; 
	//	if (len[i] < maxLen) continue;
		for (int j = i + maxLen + 1; j < n; j++)
		{
			if (a[i] != a[j]) continue; 
			for (int length = 1; ;length++)
			{
				if (i + length >= j ) break; 
				if (j + length - 1 > n - 1) break; 
				if (a[i + length - 1] != a[j + length - 1]) break; 
				maxLen = max(length, maxLen); 
				len[i] = max(length, len[i]);
			}
		}
	}
	if (maxLen >= 4)
		cout << maxLen + 1 << endl; 
	else cout<<0<<endl;
}

