/*
ID: zihaoch1
PROG: picture
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<algorithm>
#define debug cout<<"not here\n"
#define bung {cout<<"bang\n"; return 0;}
using namespace std; 

struct node
{
	int base, s, e; 
	bool start; 
}; 

bool cmp(const node &a, const node &b)
{
	return (a.base < b.base || a.base == b.base && a.start > b.start);
}

vector<node> ex, ey; 
int n; 
const int balance = 10000 + 5; 
int level[balance * 3]; 
int ans; 

void scan(const vector<node> &a)
{
	memset(level, 0, sizeof(level)); 
	for (int i = 0; i < a.size(); i++)
	{
		node tmp = a[i];
		if (tmp.start)
			for (int j = tmp.s; j < tmp.e; j++)
			{
				level[j + balance]++; 
				if (level[j + balance] == 1) ans++; 
			}
		else
			for (int j = tmp.s; j < tmp.e; j++)
			{
				level[j + balance]--; 
				if (level[j + balance] == 0) ans++; 
			}
	}
}

int main()
{
	ifstream cin("picture.in"); 
	ofstream cout("picture.out"); 
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		node tmp1, tmp2, tmp3, tmp4; 
		int ui, uj, di, dj; 
		cin >> di >> dj >> ui >> uj; 
		tmp1.s = di; tmp1.e = ui; tmp1.base = uj; tmp1.start = 0; 
		ey.push_back(tmp1); 
		tmp2.s = di; tmp2.e = ui; tmp2.base = dj; tmp2.start = 1;  
		ey.push_back(tmp2); 
		tmp3.s = dj; tmp3.e = uj; tmp3.base = ui; tmp3.start = 0; 
		ex.push_back(tmp3); 
		tmp4.s = dj; tmp4.e = uj; tmp4.base = di; tmp4.start = 1; 
		ex.push_back(tmp4); 
	}
	
	sort(ex.begin(), ex.end(), cmp); 
	sort(ey.begin(), ey.end(), cmp); 
	
	scan(ex); 
	scan(ey); 

	cout << ans << endl; 
}

