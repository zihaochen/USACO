/*
ID: zihaoch1
PROG: shuttle
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std; 

int n; 
vector<string> result; 
string s; 
string goal;
string action; 

void dfs(int hole, string action)
{
	if (s == goal)
	{
		result.push_back(action); 
		return;
	}
	for (int i = 0; i < hole;i++)
		if (i + 2 < s.size() && s[i] == '1' && s[i + 1] == '2' && s[i + 2] == '2')
			return;
	for (int i = hole; i < s.size(); i++)
		if (i - 2 >= 0 && s[i] == '2' && s[i - 1] == '1' && s[i - 2] == 1)
			return;
			
	if (hole > 0 && s[hole - 1] == '1')
	{
		swap(s[hole], s[hole -1]); 
		dfs(hole - 1, action + (char)(hole - 1 + '1'));
		swap(s[hole], s[hole - 1]); 
	}
	if (hole < s.size() - 1 && s[hole + 1] == '2')
	{
		swap(s[hole], s[hole + 1]); 
		dfs(hole + 1, action + (char)(hole + 1 + '1')); 
		swap(s[hole], s[hole + 1]); 
	}
	if (hole - 2 >= 0 && s[hole - 2] == '1' && s[hole - 1] == '2')
	{
		swap(s[hole - 2], s[hole]); 
		dfs(hole - 2, action + (char)(hole - 2 + '1')); 
		swap(s[hole - 2], s[hole]); 
	}
	if (hole + 2 <= s.size() - 1 && s[hole + 2] == '2' && s[hole + 1] == '1')
	{
		swap(s[hole + 2], s[hole]); 
		dfs(hole + 2, action + (char)(hole + 2 + '1')); 
		swap(s[hole + 2], s[hole]); 
	}
	return; 
}

int main()
{
	ifstream cin("shuttle.in"); 
	ofstream cout("shuttle.out"); 
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		goal += '2'; 
		s += '1'; 
	}
	s += '0'; 
	goal += '0';
	for (int i = 0; i < n; i++)
	{
		s += '2'; 
		goal += '1'; 
	}
	dfs(n, action); 
	string tmp = result[0]; 
	for (int i = 0; i < result.size(); i++)
	{
		if (tmp.compare(result[i]) > 0)
			tmp = result[i]; 
	}
	for (int i = 0; i < tmp.size() - 1; i++)
	{
		if (i % 20 == 19)
			cout << (int) (tmp[i] - '0')<< endl; 
		else
			cout << (int) (tmp[i] - '0') << ' '; 
	}
	cout << (int) (tmp[tmp.size() - 1] - '0') << endl; 
}

