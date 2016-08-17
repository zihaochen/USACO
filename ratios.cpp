/*
ID: zihaoch1
PROG: ratios
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int x[4],y[4],z[4],a[4],tmp[3];

int main()
{
	ifstream cin("ratios.in"); 
	ofstream cout("ratios.out"); 

	int Min = 10000; 
	int i1, j1, k1, r; 
	int tmp0;
	cin >> a[0] >> a[1] >> a[2]; 
	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i] >> z[i]; 
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			for (int k = 0; k <= 100; k++)
			{
				tmp[0] = x[0] * i + x[1] * j + x[2] * k; 
				tmp[1] = y[0] * i + y[1] * j + y[2] * k; 
				tmp[2] = z[0] * i + z[1] * j + z[2] * k; 

				if (!((a[0] != 0 && tmp[0] % a[0] == 0 || a[0] == 0 && tmp[0] == 0) \
				&& (a[1] != 0 && tmp[1] % a[1] == 0 || a[1] == 0 && tmp[1] == 0)\
				 && (a[2] != 0 && tmp[2] % a[2] == 0 || a[2] == 0 && tmp[2] == 0)))
				 		continue;
				for (int t = 0;t < 3;t++)
					if (a[t] != 0)
						tmp0 = tmp[t] / a[t];
				bool flag = 0;
				for (int t = 0; t < 3;t++)
					if (a[t] != 0 && tmp[t] / a[t] != tmp0)
						flag = 1;
				if (flag || tmp0 == 0) continue;
					if (i + j + k < Min)
					{
						i1 = i; 
						j1 = j; 
						k1 = k; 
						r = tmp0;
						Min = i + j + k; 
					}
			}
	if (Min != 10000)
		cout << i1 << ' ' << j1 << ' ' << k1 << ' ' << r << endl; 
	else
		cout<<"NONE"<<endl;
}

