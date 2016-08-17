/*
ID: zihaoch1
PROG: window
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#define debug cout<<"not here\n"
using namespace std; 

struct node
{
	int x1, x2, y1, y2; 
	char ch; 
}; 

vector<node> v; 
int num, area;

void Bottom(char f)
{
	for (int i = 0; i < num; i++)
		if (v[i].ch == f)
		{
			node tmp = v[i]; 
			v.erase(v.begin() + i); 
			v.insert(v.begin(), tmp); 
			return; 
		}
}

void Top(char f)
{
	for (int i = 0; i < num; i++)
		if (v[i].ch == f)
		{
			node tmp = v[i]; 
			v.erase(v.begin() + i); 
			v.push_back(tmp); 
			return; 
		}
}

void Destroy(char f)
{
	 for (int i = 0; i < num; i++)
		 if (v[i].ch == f)
		 {
			 node tmp = v[i]; 
			v.erase(v.begin() + i); 
			 num--;
			 return; 
		 }
}

void cover(int i1, int j1, int i2, int j2, int floor, int col)
{
	while (floor <  num && (i2 <= v[floor].x1 || i1 >= v[floor].x2 || j2 <= v[floor].y1 || j1 >= v[floor].y2))
		floor++; 
	if (floor == num)
	{
		area += (i2 - i1) * (j2 - j1); 
		return;
	}
	if (i1 < v[floor].x1)
	{ 
		cover(i1, j1,  v[floor].x1, j2, floor + 1, col);
		i1 =  v[floor].x1; 
	}
	if (i2 > v[floor].x2)
	{
		cover(v[floor].x2, j1, i2, j2, floor + 1, col);
		i2 = v[floor].x2; 
	}
	if (j2 > v[floor].y2)
	{
		cover(i1, v[floor].y2, i2, j2, floor + 1, col);
		j2 =  v[floor].y2; 
	}
	if (j1 <  v[floor].y1)
	{
		cover(i1, j1, i2,  v[floor].y1, floor + 1, col);
		j1 =  v[floor].y1; 
	}
}

double cal(char f)
{
	int i; 
	for (i = 0; i <num; i++)
		if (v[i].ch == f) break; 
	area = 0; 
	cover(v[i].x1, v[i].y1, v[i].x2, v[i].y2, i + 1, i);
	int sum = (v[i].x2 - v[i].x1) * (v[i].y2 - v[i].y1);
	return (double) area * 100/ sum; 
}

int main()
{
	ifstream cin("window.in"); 
	ofstream cout("window.out"); 

	char op;
	while (cin >> op)
	{ 
		if (op == 'w')
		{
			char ch; 
			cin.get();
			node tmp;
			cin >> tmp.ch; cin.get();
			cin >> tmp.x1; cin.get(); 
			cin >> tmp.y2; cin.get(); 
			cin >> tmp.x2; cin.get(); 
			cin >> tmp.y1; cin.get(); 
			if (tmp.x1 > tmp.x2) swap(tmp.x1, tmp.x2);
			if (tmp.y1 > tmp.y2) swap(tmp.y1, tmp.y2);
			v.push_back(tmp);
			num++;
		}
		else
		{
			cin.get(); 
			char f; 
			cin >> f; 
			cin.get(); 
			if (op == 't') Top(f); 
			if (op == 'b') Bottom(f); 
			if (op == 'd') Destroy(f); 
			if (op == 's') cout << setiosflags(ios::fixed) << setprecision(3) << cal(f) << endl; 
		}
		//if (cin.get() == EOF) break;
	} 
	
}

