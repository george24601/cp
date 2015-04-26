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

//UVa 10066 The twin towers
//longest common subsequence
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

const int MaxSize = 110;
const int INF = 2000000000;

int f[MaxSize];
int s[MaxSize];

int dist[MaxSize][MaxSize];

int N1, N2;
void Process() {
	int fLen = N1;
	int sLen = N2;

	//init 00

	dist[0][0] = 0;

	//init r0
	LPE(si, 1, sLen)
		dist[0][si] = dist[0][si - 1]; //just delete all previous one

	LPE(fi, 1, fLen)
		dist[fi][0] = dist[fi - 1][0]; //just keep inserting

	//init col 0

	LPE(fl, 1, fLen)
	{
		int fc = f[fl - 1];
		LPE(sl, 1, sLen)
		{
			int sc = s[sl - 1];

			int cC = fc == sc ? dist[fl - 1][sl - 1] + 1: dist[fl - 1][sl - 1] - INF; //change last

			int iC = dist[fl][sl - 1]; //add last
			int dC = dist[fl - 1][sl]; //remove last

			if (cC >= iC && cC >= dC) {
				dist[fl][sl] = cC;

			} else if (iC >= cC && iC >= dC) {
				dist[fl][sl] = iC;


			} else {
				dist[fl][sl] = dC;
			}
		}
	}

	printf("Number of Tiles : %d\n\n", dist[fLen][sLen]);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	while(true)
	{
		scanf("%d %d", &N1, &N2);

		if(N1 == 0 && N2 == 0)
			break;

		caseNum++;

		LP(i, 0, N1)
			scanf("%d", &f[i]);

		LP(i, 0, N2)
			scanf("%d", &s[i]);


		printf("Twin Towers #%d\n", caseNum);
		Process();
	}

	return 0;
}
