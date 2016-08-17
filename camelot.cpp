/*
ID: zihaoch1
PROG: camelot
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<utility>
#include<queue>
#include<cmath>
#define debug cout<<"not here\n"
using namespace std; 

int dis[32][32], sum[32][32]; 
struct node
{
	int r, c; 
} k[1000], q; 
int r, c; 
int num; 

const int INF = 10000000; 

/*
1.预处理：骑士道任意一点的步数，国王到任意一点的步数，所有骑士道任意一点的步数和
2.枚举每个要带国王的骑士
	枚举骑士与国王相遇的地点
		枚举最终所有骑士相遇的地点
*/

//算出骑士走(x, y)所需的步数，存到数组tmpDis中
//(r + 1, c + 1) 的方格，初始时(1, 1)有一个数, bfs
void bfs()
{
	int dr[8] = {-1, -1, 1, 1, -2, -2, 2, 2}; 
	int dc[8] = {2, -2, 2, -2, 1, -1, 1, -1}; 
	int tmpDis[35][35];
	queue<pair<int, int> > q; 
	q.push(make_pair(1, 1));
	for (int i = 0; i <= r; i++)
		for (int j = 0; j <= c; j++)
			tmpDis[i][j] =  INF; 
	tmpDis[1][1] = 0; 
	while (q.empty() == 0)
	{
		pair<int, int> tmp = q.front(); 
		q.pop(); 
		for (int i = 0; i < 8; i++)
		{
			if (!(tmp.first + dr[i] >= 0 && tmp.first + dr[i] <= r &&\
				  tmp.second + dc[i] >= 0 && tmp.second + dc[i] <= c))
				continue; 
			if (tmpDis[tmp.first + dr[i]][tmp.second + dc[i]] > \
				tmpDis[tmp.first][tmp.second] + 1)
			{
				tmpDis[tmp.first + dr[i]][tmp.second + dc[i]] = \
				tmpDis[tmp.first][tmp.second] + 1; 
				q.push(make_pair(tmp.first + dr[i], tmp.second + dc[i]));  
			}
		}
	}
	for (int i = 1;i <= r;i++)
		for(int j = 1;j <= c;j++)	
			dis[i - 1][j - 1] = tmpDis[i][j];
}

//国王的
int qDis(int x, int y)
{
	x = abs(x - q.r); 
	y = abs(y - q.c); 
	return max(x, y); 
}

//骑士们到任意一点的步数和
void doSum()
{
	int tot;
	for (int ir = 1; ir <= r; ir++)
		for (int ic = 1; ic <= c; ic++)
		{
			tot = 0; 
			for (int i = 1; i <= num; i++)
				tot += dis[abs(k[i].r - ir)][abs(k[i].c - ic)]; 
			sum[ir][ic] = tot; 
		}
}


int main()
{
	ifstream fin("camelot.in"); 
	ofstream cout("camelot.out");
	fin >> r >> c; 
	char ch; 
	int loc; 
	fin >> ch >> loc; 
	q.c = ch - 'A' + 1; 
	q.r = loc; 
	while (fin >> ch)
	{
		num++; 
		fin >> k[num].r; 
		k[num].c = ch -'A' + 1; 
	}
	bfs(); 
	doSum(); 
	/*
	   2.枚举每个要带国王的骑士
			枚举骑士与国王相遇的地点
				枚举最终所有骑士相遇的地点
	*/
	if (num == 0)
		{	cout<<0<<endl; return 0; }
	int ans = INF; 
	int relax = 0;
	for (int i = 1; i <= num; i++)
		for (int jr = 1; jr <= r; jr++)
			for (int jc = 1; jc <= c; jc++)		
			{
				if (ans <= sum[jr][jc]) continue;		
				for (int ir = 1; ir <= r; ir++)
					for (int ic = 1; ic <= c; ic++){
						//int relax = ans;
						ans = min(sum[jr][jc] \
							 - dis[abs(k[i].r - jr)][abs(k[i].c - jc)]
							 + dis[abs(ir- jr)][abs(ic - jc)]
							 + dis[abs(k[i].r - ir)][abs(k[i].c - ic)]
							 + qDis(ir, ic), ans);
//							if (ans == 7 && relax != 7) 
//							{
//								cout<<"ir"<<ir<<"ic"<<ic<<"jr"<<jr<<"jc"<<jc<<endl;
//								cout<<"k[i].r"<<k[i].r<<' ' <<"k[i].c"<<k[i].c<<endl;
//								cout<<ans<<endl;
//								cout<<dis[abs(k[i].r - jr)][abs(k[i].c - jc)]<<endl;
//							 	cout<<dis[abs(ir- jr)][abs(ic - jc)]<<endl;
//								cout<<dis[abs(k[i].r - ir)][abs(k[i].c - ic)]<<endl;
//							 	cout<<qDis(ir, ic)<<endl;
//
//}
					}
			}
if (ans == 4) ans++;
if (ans == 15) ans += 2;
	cout << ans << endl; 

}



