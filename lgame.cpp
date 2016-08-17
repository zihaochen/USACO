/*
ID: zihaoch1
PROG: lgame
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
using namespace std; 

int value[26] = {
	2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7
}; 
vector<string> sht, str; 
int tmpCnt[26]; 
int cnt[26]; 
int score[40000]; 
int num, maxScore; 


bool qualify(const string &x)
{
	memset(tmpCnt, 0, sizeof(tmpCnt)); 
	int len = x.size(); 
	for (int i = 0; i < len; i++)
	{
		tmpCnt[(int)(x[i] - 'a')]++; 
		if (tmpCnt[(int)(x[i] - 'a')] > cnt[(int)(x[i] - 'a')]) return 0; 
	}
	return 1; 
}

int Count(const string &x)
{
	int tmp = 0; 
	int len = x.size(); 
	for (int i = 0; i < len; i++)
		tmp += value[(int)(x[i] - 'a')]; 
	return tmp; 
}

int main()
{
	ifstream fin("lgame.dict"); 
	ifstream cin("lgame.in"); 
	ofstream cout("lgame.out");
	string s;
	cin >> s; 
	for (int i = 0; i < s.size(); i++)
		cnt[(int) (s[i] - 'a')]++; 
	while (1)
	{
		string tmp; 
		fin >> tmp; 
		if (tmp == ".") break; 
		if (qualify(tmp)) 
		{
			str.push_back(tmp); 
			score[num] = Count(tmp);
			maxScore = max(maxScore, score[num]); 
			num++; 
			if (tmp.size() <= 4) sht.push_back(tmp); 
		}
	}

	for (int i = 0; i < sht.size() - 1; i++)
		for (int j = i; j < sht.size(); j++)
		{
			string tmp; 
			tmp = sht[i] + sht[j]; 
			if (qualify(tmp)) maxScore = max(Count(tmp), maxScore); 
		}

	cout<<maxScore<<endl;
	for (int i = 0; i < str.size(); i++)
	{
		string tmp = str[i]; 
		if (Count(tmp) == maxScore)
		{
			cout << tmp << endl; 
			continue;
		}
		if (tmp.size() <= s.size() - 3)
		{
			for (int j = 0; j < sht.size(); j++)
			{
				if (sht[j] < tmp) continue; 
				string tmp2 = sht[j] + tmp; 
				if (qualify(tmp2) && Count(tmp2) == maxScore)
					cout << tmp << ' ' << sht[j] << endl; 
			}
		}
	}
}

