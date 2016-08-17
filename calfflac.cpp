/*
ID: zihaoch1
PROG: calfflac
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cctype>
#include<cstring>
using namespace std;

char a[20010],b[20010];

int main()
{
	ifstream fin("calfflac.in"); 
	ofstream fout("calfflac.out"); 
	int i, maxLength, left, right, s, begin,len; 
	char *p, *q, ch; 
	p = a; q = b;
	while (!fin.eof())
	{
		ch = fin.get();
		if (isalpha(ch)) *q++ = tolower(ch); 
		*p++ = ch; 
	}
	*p='\0';
	*q='\0';
	maxLength = 0;
	len = strlen(b); 
	p = a;
	for (i = 0; i < len; i++)
	{
		left = i - 1;  right = i + 1;  s = 1; 
		while (left >= 0 && right <= len - 1 && b[left] == b[right])
		{
			left--;  right++; s += 2; 
		}
		if (s > maxLength)
		{
			begin = left + 1; 
			maxLength = s; 
		}
		left = i;  right = i + 1; s = 0; 
		while (left >= 0 && right <= len - 1 && b[left] == b[right])
		{
			left--;  right++; s += 2; 
		}
		if (s > maxLength)
		{
			begin = left + 1; 
			maxLength = s; 
		}
	}
	
	for (i = 0; *p; p++)
		if (isalpha(*p) && i++ == begin)
			break;
	fout << maxLength << endl; 
	for (i = 0; i < maxLength && *p; p++)
	{
		 fout << *p; 
		 if (isalpha(*p)) i++; 
	}
	fout << endl;
}


