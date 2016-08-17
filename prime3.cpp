/*
ID: zihaoch1
PROG: prime3
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#define FOR(x, s, e, step) for (x = s; x <= e; x += step)
#define NUM(x1, x2, x3, x4, x5) (10000 * x1 + 1000 * x2 + 100 * x3 + 10 * x4 + x5)
#define check(x) if (x < 0 || x > 9 || x % 2 == 0) continue; 
using namespace std; 

int a[6][6], num, sum; 
char ans[300][30];  
bool p[99999 + 5]; 

int main()
{
	int first;
	ifstream cin("prime3.in"); 
	ofstream cout("prime3.out"); 
	cin >> sum >> first; 
	
	//pre();
	memset(p, 1, sizeof(p));
	p[1] = 0;
	for (int i = 2; i <= 99999; i++)
	{
		if (p[i] == 0) continue;
		for (int j = i * 2; j <= 99999; j += i)
			p[j] = 0;
	} 
	a[1][1] = first;
	FOR (a[2][2], 0, 9, 1)
		FOR(a[3][3], 0, 9, 1)
			FOR(a[4][4], 0, 9, 1)
			{
				a[5][5] = sum - a[4][4] - a[3][3] - a[2][2] -a[1][1]; 
			 	check(a[5][5]); 
				int tmp = NUM(a[1][1], a[2][2], a[3][3], a[4][4], a[5][5]); 
				if (!p[tmp]) continue; 
				FOR (a[5][1], 1, 9, 2)
					FOR (a[4][2], 0, 9, 1)
						FOR (a[2][4], 0, 9, 1)
						{
							a[1][5] = sum - a[5][1] - a[4][2] - a[3][3] - a[2][4]; 
							check(a[1][5]); 
							int tmp = NUM(a[5][1], a[4][2], a[3][3], a[2][4], a[1][5]); 
							if (!p[tmp]) continue; 
							FOR (a[3][1], 1, 9, 1)
								FOR (a[3][2], 0, 9, 1)
									FOR (a[3][4], 0, 9, 1)
									{
										a[3][5] = sum - a[3][1] - a[3][2] - a[3][3] - a[3][4]; 
										check(a[3][5]); 
										int tmp = NUM(a[3][1], a[3][2], a[3][3], a[3][4], a[3][5]); 
										if (!p[tmp]) continue; 
										FOR (a[2][1], 1, 9, 1)
										{
											a[4][1] = sum - a[1][1] - a[2][1] - a[3][1] - a[5][1]; 
											if (a[4][1] <= 0 || a[4][1] > 9) continue; 
											int tmp = NUM(a[1][1], a[2][1], a[3][1], a[4][1], a[5][1]); 
											if (!p[tmp]) continue; 
											FOR (a[2][5], 1, 9, 2)
											{
												a[2][3] = sum - a[2][1]- a[2][2] - a[2][4] - a[2][5]; 
												if (a[2][3] < 0 || a[2][3] > 9) continue; 
												int tmp = NUM(a[2][1], a[2][2], a[2][3], a[2][4], a[2][5]); 
												if (!p[tmp]) continue; 
												a[4][5] = sum - a[1][5] - a[2][5] - a[3][5] - a[5][5]; 
												check(a[4][5]); 
												tmp = NUM(a[1][5], a[2][5], a[3][5], a[4][5], a[5][5]); 
												if (!p[tmp]) continue; 
												a[4][3] = sum - a[4][1] - a[4][2] - a[4][4] - a[4][5]; 
												if (a[4][3] < 0 || a[4][3] > 9) continue; 
												tmp = NUM(a[4][1], a[4][2], a[4][3], a[4][4], a[4][5]); 
												if (!p[tmp]) continue; 
												FOR (a[5][2],1, 9, 2)
												{
													a[1][2] = sum - a[2][2] - a[3][2] - a[4][2] - a[5][2]; 
													if (a[1][2] <= 0 || a[1][2] > 9)
														continue; 
													int tmp = NUM(a[1][2], a[2][2], a[3][2], a[4][2], a[5][2]); 
													if (!p[tmp]) continue; 
													FOR (a[5][3], 1, 9, 2)
													{
														a[1][3] = sum - a[2][3] - a[3][3] - a[4][3] - a[5][3]; 
														if (a[1][3] <= 0 || a[1][3] > 9)
															continue; 
														tmp = NUM(a[1][3], a[2][3], a[3][3], a[4][3], a[5][3]); 
														if (!p[tmp]) continue; 
														a[1][4] = sum - a[1][1] - a[1][2] - a[1][3] - a[1][5]; 
														if (a[1][4] <= 0 || a[1][4] > 9)
															continue; 
														tmp = NUM(a[1][1], a[1][2], a[1][3], a[1][4], a[1][5]); 
														if (!p[tmp]) continue; 
														a[5][4] = sum - a[1][4] - a[2][4] - a[3][4] - a[4][4]; 
														check(a[5][4]); 
														tmp = NUM(a[1][4], a[2][4], a[3][4], a[4][4], a[5][4]); 
														if (!p[tmp]) continue; 
														tmp = NUM(a[5][1], a[5][2], a[5][3], a[5][4], a[5][5]); 
														if (!p[tmp]) continue; 
														num++; 
														for (int i = 1; i <= 5; i++)
														{
															for (int j = 1; j <= 5; j++)
																ans[num][i * 5 -6 + j]  = a[i][j]  + '0'; 
														}
													}
												}

											}
										}
									}
						}
			}
	for (int i = 1; i <= num - 1; i++)
		for (int j = i + 1; j <= num; j++)
			if (strcmp(ans[i], ans[j]) > 0)
			{
				strcpy(ans[0], ans[i]); 
				strcpy(ans[i], ans[j]); 
				strcpy(ans[j], ans[0]); 
			}
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			for (int k = 1; k <= 5; k++)
				cout << ans[i][j * 5 - 6 + k]; 
			cout << endl; 
		}
		if (i != num) cout << endl; 
	}
}


