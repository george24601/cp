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

//UVa 164 String Computer
//string DP
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

const int MaxSize = 1010;
const int INF = 2000000000;

char f[MaxSize];
char s[MaxSize];

int dist[MaxSize][MaxSize];

int M, N;

void Process() {
	int fLen = M;
	int sLen = N;

	//init 00

	dist[0][0] = 0;

	//init r0
	LPE(si, 1, sLen)
		dist[0][si] = dist[0][si - 1] + 1; //just delete all previous one

	LPE(fi, 1, fLen)
		dist[fi][0] = dist[fi - 1][0] + 1; //just keep inserting

	//init col 0

	LPE(fl, 1, fLen)
	{
		char fc = f[fl - 1];
		LPE(sl, 1, sLen)
		{
			char sc = s[sl - 1];

			int cC = fc == sc ? dist[fl - 1][sl - 1] : dist[fl - 1][sl - 1] + 1; //change last

			int iC = dist[fl][sl - 1] + 1; //add last
			int dC = dist[fl - 1][sl] + 1; //remove last

			if (cC <= iC && cC <= dC) {
				dist[fl][sl] = cC;
			} else if (iC <= cC && iC <= dC) {
				dist[fl][sl] = iC;
			} else {
				dist[fl][sl] = dC;
			}
		}
	}

	printf("%d\n", dist[fLen][sLen]);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %s", &M, f) != EOF) {
		scanf("%d %s", &N, s);
		Process();
	}

	return 0;
}
