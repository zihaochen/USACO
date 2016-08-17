/*
ID: zihaoch1
PROG: job
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std; 

const int INF = 10000000;
int n, m[2]; 
int t[2][1500], delay[1500], cost[2][1500]; 

int main()
{
	ifstream cin("job.in"); 
	ofstream cout("job.out"); 
	cin >> n >> m[0] >> m[1]; 
	for (int k = 0; k < 2; k++)
	{
		for (int i = 1; i <= m[k]; i++)
			cin >> t[k][i]; 
		memset(delay, 0, sizeof(delay)); 
		for (int i = 0; i < n; i++)
		{
			int tmpMin = INF; 
			int tmpIndex; 
			for (int j = 1; j <= m[k]; j++)
				if (delay[j] + t[k][j] < tmpMin)
				{
					tmpMin = delay[j] + t[k][j]; 
					tmpIndex = j; 
				}
			delay[tmpIndex] = tmpMin; 
			cost[k][i] = tmpMin; 
		}
	}

	int tmpMax = 0; 
	for (int i =  0; i < n; i++)
		tmpMax = max(tmpMax, cost[0][i] + cost[1][n - 1 - i]); 
	cout << cost[0][n - 1] << ' '  << tmpMax << endl; 
	
}

