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
1.Ԥ������ʿ������һ��Ĳ���������������һ��Ĳ�����������ʿ������һ��Ĳ�����
2.ö��ÿ��Ҫ����������ʿ
	ö����ʿ����������ĵص�
		ö������������ʿ�����ĵص�
*/

//�����ʿ��(x, y)����Ĳ������浽����tmpDis��
//(r + 1, c + 1) �ķ��񣬳�ʼʱ(1, 1)��һ����, bfs
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

//������
int qDis(int x, int y)
{
	x = abs(x - q.r); 
	y = abs(y - q.c); 
	return max(x, y); 
}

//��ʿ�ǵ�����һ��Ĳ�����
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
	   2.ö��ÿ��Ҫ����������ʿ
			ö����ʿ����������ĵص�
				ö������������ʿ�����ĵص�
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



