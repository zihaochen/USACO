/*
PROG:gift1
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	
char ch[10][16],ch0[16],b[16];
int a[11];

int main()
{
int sum,m,t,i,j,n;
	fin>>n;
	for (i = 0;i < n;i++)
		fin>>ch[i];
	for (i = 0;i < n;i++)
		{
			fin>>b;
			fin>>sum>>m;
			for (j = 0;j < n;j++)
				if (strcmp(ch[j],b) == 0) 
					{if (m == 0) a[j] += sum;
						else a[j] += sum % m - sum;
						 break;}
			
			if (m != 0)
				for (j = 0;j < m;j++)
					{
						fin>>ch0;
						for (t = 0;t < n;t++)
							if (strcmp(ch[t],ch0) == 0) 
								{
									a[t] += sum / m;
									break;
								}
					}	   
		}
	for (i = 0;i < n;i++)
		fout<<ch[i]<<' '<<a[i]<<endl;
	return 0;
}
		
		

