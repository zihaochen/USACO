/*
ID: zihaoch1
PROG: beads
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

ofstream fout ("beads.out");
ifstream fin ("beads.in");


int main()
{
char ch[1000],t1,t2;
int num1,num2,num = 0,n;
int i,j;
	fin>>n;
	fin>>ch;
	int length = strlen(ch);
	for (i = 0,j = 0;j < length;j++,i++)
		ch[j + length] = ch[i];	
	for (i = 0;i < 2 * length - 1;i++)
		{
			num1 = num2 = 0;
			t1 = ch[i];
			t2 = ch[i + 1];
			for (j = i;j >= 0;j--)
				{
					if (t1 == 'w') t1 = ch[j];
					if (!(ch[j] == t1 || ch[j] == 'w')) break;
					num1++;
				}
			for (j = i + 1;j < 2 * length;j++)
				{
					if (t2 == 'w') t2 = ch[j];
					if (!(ch[j] == t2 || ch[j] == 'w')) break;
					if (num2 >= length) break;
					num2++;
				}
			num = max(num1 + num2,num);
		}
	num = min(num,length);
	fout<<num<<endl;
}
