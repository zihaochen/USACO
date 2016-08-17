/*
ID: zihaoch1
PROG: zerosum
LANG: C++
*/
#include<fstream>
using namespace std; 

ifstream cin("zerosum.in"); 
ofstream cout("zerosum.out"); 

char record[12]; 
int n; 

int pow(int base, int n)
{
	int sum = 1; 
	for (int i = 0; i < n; i++)
		sum *= base; 
	return sum; 
}

void print()
{
	cout << 1; 
	for (int i = 2; i <= n; i++)
		cout << record[i] << i; 
	cout << endl; 
}

void dfs(int value, int loc)
{
	if (loc == n + 1)
	{
		if (value == 0) 
			print(); 
		return; 
	}

	record[loc] = ' '; 
	int tmp = loc;
	int sum = 0;
	while (tmp >= 2 && record[tmp] == ' ')
	{
		sum += tmp * pow(10, loc - tmp); 
		tmp--; 
	}
	sum += tmp * pow(10, loc - tmp); 
	if (tmp == 1) dfs(sum, loc + 1); 
		else if (record[tmp] == '-') dfs(value + sum/10 - sum, loc + 1); 
			else dfs(value - sum/10 + sum, loc + 1);
			
	record[loc] = '+'; 
	dfs(value + loc, loc + 1); 
	record[loc] = '-'; 
	dfs(value - loc, loc + 1); 

}

int main()
{
	cin >> n;
	dfs(1, 2);
}

