/*
ID: zihaoch1
PROG: ride
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
char ch1[7],ch2[7];
int main()
{

long long product1 = 1,product2 = 1,i;
	fin>>ch1>>ch2;
	for (i = 0;i < strlen(ch1) ;i++) {
		product1 *= ch1[i] - 64;
	}
	cout << product1 << endl;
	for (i = 0;i < strlen(ch2) ;i++)	
		product2 *= ch2[i] - 64;
	cout << product2 << endl;
	if ((product1 - product2) % 47 ==0) fout<<"GO"<<endl;
		else fout<<"STAY"<<endl;;
	return 0;

}
