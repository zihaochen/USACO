/*
ID: zihaoch1
PROG: money
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int m[30]; 
long long dp[10005][30]; //只用前j种货币来分配i元 

int main()
{
	int v, n; 
	ifstream cin("money.in"); 
	ofstream cout("money.out"); 
	cin >> v >> n; 
	for (int i = 1; i <= v; i++)
	{
		dp[0][i] = 	1;
		cin >> m[i]; 
	}
	dp[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 1; j <= v; j++)
		{
			for (int k = 0; i - k*m[j] >= 0;k++)
				dp[i][j] += dp[i - k*m[j]][j - 1];
		} 
 	cout<<dp[n][v]<<endl;

}

