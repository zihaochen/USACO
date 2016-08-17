/*
ID: zihaoch1
PROG: fence3
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std; 

const double INF = 1000000000;
const double EPS = 1e-6;
struct node
{
	int i, j; 
}; 

struct EDGE
{
	node a, b; 
} edge[200]; 

int det(const node &a, const node &b, const node &base)
{
	return ((a.i - base.i) * (b.j  - base.j) - (b.i - base.i) * (a.j - base.j)); 
}

double dis(const node &a, const node &b)
{
	return ((double) sqrt((a.i - b.i) * (a.i - b.i) + (a.j - b.j) * (a.j - b.j))); 
}

double dist( node n, EDGE e)
{
	if (((e.a.i - n.i) * (e.a.i - e.b.i) + (e.a.j - n.j) * (e.a.j - e.b.j)) < 0\
		|| ((e.b.i - n.i) * (e.b.i - e.a.i) + (e.b.j - n.j) * (e.b.j - e.a.j)) < 0)
	return min(dis(e.a, n), dis(e.b, n)); 
	else 
		if (fabs(dis(e.a, e.b)) > EPS)
			return fabs((double) det(e.a, e.b, n) / dis(e.a, e.b)); 
		else return dis(e.a, n);
}

int main()
{
	ifstream cin("fence3.in");
	ofstream cout("fence3.out");
	int f; 
	int minJ = INF, minI = INF, maxJ = 0, maxI = 0; 
	cin >> f; 
	for (int i = 0; i < f; i++)
	{
		cin >> edge[i].a.i >> edge[i].a.j >> edge[i].b.i >> edge[i].b.j;
		edge[i].a.i *= 10; 
		edge[i].b.i *= 10; 
		edge[i].a.j *= 10; 
		edge[i].b.j *= 10; 
		minI = min(edge[i].a.i, minI); 
		minI = min(edge[i].b.i, minI); 
		minJ = min(edge[i].a.j, minJ); 
		minJ = min(edge[i].b.j, minJ); 
		maxI = max(edge[i].a.i, maxI); 
		maxI = max(edge[i].b.i, maxI); 
		maxJ = max(edge[i].a.j, maxJ); 
		maxJ = max(edge[i].b.j, maxJ); 
	}
	
	node maxNode; 
	double minSum = INF; 
	for (int i = minI; i <= maxI; i += 10)
		for (int j = minJ; j <= maxJ; j += 10)
		{
			node tmp;
			tmp.i = i; tmp.j = j; 
			double sum = 0; 
			for (int t = 0; t < f; t++)
				sum += dist(tmp, edge[t]); 
			if (minSum > sum)
			{
				maxNode = tmp; 
				minSum = sum; 
			}

		}

	for (int i = maxNode.i - 10; i <= maxNode.i + 10; i++)
		for (int j = maxNode.j - 10; j <= maxNode.j + 10; j++)
		{
			node tmp;
			tmp.i = i; tmp.j = j; 
			double sum = 0; 
			for (int t = 0; t < f; t++)
				sum += dist(tmp, edge[t]); 
			if (minSum > sum)
			{
				maxNode = tmp; 
				minSum = sum; 
			}
		}
	cout<< setiosflags(ios::fixed) << setprecision(1) << (double) maxNode.i / 10 <<  ' ' << (double) maxNode.j / 10  << ' '  <<  minSum / 10 << endl; 
	
}

