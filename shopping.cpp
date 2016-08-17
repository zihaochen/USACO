/*
ID: zihaoch1
PROG: shopping
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

const int INF = 100000;

struct node
{
	int n, v; 
	int s[6]; 
} p[100]; 
int dp[6][6][6][6][6]; 
int a[6]; 
int num; 
int price[6]; 
int cnt[6]; 

int find(int c)
{
	for (int i = 0; i < num; i++)
		if (a[i] == c) return i; 
	a[num++] = c; 
	return num - 1; 
}

int main()
{
	ifstream cin("shopping.in"); 
	ofstream cout("shopping.out");
	int s; 
	cin >> s; 
	for (int i = 1; i <= s; i++)
	{
		cin >> p[i].n; 
		for (int j = 0; j < p[i].n; j++)
		{
			int k, c; 
			cin >> c >> k; 
			p[i].s[find(c)] = k; 
		}
		cin >> p[i].v; 
	}
	int b; 
	cin >> b;
	for (int i = 1; i <= b; i++)
	{
		int c1, k1, p1; 
		cin >> c1 >> k1 >> p1;
		price[find(c1)] = p1; 
		cnt[find(c1)] = k1; 
	}

	for (int a0 = 0; a0 <= cnt[0]; a0++)
		for (int a1 = 0; a1 <= cnt[1]; a1++)
			for (int a2 = 0; a2 <= cnt[2]; a2++)
				for (int a3 = 0; a3 <= cnt[3]; a3++)
					for (int a4 = 0; a4 <= cnt[4]; a4++)
						for (int i = 0; i <= s; i++)
							dp[a0][a1][a2][a3][a4] = INF;
	dp[0][0][0][0][0]= 0;
							
	for (int a0 = 0; a0 <= cnt[0]; a0++)
		for (int a1 = 0; a1 <= cnt[1]; a1++)
			for (int a2 = 0; a2 <= cnt[2]; a2++)
				for (int a3 = 0; a3 <= cnt[3]; a3++)
					for (int a4 = 0; a4 <= cnt[4]; a4++)
						for (int i = 0; i <= s; i++)
						{
							if (a0 > 0)	
								dp[a0][a1][a2][a3][a4] = min(dp[a0][a1][a2][a3][a4], dp[a0 - 1][a1][a2][a3][a4] + price[0]);
							if (a1 > 0)
								dp[a0][a1][a2][a3][a4] = min(dp[a0][a1][a2][a3][a4], dp[a0][a1 - 1][a2][a3][a4] + price[1]);
							if (a2 > 0)
								dp[a0][a1][a2][a3][a4] = min(dp[a0][a1][a2][a3][a4], dp[a0][a1][a2 - 1][a3][a4] + price[2]);
							if (a3 > 0)
								dp[a0][a1][a2][a3][a4] = min(dp[a0][a1][a2][a3][a4], dp[a0][a1][a2][a3 - 1][a4] + price[3]);
							if (a4 > 0)
								dp[a0][a1][a2][a3][a4] = min(dp[a0][a1][a2][a3][a4], dp[a0][a1][a2][a3][a4 - 1] + price[4]);
							dp[a0][a1][a2][a3][a4] = min(dp[a0][a1][a2][a3][a4], \
								dp[max(0, a0 - p[i].s[0])][max(0, a1 - p[i].s[1])][max(0, a2 - p[i].s[2])]\
								[max(0, a3 - p[i].s[3])][max(0, a4 - p[i].s[4])]+ p[i].v); 
							//cout<<a0<<' '<<a1<<' '<<a2<<' '<<a3<<' '<<a4<<' '<<i<<" is"<<dp[a0][a1][a2][a3][a4][i]<<endl;
						}

	cout << dp[cnt[0]][cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl; 
}

