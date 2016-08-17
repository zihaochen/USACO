/*
ID: zihaoch1
PROG: palsquare
LANG: C++
*/
#include<fstream>
#include<cstring>
#include<iostream>
using namespace std; 

bool check(int); 
char convert(int r);
void changeBase(int i); 

char ch[10];
char ch0[10];
char con[20] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; 
int base; 
ifstream fin("palsquare.in");
ofstream fout("palsquare.out");
int main()
{
	fin >> base; 
	for (int i = 1; i <= 300; i++)
		if (check(i * i))
		{
			changeBase(i); 
			fout  << ' '<< ch << endl; 
		}
}

bool check(int i)
{
int t = 0; 
bool flag = 1; 
	while (i != 0)
	{
		ch[t] = convert(i % base); 
		i = i / base; 
		t++; 
	}
	for (int j = 0; j <= t - 1; j++)
		if (ch[j] != ch[t - 1 - j])
		{
			flag = 0; 
			break; 
		}
	return flag; 
}

void changeBase(int i)
{
int t = 0; 
	while (i != 0)
	{
		ch0[t] = convert(i % base); 
		i = i / base; 
		t++; 
	}
	for (int j = t - 1; j >= 0; j--)
		fout << ch0[j]; 
}
 

char convert(int r)
{
	if (r >= 10)
		return con[r - 10];
	else 
		return (r + '0'); 
}



