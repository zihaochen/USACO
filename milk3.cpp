/*
ID: zihaoch1
PROG: milk3
LANG: C++
*/
#include<iostream>
#include<fstream>

using namespace std; 

int a, b, c; 
bool visited[30][30][30], note[30]; 
int milk[21]; 
void dfs(int,int,int);

int main()
{
	int size = 0; 
	ifstream fin("milk3.in"); 
	ofstream fout("milk3.out"); 

	fin >> a >> b >> c; 
	dfs(0, 0, c); 
	for (int i = 0; i <= c; i++)
		if (note[i])
			milk[size++] = i; 
	for (int i = 0; i < size - 1; i++)
		fout << milk[i] << ' '; 
	fout << milk[size - 1] << endl; 
}

void dfs(int a1, int b1, int c1)
{
	if (visited[a1][b1][c1]) return;
	visited[a1][b1][c1] = 1; 
	if (a1 == 0) note[c1] = 1; 
	// a -> b
	int	pour = min(b, b1 + a1) - b1; 
	dfs(a1 - pour, pour + b1, c1); 
	// a -> c
	pour = min(c, c1 + a1) - c1; 
	dfs(a1 - pour, b1, pour + c1); 
	// b -> a
	pour = min(a, a1 + b1) - a1; 
	dfs(a1 + pour, b1 - pour, c1); 
	// b -> c
	pour = min(c, c1 + b1) - c1; 
	dfs(a1, b1 - pour, c1 + pour); 
	// c -> a; 
	pour = min(a, a1 + c1) - a1; 
	dfs(a1 + pour, b1, c1 - pour); 
	// c -> b
	pour = min(b, b1 + c1) - b1; 
	dfs(a1, b1 + pour, c1 - pour); 
	return;
}

