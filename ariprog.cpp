/*
ID: zihaoch1
PROG: ariprog
LANG: C++
*/
#include<iostream>
#include<fstream>

using namespace std; 

bool bisquare[2 * 250 * 250 + 5]; 

int main()
{
	int m, n, i, j, a, b; 
	bool flag,FLAG = 0; 
	ifstream fin("ariprog.in"); 
	ofstream fout("ariprog.out"); 
	fin >> n >> m; 
	for (i = 0; i <= m; i++)
		for (j = i; j <= m; j++)
			bisquare[i*i + j*j] = 1; 
	if (n == 3)
	{
	for (b = 1; b <= m * m * 2; b ++)
		for (a = 0; a <= m * m * 2; a++)
		{
			if (a + (n - 1) * b > 2 * m * m) break;
			if (a % 4 == 3) continue; 
			flag = 1; 
			for (i = 0; i < n && (a + i * b <= 2 * m * m); i++)
			{
				if (!bisquare[a + i * b])
				{
					flag = 0; 
					break; 
				}				
			}
			if (flag)
			{
				fout << a << ' ' << b << endl; 
				FLAG = 1;
			}
		}
	}
	else
	{
		for (b = 4; b <= m * m * 2; b += 4)
		for (a = 0; a <= m * m * 2; a++)
		{
			if (a + (n - 1) * b > 2 * m * m) break;
			if (a % 4 == 3) continue; 
			flag = 1; 
			for (i = 0; i < n; i++)
			{
				if (!bisquare[a + i * b])
				{
					flag = 0; 
					break; 
				}				
			}
			if (flag)
			{
				fout << a << ' ' << b << endl; 
				FLAG = 1;
			}
		}
	}
	if (!FLAG) fout<<"NONE"<<endl;
}

