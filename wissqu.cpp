/*
ID: zihaoch1
PROG: wissqu
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<vector>
#define debug cout<<"not here\n"
using namespace std; 

int cow[6] = {3, 3, 3, 4, 3}; 
int di[8] = {0, 0, 1, -1, 1, 1, -1, -1}; 
int dj[8] = {1, -1, 0, 0, 1, -1, 1, -1}; 
bool visited[6][6];
vector<string> result; 
string path; 
char a[6][6]; 

void search(string path)
{
	bool flag = 0; 
	for (int i = 0; i < 5; i++)
		if (cow[i]) flag = 1; 
	if (flag == 0) 
	{
		result.push_back(path); 
		return; 
	}
	for (int c = 0; c < 5; c++)
	{
		if(cow[c] == 0) continue;
		char tmp = (char)(c + 'A'); 
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				if (a[i][j] == tmp) continue;
				if (visited[i][j]) continue;
				flag = 0; 
				for (int t = 0; t < 8; t++)
				{
					int tmpI = i + di[t]; 
					int tmpJ = j + dj[t]; 
					if (!(tmpI >= 1 && tmpI <= 4 && tmpJ >= 1 && tmpJ <= 4)) continue; 
					if (a[tmpI][tmpJ] == tmp)
					{
						flag = 1; 
						break; 
					}
				}
				if (flag == 0)
				{
					cow[c]--; 
					char tmpChar= a[i][j]; 
					a[i][j] = tmp; 
					visited[i][j] = 1;
					search(path + tmp + (char)(i + '0') + (char)(j + '0')); 
					cow[c]++; 
					a[i][j] = tmpChar;
					visited[i][j] = 0; 
				}
			}
	}
}

int main()
{
	ifstream cin("wissqu.in"); 
	ofstream cout("wissqu.out"); 
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
			cin >>a[i][j];
		cin.get(); 
	}

	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
		{
			bool flag = 0; 
			if (a[i][j] == 'D') continue;
			for (int t = 0; t < 8; t++)
			{
				int tmpI = i + di[t]; 
				int tmpJ = j + dj[t]; 
				if (!(tmpI >= 1 && tmpI <= 4 && tmpJ >= 1 && tmpJ <= 4)) continue; 
				if (a[tmpI][tmpJ] == 'D')
				{
					flag = 1; 
					break; 
				}
			}
			if (flag == 0)
			{
				cow[(int)('D' - 'A')]--;
				char tmp = a[i][j]; 
				a[i][j] = 'D'; 
				visited[i][j] = 1;
				search(path + 'D' + (char)(i + '0') + (char)(j + '0')); 
				cow[(int)('D' - 'A')]++; 
				a[i][j] = tmp; 
				visited[i][j] = 0;
			}
		}
	string tmpMin = result[0]; 
	for (int i = 0; i < result.size(); i++)
		if (result[i] < tmpMin)
			tmpMin = result[i]; 

	for (int i = 0; i < tmpMin.size(); i++)
	{
		if (i % 3 != 2) cout << tmpMin[i] <<  ' '; 
		else cout << tmpMin[i] << endl; 
	}

	cout << result.size() << endl; 
}

