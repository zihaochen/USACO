/*
ID: zihaoch1
PROG: fracdec
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std; 

int q[1000000], r[1000000]; 
int v[10][50000];
int cnt[10];

int main()
{
	int a, b; 
	ifstream cin("fracdec.in"); 
	ofstream cout("fracdec.out"); 
	cin >> a >> b; 
	int count = 0;
	{
		int num = 0; 
		q[0] = a/b; 
		r[0] = a - q[0] * b; 
		while (1)
		{
			if (r[num] == 0)
			{
				cout<<q[0]<<'.';
				for (int i = 1;i <= num;i++)
					cout<<q[i];
				if (num == 0)
					cout<<0;
				cout<<endl;
				return 0;
			}
			num++; 
			q[num] = 10 * r[num - 1] / b; 
			r[num] = 10 * r[num - 1] - q[num] * b; 
			v[q[num]][cnt[q[num]]++] = num;
			for (int t = 0; t < cnt[q[num]] - 1; t++)
			{
				int i = v[q[num]][t];
				if (q[i] == q[num] && r[i] == r[num])
				{
					cout << q[0] << '.'; 
					if (q[0] != 0)
						count = log10(q[0]) + 1;
					else 
						count = 1;
					count++;
					for (int j = 1; j < i; j++)
					{		
						if (count % 76 == 0) cout<<endl;
						cout << q[j]; 
						count++;
					}
					if (count % 76 == 0) cout<<endl;
					count++;
					cout << '('; 
					for (int j = i; j < num; j++)
					{		
						if (count % 76 == 0) cout<<endl;
						cout << q[j]; 
						count++;
					}
					if (count % 76 == 0) cout<<endl;
					cout << ')'<< endl; 
					return 0; 
				}
			}
		}
	}
}

