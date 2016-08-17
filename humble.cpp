/*
ID: zihaoch1
PROG: humble
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<set>
using namespace std; 

int p[100002]; 
int n, m; 

int main()
{
	ifstream cin("humble.in"); 
	ofstream cout("humble.out"); 
	
	set<int> s; 

	cin >> n >> m; 
	for (int i = 0; i < n; i++)
	{
		cin >> p[i]; 
		s.insert(p[i]); 
	}

	for (int i = 0; i < n; i++)
	{
		set<int>::iterator itr = s.begin(); 
		int tmp; 
		while (1)
		{
			tmp = *(itr) * p[i]; 
			if (tmp < 0) break;
			if (s.size() > m)
			{
				s.erase(--s.end()); 
				if (tmp > *(--s.end())) break; 
			}
			s.insert(tmp); 
			itr++; 
		}
	}

	cout << *(--s.end()) << endl; 
}


