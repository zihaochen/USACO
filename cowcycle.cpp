/*
ID: zihaoch1
PROG: cowcycle
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<algorithm>
#define debug cout<<"not here\n"
using namespace std; 

double Min = 1000000000; 
int F, R, fHigh, fLow, rHigh, rLow; 
vector<double> quo; 
vector<int> f, r, fResult, rResult; 

void searchR(int rn, int rnum)
{;
	if (rnum == R + 1)
	{
		if (f[F - 1] * r[R - 1] - 3 * f[0] * r[0] < 0) return; 
		quo.clear(); 
		for (int i = 0; i < F; i++)
			for (int j = 0; j < R; j++)
			{
				double tmp = (double) f[i] / r[j]; 
				quo.push_back(tmp); 
			}
		sort(quo.begin(), quo.end()); 
		for (int i = 0; i < quo.size() - 1; i++)
			quo[i] = quo[i + 1] - quo[i]; 
		quo.pop_back(); 
		double mean = 0; 
		for (int i = 0; i < quo.size(); i++)
			mean += quo[i]; 
		mean /= quo.size(); 
		double sum = 0; 
		for (int i = 0; i < quo.size(); i++)
			sum  = sum + quo[i] * quo[i] - mean * mean; 
		if (sum < Min)
		{
			fResult = f; 
			rResult = r; 
			Min = sum; 
		}
		return;
	}
	if (rn > rHigh) return; 
	searchR(rn + 1, rnum); 
	r.push_back(rn); 
	searchR(rn + 1, rnum + 1); 
	r.pop_back(); 
}

void searchF(int fn, int fnum)
{
	if (fnum == F + 1) 
	{
		searchR(rLow, 1); 
		return;
	}
	if (fn > fHigh) return; 
	searchF(fn + 1, fnum); 
	f.push_back(fn); 
	searchF(fn + 1, fnum + 1); 
	f.pop_back(); 
}


int main()
{
	ifstream cin("cowcycle.in"); 
	ofstream cout("cowcycle.out"); 
	cin >> F >> R;
	cin >> fLow >> fHigh >> rLow >> rHigh; 
	searchF(fLow, 1); 
	for (int i = 0; i < fResult.size() - 1; i++)
		cout << fResult[i] <<  ' '; 
	cout << fResult[fResult.size() - 1] << endl; 
	for (int i = 0; i < rResult.size() - 1; i++)
		cout << rResult[i] << ' '; 
	cout << rResult[rResult.size() - 1] << endl; 
}


