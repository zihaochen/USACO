/*
ID: zihaoch1
PROG: milk4
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std; 

int p[150]; 
vector<int> v[20003]; 

bool operator < (const vector<int> &a, const vector<int> &b)
{
	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); i++)
			if (a[i] < b[i]) return 1; 
			else if (a[i] > b[i]) return 0; 
	}
	return (a.size() < b.size()); 
}

int main()
{
	int q, P; 
	ifstream cin("milk4.in"); 
	ofstream cout("milk4.out"); 
	cin >> q; 
	cin >> P; 
	for (int i = 0; i < P; i++)
		cin >> p[i]; 

	for (int i = 0; i < P; i++)
		for (int j = 0; j <= q; j++)
		{
			for (int s = 1; s * p[i]  + j <= q; s++)
			{
				int pp = s * p[i];
				if (j + pp > q) continue; 
				if (v[j].size() == 0 && j > 0) continue;
				vector<int> tmp = v[j];
				bool flag = 0;
				for (int t = 0; t < tmp.size(); t++)
					if (tmp[t] == p[i])
					{
						flag = 1;
						break;
					} 
				if (!flag)
				{
					 tmp.push_back(p[i]);
					sort(tmp.begin(),tmp.end()); 
				}
				if (v[j + pp].size() == 0) v[j + pp] = tmp; 
				else if (tmp < v[j+ pp])
						v[j + pp] = tmp; 
			}
		}
//	for (int i = 0; i <= q;i++)
//	{
//		cout<<i<< ":  ";
//		for (int j  = 0;j < v[i].size();j++)
//			cout<<v[i][j]<< ' ';
//		cout<<endl;
//	}
	
	cout << v[q].size() << ' '; 
	for (int i = 0; i < v[q].size() - 1; i++)
		cout << v[q][i] <<  ' '; 
	cout << v[q][v[q].size() - 1] << endl; 
}

