/*
ID: zihaoch1
PROG: twofive
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std; 

int n; 
int dp[6][6][6][6][6]; 
int maxRow[6], maxCol[6], col[6]; 
bool used[60]; 
//int ans = 0;

int dfs(int a, int b, int c, int d, int e, int ch)
{
	int tmp = dp[a][b][c][d][e]; 
	if (tmp != 0) return tmp; 
	if (used[ch]) return dfs(a, b, c, d, e, ch + 1); 
	if(a < 5 && ch > maxRow[0] && ch > maxCol[a])
		tmp += dfs(a + 1, b, c, d, e, ch + 1);
	if(b < a && ch > maxRow[1] && ch > maxCol[b])
		tmp += dfs(a, b + 1, c, d, e, ch + 1);
	if(c < b && ch > maxRow[2] && ch > maxCol[c])
		tmp += dfs(a, b, c + 1, d, e, ch + 1);
	if(d < c && ch > maxRow[3] && ch > maxCol[d])
		tmp += dfs(a, b, c, d + 1, e, ch + 1);
	if(e < d && ch > maxRow[4] && ch > maxCol[e])
		tmp += dfs(a, b, c, d, e + 1, ch + 1);
	dp[a][b][c][d][e] = tmp;
	return tmp; 
}

void place(int i, int j, int ch)
{
	memset(dp, 0, sizeof(dp)); 
	dp[5][5][5][5][5] = 1; 
	maxRow[i] = maxCol[j] = ch; 
	used[ch] = 1; 
}

int main()
{
	ifstream cin("twofive.in"); 
	ofstream cout("twofive.out"); 

	char op; 
	cin>>op;
	if (op == 'N')
	{
		cin >> n;
		memset(maxRow, -1, sizeof(maxRow)); 
		memset(maxCol, -1, sizeof(maxCol)); 
		int ans = 0;
		for (int i = 0; i < 25; i++)
		{
			col[i/5]++; 
			int j; 
			for (j = 0; j < 25; j++)
			{
				if (!used[j] && j > maxCol[i % 5] && j > maxRow[i / 5])
				{
					place(i / 5, i % 5, j); 
					int tmp = dfs(col[0], col[1], col[2], col[3], col[4], 0); 
					if (ans + tmp >= n) break; 
					ans += tmp; 
					used[j] = 0; 
				}
			}
			cout << (char)(j + 'A'); 
		}
		cout << endl; 
	}
	if (op == 'W')
	{
		string s; 
		cin >> s; 
		int ans = 0; 
		for (int i = 0; i < 25; i++)
		{
			col[i/5]++; 
			int tmp; 
			for (tmp = 0; tmp < (int)(s[i] - 'A'); tmp++)
			{
				if (!used[tmp] && tmp > maxCol[i % 5] && tmp > maxRow[i / 5])
				{
					place(i / 5, i % 5, tmp); 
					ans += dfs(col[0], col[1], col[2], col[3], col[4], 0); 
					used[tmp] = 0; 
				}
			}
			used[tmp] = 1; 
			maxRow[i / 5] = maxCol[i % 5] = tmp; 
		}
		cout << ans + 1 << endl; 
	}
}

