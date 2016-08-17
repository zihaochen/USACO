/*
ID: zihaoch1
PROG: milk2
LANG: C++
*/

#include<iostream>
#include<fstream>
using namespace std;

ofstream fout("milk2.out");
ifstream fin("milk2.in");

int l[5000],r[5000];
bool a[1000001];

int main()
{
bool flag = 0;
int i,j,n,num1,num0,sum1,sum0,MAX,MIN = 1000005;
num1 = num0 = sum1 = sum0 = MAX = 0;
	fin>>n;
	for (i = 0;i < n;i++)
		{
			fin>>l[i]>>r[i];
			for (j = l[i];j < r[i];j++)
				a[j] = 1;
			MAX = max(r[i],MAX);
			MIN = min(l[i],MIN);
		}
	for (i = MIN;i < MAX;i++)
		{
			if (flag == 0 && a[i] == 0) num0++;
			if (flag == 1 && a[i] == 1) num1++;
			if (flag == 0 && a[i] == 1) {num1 = 1;flag = 1;}
			if (flag == 1 && a[i] == 0) {num0 = 1;flag = 0;}
			sum1 = max(sum1,num1);
			sum0 = max(sum0,num0);
		}
	fout<<sum1<<' '<<sum0<<endl;
}
