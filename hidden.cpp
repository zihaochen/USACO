/*
ID: zihaoch1
PROG: hidden
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std; 
string s; 
vector<int> v; 


int main()
{
	ifstream cin("hidden.in"); 
	ofstream cout("hidden.out"); 
	int n; 
	cin >> n; 
	string tmp; 
	while (cin >> tmp)
		s += tmp; 
	int i = 0, j = 1, k = 0;
	while (i < n && j < n && k < n)
	{
		int tmp = (int) (s[(i + k) % n] - s[(j + k) % n]);
		if (tmp == 0)
			k++;
		else
		{
			if (tmp > 0)
			{
				i += k + 1;
				k = 0;
			}
			else
			{
				j += k + 1;
				k = 0;
			}
			if (i == j) j++;
		}
	}
	cout<<min(i, j)<<endl;
}

