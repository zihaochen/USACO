/*
ID: zihaoch1
PROG: spin
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int sp[7], num[7], tmpos[7]; 
int pos[7][400], len[7][400]; 
int cnt;

bool interact(int a, int b, int c, int d)
{
	if (b < a) b += 360;
	if (c < d) c += 360;
	return (a <= c && c <= b || c <= a && a <= d);
}

bool dfs(int index, int begin, int end)
{
	//if (cnt == 357) cout<<index<<' '<<begin<< ' '<<end<<endl;
	if (index == 5) return 1; 
	bool flag = 0; 
	for (int i = 0; i < num[index + 1]; i++)
	{
		int k1, k2; 
		k1 = (pos[index + 1][i] + tmpos[index + 1]) % 360; 
		k2 = k1 + len[index + 1][i]; 
		//if (cnt == 357) cout<<"k1"<<k1<<" k2"<<k2<<endl;
		if (end < begin) end += 360;
		if (k2 < k1) k2 += 360;
		if (k2 >= 360 && end < 360)
		{
			begin += 360;
			end += 360;
		}
		if (end >= 360 && k2 < 360)
		{
			k1 += 360;
			k2 += 360;
		}
		if (!((begin <= k1 && k1 <= end) || (k1 <= begin && begin <= k2))) continue;
		if (dfs(index + 1, max(begin, k1) % 360, min(end, k2) % 360)) flag = 1;
		
 	}
	return flag; 
}

int main()
{
	ifstream cin("spin.in"); 
	ofstream cout("spin.out"); 
	for (int i = 1; i <= 5; i++)
	{
		cin >> sp[i] >> num[i]; 
		for (int j = 0; j < num[i]; j++)
			cin >> pos[i][j] >> len[i][j];
	}
 
	for (cnt = 0; ; cnt++)
	{
		if (cnt >= 2000) 
		{
			cout<<"none"<<endl;
			return 0;
		}
		for (int j = 1; j <= 5; j++)
			tmpos[j] = (sp[j] * cnt) % 360; 
		if (dfs(0, 0, 359 * 2)) break; 
	}

	cout << cnt << endl; 
}

