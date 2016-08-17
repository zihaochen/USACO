/*
ID: zihaoch1
PROG: cryptcow
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<set>
#define debug cout<<"not here\n"
using namespace std; 

int cnt1, cnt2, cnt3; 
const char s[80] = "Begin the Escape execution at the Break of Dawn";
const string str = "Begin the Escape execution at the Break of Dawn" ;
const int N = 99989;
bool hash[1000000];
bool hh[1000000];
vector<char> v;
set<string> m;
int cheat;

int ELFhash(vector<char>::iterator key)
{
   	unsigned long h=0;
    unsigned long x=0;

    while(*key)
    {
        h=(h<<4)+(*key++);  //h左移4位，当前字符ASCII存入h的低四位
                if( (x=h & 0xF0000000L)!=0)
        { //如果最高位不为0，则说明字符多余7个，如果不处理，再加第九个字符时，第一个字符会被移出
          //因此要有如下处理
          h^=(x>>24);
          //清空28~31位
          h&=~x;
        }
    }
    return h % N;
}

int ELFhash(string::iterator key)
{
   	unsigned long h=0;
    unsigned long x=0;

    while(*key)
    {
        h=(h<<4)+(*key++);  //h左移4位，当前字符ASCII存入h的低四位
                if( (x=h & 0xF0000000L)!=0)
        { //如果最高位不为0，则说明字符多余7个，如果不处理，再加第九个字符时，第一个字符会被移出
          //因此要有如下处理
          h^=(x>>24);
          //清空28~31位
          h&=~x;
        }
    }
    return h % N;
}

void swap(int a, int b, int c)
{
	vector<char> tmp1, tmp2; 
	tmp1.insert(tmp1.begin(), v.begin() + a + 1, v.begin() + b); 
	tmp2.insert(tmp2.begin(), v.begin() + b + 1, v.begin() + c); 
	v.erase(v.begin() + a + 1, v.begin() + b); 	
	v.insert(v.begin() + a + 1, tmp2.begin(), tmp2.end());
	v.erase(v.begin() + a + c - b + 1, v.begin() + a+ c - b + c - b );
	v.insert(v.begin() + a + c - b + 1, tmp1.begin(), tmp1.end());
}

bool dfs(int depth)
{
	if (depth == cnt1)
	{
		for (int i = 0; i < v.size(); i++)
			if (v[i] != s[i])
				return 0; 

		return 1; 
	}
	
	if (hash[ELFhash(v.begin())]) return 0;
	hash[ELFhash(v.begin())] =1;
	 
	int last = -1;
	int Len = str.size();
	for (int i = 0; i < v.size();i++)
		if (v[i] == 'C' || v[i] == 'O' || v[i] == 'W')
		{
			if (last == -1)
			{
				last = i;
				continue;
			}
			string tmp;
			tmp.assign(v.begin() + last + 1, v.begin() + i);
			last = i;
			if (hh[ELFhash(tmp.begin())]) continue;
			int tmpLen = tmp.size();
			if (tmpLen == 0) continue;
			bool tmpFlag = 0;
			for (int j = 0; j + tmpLen - 1 < Len;j++)
				if (str.compare(j, tmpLen,tmp) == 0)
				{
					tmpFlag = 1;
					break;
				}
			if (tmpFlag == 0) 
			{
				//debug;
				 return 0;
			}
		}
		
		
	for (int b = 1; b < v.size(); b++)
	{
		if (v[b] != 'O') continue;
		for (int a = 0; a < b; a++)
		{
			if (v[a] != 'C') continue;
			for (int c = v.size() - 1; c > b; c--)
			{
				if (v[a] == 'C' && v[b] == 'O' && v[c] == 'W')
				{ 
					swap(a, b, c); 
					v.erase(v.begin() + c); 
					v.erase(v.begin() + a + c - b); 
					v.erase(v.begin() + a);
					if (dfs(depth + 1)) return 1;  
					v.insert(v.begin() + a, 'C'); 
					v.insert(v.begin() + a + c - b, 'O'); 
					v.insert(v.begin() + c, 'W'); 
					swap(a, a + c - b, c); 
				}
			}
		}
	}
	return 0; 
}

int main()
{
	ifstream cin("cryptcow.in"); 
	ofstream cout("cryptcow.out"); 

	for (int i = 0; i < str.size(); i++)
		for (int j = 0; i + j - 1 < str.size();j++)
			{
				string tmp;
				tmp.assign(str, i , j);
				hh[ELFhash(tmp.begin())] =1;
			}
			
	char ch[80]; 
	cin.getline(ch, 80);
	int len = strlen(ch); 
	for (int i = 0; i < len; i++)
		v.push_back(ch[i]); 
	cnt1 = cnt2 = cnt3 = 0; 
	for (int i = 0; i < len; i++)
	{
		if (ch[i] == 'C') cnt1++; 
		if (ch[i] == 'O') cnt2++; 
		if (ch[i] == 'W') cnt3++; 
	}
	bool flag = 0; 
	if (cnt1 == cnt2 && cnt2 == cnt3)
		flag = 1; 
	if (len - cnt1 - cnt2 - cnt3 != str.size())
		flag = 0;


		
	if (flag) flag = dfs(0); 
	//	if (ch[0] == 'B' && ch[1] == 'e' && ch[2] == 'C' && ch[3] == 'O')
	//		flag = 1;
	if (flag) cout << 1 << ' ' << cnt1 << endl; 
	else cout << 0 <<' '<< 0<< endl; 
}


