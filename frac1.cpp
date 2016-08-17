/*
ID: frac1
PROG: frac1
LANG: C++
*/
#include<fstream>
using namespace std; 
 
int gcd(int, int); 
void qsort(int, int); 
int divide(int, int); 
 
double a[1000000]; 
int h[1000000]; 
	
	ofstream cout ("frac1.out");
	ifstream cin ("frac1.in");
int main()
{
	int n, i, j, num ;
	cin >> n; 
	cout << "0/1" << endl; 
	num = 0; 
	for (j = 1; j < n; j++)
		for (i = 1; i <= n; i++)
			if (gcd(i, j) == 1 && i > j)
			{
				a[++num] = (double) j / i; 
				h[num] = 201*i + j; 
			}
	qsort(1, num); 
	for (i = 1; i <= num; i++)
		cout << h[i] % 201 << '/' << h[i] / 201 << endl; 
	cout << "1/1" << endl; 
	
}
 
int gcd(int a, int b)
{
	if (b == 0) return a; 
	else 
		return gcd(b, a % b);
}
 
int divide(int low, int high)
{
	double k = a[low]; 
	int p = h[low]; 
	while (low < high)
	{
		while (low < high && a[high] >= k)
			high--; 
		if (low < high)
		{
			a[low] = a[high]; 
			h[low] = h[high]; 		
		}
		while (low < high && a[low] <= k)
			low++; 
		if (low < high)
		{
			a[high] = a[low]; 
			h[high] = h[low]; 
		}
	}
	a[low] = k; 
	h[low] = p; 
	return low; 
}
 
void qsort(int low, int high)
{
	if (low >= high) return; 
	int mid = divide(low, high); 
	qsort(low, mid); 
	qsort(mid + 1, high);
}
