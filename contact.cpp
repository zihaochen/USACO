/*
ID: zihaoch1
PROG: contact
LANG: C++
*/
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

struct node
{
	int l, v;
	long long s; 
	bool operator <(const node &x) const
	{
		if (v > x.v) return 1;
		if (v < x.v) return 0; 
		if (l < x.l) return 1;
		if (l > x.l) return 0;
		if (s < x.s) return 1;
		return 0;
	}
} result[100000]; 
string Stack[1000], ch; 
int a, b, n, num; 
int f[15][40000];

long long toNum(int l, int pos)
{
	long long tmp = 0; 
	for (int i = 0; i < l; i++)
		tmp += ((ch[i + pos] - '0') << (l - 1 - i)); 
	tmp += 1 << l;
	return tmp; 
}

string toString(long long x)
{
	string tmp = ""; 
	char ch; 
	do
	{
		ch = (char) (x % 2 + '0'); 
		if (ch == '/') cout<<"SHIT"<<x<<endl;
		tmp = ch + tmp; 
		x /= 2; 
	}
	while (x / 2 > 0); 
	return tmp; 
}
int main()
{
	ifstream cin("contact.in"); 
	ofstream out("contact.out"); 
	cin >> a >> b >> n; 
	string tmp; 
	while (getline(cin, tmp))
		ch += tmp; 
	int len = ch.size(); 
	for (int i = a; i <= b; i++)
		for (int j = 0; j + i - 1 < len; j++)
		{
			long long tt = toNum(i,j);
			f[i][tt]++; 
		}
			
	for (int i = a; i <= b; i++)
		for (int j = 0; j < (1  <<  13); j++)
		{
			if (f[i][j] == 0) continue; 
			result[num].l = i; 
			result[num].v = f[i][j];
			result[num].s = j; 
			num++;
		}
	
	sort(result, result + num);
	for (int i = 0;i < n;i++)
	n = min(num, n); 
	int cursor = 0; 
	int count = 0; 
	int i = 0; 
	int last = 0; 
	while (count <= n && i <= num)
	{
		if (result[i].v == last && i < num - 1)
		{
			Stack[cursor++] = toString(result[i].s);
		}
		else
		{
			if (cursor > 0)
			{
				for (int j = 0;j < cursor - 1;j++)
				{
					if (j % 6 != 5)
						out<<Stack[j]<< ' ';
					else
						out<<Stack[j]<<endl;
				}
				out<<Stack[cursor - 1]<<endl;
			}
			if (count >= n) return 0;
		 	cursor =  0;
			last = result[i].v;
			if (last != 0)
				out<<result[i].v<<endl;
			Stack[cursor++] = toString(result[i].s);
			count++;
		}
		i++;
	}
}


