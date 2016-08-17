/*
ID: zihaoch1
PROG: fence4
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std; 

int n; 
int flag[300];

struct VECT
{
	double x, y; 
}; 

struct NODE
{
	double x, y; 
	NODE & operator = (const NODE &t) 
	{
		x = t.x; 
		y = t.y; 
	}
	
	bool operator ==  (const NODE &t) const
	{
		return x == t.x && y == t.y;
	}

	VECT operator - (const NODE &t1)
	{
		VECT tmp; 
		tmp.x = x - t1.x; 
		tmp.y = y - t1.y; 
		return tmp; 
	}

} node[300], o; 

struct EDGE
{
	NODE a, b; 
} e[300]; 


double det(VECT n1, VECT n2)
{
	return (n1.x * n2.y - n1.y * n2.x); 
}

double interTmp(EDGE e1, EDGE e2)
{
	VECT v1, v2, v3, v4; 
	v1 = e1.a  - e2.a; 
	v2 = e1.a - e2.b; 
	v3 = e1.b - e2.a;  
	v4 = e1.b - e2.b; 
	return det(v1, v2) * det(v3, v4); 
}

bool inter(EDGE e1, EDGE e2)
{
	if (e1.a == e2.a || e1.a == e2.b || e1.b == e2.a || e1.b == e2.b)
		return 0;
	return interTmp(e1, e2) < 0 && interTmp(e2, e1) <= 0 ||
		   interTmp(e1, e2) <= 0 && interTmp(e2, e1) < 0; 
}

bool check()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j  < i; j++)
			if (inter(e[i], e[j]))
			{
			//	cout<<"e["<<i<<"] & e["<<j<<"]"<<endl;
			//	cout<<e[i].a.x << ' '<<e[i].a.y << ' '<< e[i].b.x<<' '<<e[i].b.y<<endl;
			//	cout<<e[j].a.x << ' '<<e[j].a.y << ' '<< e[j].b.x << ' '<<e[j].b.y<<endl;
				 return 0; 
			}
	return 1; 
}

int main()
{
	ifstream cin("fence4.in"); 
	ofstream cout("fence4.out"); 

	cin >> n; 
	cin >> o.x >> o.y;  
	for (int i = 0; i < n; i++)
		cin >> node[i].x >> node[i].y; 
	for (int i = 0; i < n ; i++)
	{
		if (i == n  - 2)
		{
			e[i].a = node[0]; 
			e[i].b = node[n - 1]; 
			continue; 
		}
		if (i == n - 1)
		{
			e[i].a = node[n - 2]; 
			e[i].b = node[n - 1]; 
			continue; 
		}
		e[i].a = node[i]; 
		e[i].b = node[i + 1]; 
	}

	if (!check()) 
	{
		cout << "NOFENCE\n"; 
		return 0; 
	}

	for (int i = 0; i < n; i++)
	{
		for (int t = 1; t < 512; t++)
		{
			NODE tmp; 
			tmp.x = (t * e[i].a.x + (512 - t) * e[i].b.x) / 512; 
			tmp.y = (t * e[i].a.y + (512 - t) * e[i].b.y) / 512; 
			EDGE temp; 
			temp.a = o; 
			temp.b = tmp;
			for (int j = 0; j < n; j++)
				if (i != j && inter(temp, e[j]))
				{
					flag[i]++; 
					break; 
				} 
		}
	}

	int num = 0;
	for (int i = 0;i < n;i++)
		if (flag[i] < 511)
			num++;
	cout<<num<<endl;
	for (int i = 0; i < n; i++)
		if (flag[i] < 511)
			cout << e[i].a.x << ' ' << e[i].a.y << ' '\
				 << e[i].b.x << ' ' << e[i].b.y << endl;  
}



