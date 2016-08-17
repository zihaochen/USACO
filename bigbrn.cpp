/*
ID: zihaoch1
PROG: bigbrn
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

const int N = 1004; 
int a[N][N], sum[N][N]; 
bool ti[N]; 

int main()
{
	ifstream cin("bigbrn.in");
	ofstream cout("bigbrn.out");
	int n, t, x, y; 

	cin >> n >> t; 
	for (int i = 0; i < t; i++)
	{
		cin >> x >> y; 
		a[x][y] = 1; 
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]; 

	int maxNum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int left = 1, right =  min(n - i + 1, n - j + 1) + 1;
			while (left != right)
			{
				int mid = (left + right) / 2;
				int tmp = sum[i + mid - 1][j + mid - 1] + sum[i - 1][j - 1] - sum[i + mid - 1][j - 1] - sum[i - 1][j + mid - 1];
				if (tmp == 0) left = mid + 1;
				if (tmp != 0) right = mid;
			}
			maxNum = max(left - 1, maxNum);
		}
	cout<<maxNum<<endl;
}

