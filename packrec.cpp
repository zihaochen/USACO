/*
ID: zihaoch1
PROG: packrec
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std; 

struct loc
{
	int x, y; 
}; 

int tmp1 = 0, tmp2 = 0; 
loc rec[10000]; 
bool flag[101]; 
int maxArea = 1000000; 


void record();
void permutate(int);
void exchange(int);
void cal();

int main()
{
	int i; 
	ifstream fin("packrec.in"); 
	ofstream fout("packrec.out"); 
	for (i = 0; i < 4; i++)
		fin >> rec[i].x >> rec[i].y; 
	permutate(0); 
	fout << maxArea << endl; 
	for (i = 1; i <= 100; i++)
		if (flag[i])
		{
			fout << i <<' ' << maxArea / i << endl; 
		}
}

void cal()
{
int i; 
	//case 1
	tmp1 = tmp2 = 0;
	for (i = 0; i < 4; i++)
	{
		tmp1 = max(tmp1, rec[i].y); 
		tmp2 += rec[i].x; 
	}
	record(); 

	//case 2
	tmp1 = tmp2 = 0; 
	for (i = 0; i < 3; i++)
	{
		tmp1 = max(tmp1, rec[i].y); 
		tmp2 += rec[i].x; 
	}
	tmp1 += rec[3].y; 
	tmp2 = max(tmp2, rec[3].x);
	record(); 
	
	//case 3
	tmp1 = tmp2 = 0; 
	tmp1 = max(rec[0].x + rec[1].x, rec[3].x) + rec[2].x;
	tmp2 = max(max(rec[0].y, rec[1].y) + rec[3].y, rec[2].y); 
	record(); 

	//case 4 & 5
	tmp1 = tmp2 = 0; 
	tmp1 = rec[0].x + max(rec[1].x, rec[3].x) + rec[2].x; 
	tmp2 = max(max(rec[0].y, rec[1].y + rec[3].y), rec[2].y); 
	record(); 

	//case 6
	tmp1 = tmp2 = 0; 
	tmp1 = rec[1].x + rec[2].x; 
	tmp2 = max(rec[2].y + rec[3].y, rec[0].y + rec[1].y); 
	if (rec[2].y >= rec[1].y)
		tmp1 = max(tmp1, rec[0].x + max(rec[3].x,rec[2].x)); 
	else 
		if (rec[2].y + rec[3].y <= rec[1].y) 
			tmp1 = max(max(tmp1, rec[1].x + rec[3].x), rec[0].x); 
		else
			tmp1 = max(max(tmp1, rec[1].x + rec[3].x), rec[0].x + rec[3].x);
	record(); 
}

void record()
{
	if (tmp1 * tmp2 < maxArea)
	{
		maxArea = tmp1 * tmp2; 
		fill_n(flag + 1, 100, 0); 
	}
	if (tmp1 * tmp2 == maxArea)
		flag[min(tmp1, tmp2)] = 1;  

}

void permutate(int k)
{
	if (k == 4) exchange(0); 
	else 
		for (int i = k; i < 4; i++)
		{
			swap(rec[i], rec[k]); 
			permutate(k + 1); 
			swap(rec[i], rec[k]); 
		}
}

void exchange(int k)
{
	if (k == 4) cal(); 
	else
	{
		exchange(k + 1); swap(rec[k].x, rec[k].y); 
		exchange(k + 1); swap(rec[k].x, rec[k].y); 
	}
}






