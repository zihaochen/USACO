/*
ID: zihaoch1
PROG: preface
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int value[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000}; 
char ch[7] ={'I', 'V', 'X', 'L', 'C', 'D', 'M'}; 
int num[7];

void cal(int n)
{
	while (n > 0)
	{
		for (int i = 12; i >= 0; i--)
		{
			bool flag = 0;
			while (n - value[i] >= 0)
			{
				n -= value[i];
				if (i == 1 && flag == 0) 
				{
					flag = 1;
					num[0]++; 
					num[1]++; 
					continue; 
				}
				if (i == 3 && flag == 0) 
				{
					flag = 1;
					num[0]++; 
					num[2]++; 
					continue; 
				}
				if (i == 5 && flag == 0)
				{
					flag = 1;
					num[2]++; 
					num[3]++; 
					continue; 
				}
				if (i == 7 && flag == 0) 
				{
					flag = 1;
					num[2]++; 
					num[4]++; 
					continue; 
				}
				if (i == 9 && flag == 0)
				{
					flag = 1;
					num[4]++; 
					num[5]++; 
					continue; 
				}
				if (i == 11 && flag == 0) 
				{
					flag = 1;
					num[4]++; 
					num[6]++; 
					continue; 
				}
				num[i - (i > 1) - (i > 3) - (i > 5) - (i > 7) - (i > 9) - (i > 11)]++; 
			}
		}
	}
}

int main()
{
	int n; 
	ifstream fin("preface.in"); 
	ofstream fout("preface.out"); 
	fin >> n; 
	for (int i = 1; i <= n; i++)
		cal(i); 
	for (int i = 0; i < 7; i++)
		if (num[i] != 0) 
			fout << ch[i] << ' '  << num[i] << endl; 
}

