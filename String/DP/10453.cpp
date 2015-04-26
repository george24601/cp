#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

//UVa 10739 String to Palindrome
//edit distance variant - string dp
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int MaxSize = 1005;
const int INF = 2000000000;

char f[MaxSize];

int dist[MaxSize][MaxSize];
int op[MaxSize][MaxSize];

void P_r(int s, int e)
{
	if(s == e)
	{
		printf("%c", f[s]);
		return;
	}else if(e == s+1)
	{
		printf("%c", f[s]);
		printf("%c", f[e]);

		if(f[s] != f[e])
			printf("%c", f[s]);

		return;
	}

	if(op[s][e] == 1)
	{

		printf("%c", f[s]);
		P_r(s+1, e-1);
		printf("%c", f[e]);

	}else if(op[s][e] == 2)
	{
		printf("%c", f[s]);
		P_r(s+1, e);
		printf("%c", f[s]);

	}else
	{
		printf("%c", f[e]);
		P_r(s, e-1);
		printf("%c", f[e]);
	}


}
void Process() {
	int fLen = strlen(f);

	//len 1
	LP(i,0, fLen)
		dist[i][i] = 0;

	//len 2
	LP(i, 0, fLen -1)
	{
		if (f[i] == f[i + 1])
			dist[i][i + 1] = 0;
		else
			dist[i][i + 1] = 1;
	}

	LPE(len, 3, fLen)
	{
		for (int start = 0; start + len <= fLen; start++) {
			int end = start + len - 1;

			int both = dist[start + 1][end - 1];
			if (f[start] != f[end])
				both += INF;

			int left = dist[start + 1][end] + 1; //add to right
			int right = dist[start][end - 1] + 1;//add to left

			if(both <= left && both <= right)
			{
				dist[start][end] = both;
				op[start][end] = 1;


			}else if(left <= both && left <= right)
			{
				dist[start][end] = left;
				op[start][end] = 2;

			}else
			{
				dist[start][end] = right;
				op[start][end] = 3;
			}
		}
	}

	printf("%d ", dist[0][fLen - 1]);
	P_r(0, fLen-1);
	printf("\n");
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%s", f) == 1) {
		Process();

	}

	return 0;
}
