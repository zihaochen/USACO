/*
ID: zihaoch1
PROG: fact4
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int num[10]; 
int n; 

int power(int a, int b)
{
	int tmp = 1; 
	for (int i =0; i <b; i++)
		tmp *= a; 
	return tmp; 
}


int main()
{
	ifstream cin("fact4.in"); 
	ofstream cout("fact4.out"); 
	cin >> n; 
	int tmp = 1;
	int num5,num2;
	num5 = num2 = 0;
	for (int j = 1; j <= n; j++)
	{
		int i = j;
		while ( i% 2 == 0)
		{
			num2 ++;
			i /= 2;
		}
		while ( i % 5 == 0)
		{
			num5 ++;
			i /= 5;
		}
		tmp *= i;
		tmp = tmp % 10;
	}
	tmp *= power(2, (num2 - num5 - 1) % 4 +  1);
	while (tmp % 10 == 0)
		tmp /= 10;
	cout<<tmp % 10 << endl;
}

