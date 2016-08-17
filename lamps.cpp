/*
ID: zihaoch1
PROG: lamps
LANG: C++
*/
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;

ifstream cin("lamps.in"); 
ofstream cout("lamps.out"); 

 

int b[5], state[2000], tmp[2000];
string result[1000];
int n, c, num; 

void addToString()
{
	num++;
	for (int i = 1; i <= n; i++)
		result[num] += '0' + tmp[i];
}

bool qualified()
{
	if ((b[1] + b[2] + b[3] + b[4]) > c) return 0; 
	if ((b[1] + b[2] + b[3] + b[4]) % 2 != c % 2) return 0;
	for (int i = 1; i <= n; i++)
	{
		if (state[i] == 1 && tmp[i] != 1) return 0; 
		if (state[i] == 0 && tmp[i] != 0) return 0; 
	}
	return 1; 
}

void work(int index, int num)
{
	if (index == 1 && num > 0)
		for (int i = 1; i <= n; i++)
			tmp[i] = 1 - tmp[i];
	if (index == 2 && num > 0) 
		for (int i = 1; i <= n; i++)
			if (i % 2 == 1)
				tmp[i] = 1 - tmp[i]; 
	if (index == 3 && num > 0)
		for (int i = 1; i <= n; i++)
			if (i % 2 == 0)
				tmp[i] = 1 - tmp[i]; 
	if (index == 4 && num > 0)
		for (int i = 1; i <= n; i++)
			if (i % 3 == 1)
				tmp[i] = 1 - tmp[i]; 
}

int main()
{
	int t; 
	cin >> n; 
	cin >> c;
	for (int i = 1; i <= n; i++)
		state[i] = 2; 
	t = 0; 
	while (t != -1)
	{
		state[t] = 1; 
		cin >> t; 
	}
	t = 0; 
	while (t != -1)
	{
		state[t] = 0; 
		cin >> t; 
	}
	
	for (b[1] =  0; b[1] < 2; b[1]++)
		for (b[2] = 0; b[2] < 2; b[2]++)
			for (b[3] = 0; b[3] < 2; b[3]++)
				for (b[4] = 0; b[4] < 2; b[4]++)
				{
					for (int i = 1; i <= n; i++)
						tmp[i] = 1; 
					for (int i = 1; i <= 4; i++)
						work(i, b[i]);
					if (qualified()) 
						addToString();
				}
	sort(result + 1, result + num + 1); 
	result[0] = "34003400";
	if (num == 0)
		cout<<"IMPOSSIBLE\n";
	for (int i = 1; i <= num; i++)
	{
		if (result[i] != result[i - 1])
			cout<<result[i]<<endl; 
	}
}


