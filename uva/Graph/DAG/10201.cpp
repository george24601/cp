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
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 110;
const int MaxK = 210;

const int Full = 200;

int total[MaxN][MaxK];

int dist[MaxN], cost[MaxN];
int n;
int finalDist;

int DFS_r(int stop, int liter) {
	if (total[stop][liter] >= 0)
		return total[stop][liter];

	total[stop][liter] = INF;

	LP(i, stop+1, n)
	{
		int nextDist = dist[i] - dist[stop];

		if (nextDist > Full)
			break;

		LPE(remaining, 0, Full - nextDist)
		{
			int toFill = remaining + nextDist - liter;

			if (toFill < 0)
				continue;

			int remainingCost = DFS_r(i, remaining);

			if (remainingCost == INF)
				continue;

			total[stop][liter] = min(total[stop][liter],
					remainingCost + toFill * cost[stop]);
		}
	}

	int directDist = abs(finalDist - dist[stop]);

	if (directDist <= 100) {
		int toFill = directDist + 100 - liter;
		int directCost = toFill > 0 ? toFill * cost[stop] : 0;
		total[stop][liter] = min(total[stop][liter], directCost);
	}

	return total[stop][liter];
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	char buf[1024];

	int numCase;
	scanf("%d", &numCase);

	LPE(c,1, numCase)
	{
		if (c > 1)
			printf("\n");

		while (gets(buf) != NULL && sscanf(buf, "%d", &finalDist) != 1)
			;

		for (n = 0; gets(buf);) {
			if (sscanf(buf, "%d %d", &dist[n], &cost[n]) != 2)
				break;
			n++;
		}

		LPE(i, 0, n)
		{
			LPE(j, 0, Full)
				total[i][j] = -1;
		}

		int total = INF;

		LP(i, 0, n)
		{
			if (dist[i] <= 100)
				total = min(total, DFS_r(i, 100 - dist[i]));
		}

		if (total == INF)
			printf("Impossible\n");
		else
			printf("%d\n", total);
	}

	return 0;
}
