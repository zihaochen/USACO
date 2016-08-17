/*
ID: zihaoch1
PROG: fc
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std; 

const int MAX = 10003; 

struct node
{
	double x, y; 
	double dist(const node &n)
	{
		return sqrt((n.x - x) * (n.x - x) + (n.y - y) * (n.y - y)); 
	}

	bool operator < (const node &n) const
	{
		return  (y < n.y || y == n.y && x < n.x); 
	}

	static double outProduct (const node &n1, const node &n2, const node& base)
	{
		return (n1.x - base.x) * (n2.y - base.y) - (n1.y - base.y) * (n2.x - base.x); 
	}
}p[MAX]; 

bool cmp(const node &n1, const node &n2) 
{
	double tmp = node::outProduct(n1, n2, p[0]); 
	return (tmp > 1e-6 || fabs(tmp) < 1e-6 && fabs(n1.x - p[0].x) < fabs(n2.x - p[0].x)); 
}

int main()
{
	ifstream cin("fc.in"); 
	ofstream cout("fc.out"); 
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y; 
	sort(p, p + n); 
	vector<node> hull; 
	sort(p + 1, p + n, cmp); 
	for (int i = 0; i < 3; i++)
		hull.push_back(p[i]); 
	for (int i = 3; i < n; i++)
	{
		while (hull.size() > 2 && node::outProduct(hull[hull.size() - 1], p[i], hull[hull.size() - 2]) < 0)
			hull.pop_back(); 
		hull.push_back(p[i]); 
	}
	double ans = hull[0].dist(hull.back()); 
	for (int i = 0; i < hull.size() - 1; i++)
		ans += hull[i].dist(hull[i + 1]); 
	cout << fixed << setprecision(2) << ans << endl; 
}

