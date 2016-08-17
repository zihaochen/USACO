/*
ID: zihaoch1
PROG: clocks
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
using namespace std; 

void Try(int); 
int a[10], b[10], answer[10]; 
int x[9][10] = {{4,1,2,4,5,0,0,0,0,0},
           {3,1,2,3,0,0,0,0,0,0},
           {4,2,3,5,6,0,0,0,0,0},
		   {3,1,4,7,0,0,0,0,0,0},
    	   {5,2,4,5,6,8,0,0,0,0},
    	   {3,3,6,9,0,0,0,0,0,0},
	   	   {4,4,5,7,8,0,0,0,0,0},
		   {3,7,8,9,0,0,0,0,0,0},
		   {4,5,6,8,9,0,0,0,0,0}};
int minLen = 1000000;

int main()
{
	int i; 
	ifstream fin("clocks.in"); 
	ofstream fout("clocks.out"); 
	for (i = 1; i <= 9; i++)
		fin >> a[i]; 
	Try(0); 
	for (i = 1; i <= 9; i++)
		while (answer[i]--)
		{
			if (--minLen)
				fout << i << ' '; 
			else
				fout << i << endl; 
		}


}

void Try(int n)
{
	if (n == 9)
	{
		int sum = 0;
		for (int i = 1;i <= 9;i++)
			sum += a[i] % 12;
		if (!sum)
		{ 
			int len = accumulate(b, b + 9, 0); 
			if (len < minLen)
			{
				copy(b, b + 9, answer + 1); 
				minLen = len; 
			}
		}
	}
	else
	{
		for (int k = 0; k < 4; k++)
		{
			b[n] = k; 
			for (int i = 1; i <= x[n][0]; i++)
				a[x[n][i]] += k * 3; 
			Try(n + 1); 
			for (int i = 1; i <= x[n][0]; i++)
				a[x[n][i]] -= k * 3; 
		}
	}
}

