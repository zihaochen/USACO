/*
ID: zihaoch1
PROG: msquare
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<set>
#define debug cout<<"not here\n"
using namespace std; 

string a;
string result; 
bool flag;
struct node
{
	string b; 
	string x; 
};

bool check(string &tmp)
{
	return (tmp == a);
}

void tranA(string &tmp)
{
	for (int i = 0; i < 4; i++)
		swap(tmp[i], tmp[7 - i]); 
}


void tranB(string &tmp)
{
	char k = tmp[3]; 
	for (int i = 3;i > 0;i--)
		tmp[i] = tmp[i - 1];
	tmp[0] = k;
	k = tmp[4];
	for (int i = 4;i < 7;i++)
		tmp[i] = tmp[i + 1];
	tmp[7] = k;	
}


void tranC(string &tmp)
{
	char k = tmp[6]; 
	tmp[6] = tmp[5]; 
	tmp[5] = tmp[2]; 
	tmp[2] = tmp[1]; 
	tmp[1] = k;
}

string bfs()
{
	queue<node> q;
	set<string> s;
	while (!q.empty()) q.pop();
	node ini;
	ini.b="12345678";
	ini.x = "";	
	q.push(ini);
	while (1)
	{
		node tmp = q.front(); 
		q.pop();
	//	cout<<tmp.x<<endl;
		if (check(tmp.b)) return tmp.x;

		node forPush;
		forPush.b = tmp.b;
		forPush.x = tmp.x;
		forPush.x += 'A'; 
		tranA(forPush.b);
		if (!s.count(forPush.b)) 
		{
			q.push(forPush); 
			s.insert(forPush.b);
		}
		
		forPush.b = tmp.b;
		forPush.x = tmp.x;
		forPush.x += 'B'; 
		tranB(forPush.b); 
		if (!s.count(forPush.b)) 
		{
			q.push(forPush); 
			s.insert(forPush.b);
		}

		forPush.b = tmp.b;
		forPush.x = tmp.x;
		forPush.x += 'C'; 
		tranC(forPush.b); 
		if (!s.count(forPush.b)) 
		{
			q.push(forPush); 
			s.insert(forPush.b);
		}
	}
}

int main()
{
	ifstream cin("msquare.in"); 
	ofstream cout("msquare.out"); 
	char ch;
	for (int i = 0; i < 8; i++)
	{
		cin>>ch;
		a += ch;
	}
	string tmp = bfs() ;
	cout<<tmp.size()<<endl;
	cout<< tmp << endl;
}

