/*
ID: zihaoch1
PROG: maze1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std; 

int di[4] = {1, -1, 0, 0}; 
int dj[4] = {0, 0, 1, -1}; 
int d[200][200]; 
bool visited[200][200]; 
bool Exit[200][200]; 
bool flag[200][200]; 
char ch[300][300]; 
int w, h; 

bool near(int i, int j, int i1, int j1)
{
	bool flag;
	flag = ch[(2 * i - 1 + 2 * i1 - 1) / 2][(2 * j - 1 + 2 * j1 - 1) / 2] == ' ';
	return flag; 
}

struct node
{
	int I,J;
} q[300000];

void bfs(int i,int j)
{
	d[i][j] = 1;
	int first = 0;
	int last = 1;
	q[0].I = i;
	q[0].J = j;
	while (first != last)
	{
		i = q[first].I;
		j = q[first].J;
		flag[i][j] = 1;
		first++;
		for (int t = 0;t < 4;t++)
		{
			if (!(i + di[t] >= 1 && i + di[t] <= h && j + dj[t] >= 1 && \
			j + dj[t] <= w && flag[i + di[t]][j + dj[t]] == 0 && near(i,j,i + di[t], j + dj[t]) && \
			d[i][j] + 1 < d[i + di[t]][j + dj[t]]))
				continue;
			q[last].I = i + di[t];
			q[last].J = j + dj[t];
			d[i + di[t]][j + dj[t]] = min(d[i + di[t]][j + dj[t]], d[i][j] + 1);
			last++;	
		} 
	}
}

int main()
{
	ifstream cin("maze1.in"); 
	ofstream cout("maze1.out"); 
	cin >> w >> h; 
	cin.get();
	for (int i = 0; i <= 2 * h; i++)
		cin.getline(ch[i], 100); 
	for (int i = 0; i <= 2 * h; i++)
		for (int j = 0; j <= 2 * w; j++)
		{
			if (ch[i][j] == ' ' && ( i == 2 * h || j == 2 * w))
				Exit[(i + 1) / 2][(j + 1) / 2] = 1;// cout<<"exit"<<(i + 1) / 2<< ' '<<(j + 1) / 2<<endl; 
			if (ch[i][j] == ' ' && ( i == 0 || j == 0))
				Exit[(i + 2) / 2][(j + 2) / 2] = 1;//cout<<"exit"<<(i + 2) / 2<< ' '<<(j + 2) / 2<<endl;
		}
		
	for (int i = 1; i <= h;i++)
		for (int j =1 ;j <= w;j++)
			d[i][j] = 1000000;

	for (int i = 1;i <= h;i++)
		for (int j = 1;j <= w;j++)
			if (Exit[i][j]) 
			{
				for (int a = 1;a <= h;a++)
					for (int b = 1;b <= w;b++)
						flag[a][b] = 0;
				//cout<<"bfs"<<i<< ' '<< j<<endl;
				bfs(i,j);
			}
	int num = 0; 
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)	
		{
			//cout<<d[i][j]<< ' ';
			num = max(num, d[i][j]); 
		}
		//cout<<endl;
	}
	cout << num << endl; 
}

/*
5 3
+-+-+-+-+-+
          |
+ + + + + +
| | | | | |
+ + + + + +
|            
+-+-+-+-+-+
*/

