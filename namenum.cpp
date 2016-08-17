/*
ID: zihaoch1
PROG: namenum
LANG: C++
*/
#include<fstream>
#include<cstring>
using namespace std; 

char ch[13]; 
char name[6000][13]; 
char Name[6000][13]; 
char ltr[26] = {'2','2','2', '3', '3','3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '0', '7', '7', '8', '8', '8', '9', '9', '9', '0'}; 

int main()
{
	bool flag = 1,Flag = 0; 
	int i , j, t, number = 0; 
	ifstream fin1("dict.txt"); 
	for (i = 0; fin1 >> name[i]; i++)
		for (j = 0; j < strlen(name[i]); j++)
			Name[i][j] = ltr[name[i][j] - 'A']; 
	number = i; 
	ifstream fin("namenum.in"); 
	ofstream fout("namenum.out"); 
	fin >> ch; 
	for (i = 0; i <= number; i++)
	{
		if (Name[i][0] != ch[0])
			continue; 
		if (strlen(Name[i]) != strlen(ch)) 
			continue; 
		for (j = 1; j < strlen(ch); j++)
		{
			flag = 1; 
			if (Name[i][j] != ch[j]) 
			{
				flag = 0; 
				break; 
			}
		}
		if (flag) 
			{
				fout << name[i]<< endl; 
				Flag = 1;
			}
	}
	if (!Flag) fout << "NONE"<< endl;
}




