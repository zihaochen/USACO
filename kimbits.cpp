/*
ID: zihaoch1
PROG: kimbits
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std; 

long long C(int a, int b)
{
	if (a == 0 && b == 0)  return 1;
	if (a == 0) return 0;
	if (b > a) return 0; 
	double tmp = 1.0; 
	for (int i = 1; i <= b; i++)
		tmp = tmp * (a + 1 - i) / i; 
	//out<<"C("<<a<<","<<b<<") = "<<tmp<<endl;
	return (long long) tmp; 
}

long long size(int n, int m)//至多有m个1的n位二进制数
{
	long long tmp = 0;
	for (int i = 0; i <= m; i++)
		tmp += C(n, i); 
	return tmp; 
}

string find(int n, int m, long long i)//找至多有m个1的n位二进制数的第i个元素
{	
	string tmp = ""; 
	if (n == 0) return tmp;
	long long num1 = size(n - 1, m);//  0 + 
	//int num2 = size(n - 1, m - 1);// 1 +
	//cout<<"size("<<n - 1<< ", "<< m<< ") = "<<num1<<endl;
	if (i > num1)
		tmp = '1' + find(n - 1, m - 1, i - num1); 
	if (i <= num1)
		tmp = '0' + find(n - 1, m, i); 
	return tmp; 
}

int main()
{
	ifstream cin("kimbits.in"); 
	ofstream cout("kimbits.out"); 
	int n, m;
	long long I;
	cin >> n >> m >> I; 
	string tmp = find(n, m, I);
	cout << tmp << endl;  
		
}

