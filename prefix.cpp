/*
ID: zihaoch1
PROG: prefix
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

string job, s[4000];
int num; 
int dp[400000]; //第i个位置开始向后符合的字符串长度，包括i

int main()
{
	ifstream cin("prefix.in"); 
	ofstream cout("prefix.out"); 
	string tmp; 
	while (tmp != ".")
	{
		cin >> tmp; 
		if (tmp != ".") s[num++] = tmp; 
	}
	string c;
	while (cin >> c)
		job += c;
	int len = job.size();  
	for (int i = len; i > 0; i--)
	{
		for (int j = 0; j < num; j++)
		{
			int tmpLen = s[j].size(); 
			if (i - tmpLen >= 0 && job.compare(i - tmpLen, tmpLen, s[j]) == 0)
				dp[i - tmpLen] = max(dp[i] + tmpLen, dp[i - tmpLen]); 
		}
	}
	cout << dp[0] << endl; 
}

