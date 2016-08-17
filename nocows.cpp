/*
ID: zihaoch1
PROG: nocows
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int dp[200][100]; 

int main()
{
	int n, k; 
	ifstream cin("nocows.in"); 
	ofstream cout("nocows.out"); 
	cin >> n >> k; 
	for (int i = 1;i <= k;i++)
		dp[1][i] = 1;
	//for (int i = 1; i <= k;i++)
	//	dp[0][i] = 1;
	for (int a = 2; a <= k; a++)
		for (int b = 1; b <= n;b += 2)
			for (int c = 1; c < b - 1; c++)
				dp[b][a] = (dp[b][a] + dp[b - 1 - c][a - 1] * dp[c][a - 1]) % 9901;
	cout << (dp[n][k] - dp[n][k - 1] + 9901) % 9901 << endl; 

}

