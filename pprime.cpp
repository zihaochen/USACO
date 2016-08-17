/*
ID: zihaoch1
PROG: pprime
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

bool isPrime(int x)
{
	if (x % 2 == 0) return 0; 
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0) return 0; 
	return 1; 
}

int generate(int x)
{
	int t = x; 
	x /= 10; 
	while (x > 0)
	{
		t = t * 10 + x % 10; 
		x /= 10; 
	}
	return t;
}

int main()
{
	ifstream fin("pprime.in"); 
	ofstream fout("pprime.out");
	int a, b; 
	fin >> a >> b; 
	int i = 10; 
	if(a<=5&&5<=b) fout << "5\n";
	if(a<=7&&7<=b) fout << "7\n";
	if(a<=11&&11<=b) fout << "11\n";
	while (generate(i) < a) i++; 
	while (generate(i) <= b)
	{
		int k = i, j = 1; 
		while (k > 9) 
		{
			k /= 10; 
			j *= 10; 
		}
		if (k % 2 == 0) 
		{
			i += j; 
			continue; 
		}
		j = generate(i); 
		if (isPrime(j)) fout << j << endl; 
		i++; 
	}
}

