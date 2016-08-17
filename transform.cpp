/*
ID: zihaoch1
PROG: transform
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int i,j,n;
char a[15][15]={0},b[15][15]={0},c[15][15]={0},tmp[15][15]={0};
int check(char x[15][15] , char y[15][15])
{
   for (i=1 ; i<=n; i++) 
      for (j=1 ; j<=n ; j++)
         if (x[i][j] != y[i][j]) return 0;
   return 1;
}
void turn1(char x[15][15])
{
    for (i=1 ; i<=n; i++) 
      for (j=1 ; j<=n ; j++)
         c[j][n-i+1] = x[i][j] ;
}
void turn2(char x[15][15])
{
     for (i=1 ; i<=n ; i++)
       for (j=1 ; j<=n ; j++) 
         c[i][n-j+1] = x[i][j] ;
 
} 
int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    fin >> n;
    for (i=1 ; i<=n ; i++)
      for (j=1 ; j<=n ; j++) 
            fin >> a[i][j];
    for (i=1 ; i<=n ; i++)
      for (j=1 ; j<=n ; j++)
        fin >> b[i][j];
    turn1(a);
    if (check(b,c)) { fout << "1" << endl;  return 0; }
    memcpy(tmp,c,sizeof(c));turn1(tmp);
    if (check(b,c)) { fout << "2" << endl;  return 0; }
    memcpy(tmp,c,sizeof(c));turn1(tmp);
    if (check(b,c)) { fout << "3" << endl;  return 0; }
    memcpy(tmp,c,sizeof(c));turn2(a);
    if (check(b,c)) { fout << "4" << endl;  return 0; }
    memcpy(tmp,c,sizeof(c));turn1(tmp);
    if (check(b,c)) { fout << "5" << endl;  return 0; }
    memcpy(tmp,c,sizeof(c));turn1(tmp);
    if (check(b,c)) { fout << "5" << endl;  return 0; }
    memcpy(tmp,c,sizeof(c));turn1(tmp);
    if (check(b,c)) { fout << "5" << endl;  return 0; }
    if (check(b,a)) { fout << "6" << endl;  return 0; }
    fout << "7" << endl; 
    return 0;
}
