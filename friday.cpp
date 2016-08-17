/*
ID: zihaoch1
PROG: friday
LANG: C++
*/
#include<iostream>
#include<fstream>

using namespace std;

ofstream fout("friday.out");
ifstream fin("friday.in");

int month[13] = {31,31,28,31,30,31,30,31,31,30,31,30,31};
int monthLeap[13] = {31,31,29,31,30,31,30,31,31,30,31,30,31};
int a[8];

int main()
{
int n,i,j,pre = 3;
	fin>>n;
	for (i = 1900;i < 1900 + n;i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) or (i % 400 == 0)) 
				{
					for (j = 0;j < 12;j++)
						{
							pre = (pre + monthLeap[j]) % 7;
							a[pre]++;	
						}
				}
			else 
				{
					for (j = 0;j < 12;j++)
						{
							pre = (pre + month[j]) % 7;
							a[pre]++;	
						}
				}					
		}
	fout<<a[6]<<' '<<a[0];
	for (i = 1;i < 6;i++)	
		fout<<' '<<a[i];
	fout<<endl;
	return 0;
}
