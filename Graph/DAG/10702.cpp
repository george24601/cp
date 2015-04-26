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

//UVa 10354 avoiding your boss
//SSSP
typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 110;
const int MaxM = 1000;

#define maxWin 20

int C, S, E, T;

int good[MaxN][MaxM];

int single[MaxN][MaxN];

bool dest[MaxN];

int DFS(int city, int given) {
	if (good[city][given] >= 0) {

	} else if (given == T) {
		good[city][given] = dest[city] ? 0 : INF;
	} else {

		good[city][given] = INF;

		LP(i, 0, C)
		{
			if(i == city)
				continue;

			int next = DFS(i, given + 1);

			if (next == INF)
				continue;

			int profit = next + single[city][i];

			if (good[city][given] == INF || good[city][given] < profit)
				good[city][given] = profit;
		}
	}

	return good[city][given];
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d %d %d", &C, &S, &E, &T)) {
		if (C == 0 && S == 0 && E == 0 && T == 0)
			break;

		LP(i, 0, C)
		{
			LP(j, 0, C)
				scanf("%d", &single[i][j]);
		}

		memset(dest, false, sizeof(dest));
		LP(i, 0, E)
		{
			int city;
			scanf("%d", &city);

			dest[city - 1] = true;
		}

		LPE(i, 0 , C)
			LPE(j, 0, T)
				good[i][j] = -1;

		int result = DFS(S -1, 0);
		printf("%d\n", result);
	}

	return 0;
}
