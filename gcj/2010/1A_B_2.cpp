#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-9

int T;
int D, I, M, N;
int const MaxN = 110;
int const MaxV = 255;
int nums[MaxN];

int cost[MaxN][MaxV + 1];
int tail[MaxN][MaxV + 1];
int insert[MaxN][MaxV + 1];

int singleCost(int from, int to) {
	return min(D + I, abs(from - to));
}

void calcTail(int i) {
	assert(i >= 1);

	LPE(v,0, MaxV)
	{
		tail[i][v] = D + cost[i - 1][v]; //deletion case

		int f = max(0, v - M);
		int c = min(MaxV, v + M);

		LPE(prevV, f, c)
			tail[i][v] = min(tail[i][v],
					singleCost(nums[i], v) + cost[i - 1][prevV]); //update case
	}

}

//TODO: case m = 0
int pureInsert(int from, int to) {
	int diff = abs(from - to);

	if (from == to)
		return 0; //no insertion if they are same

	int numInserts = diff / M;

	if (diff % M)
		numInserts++;

	return numInserts * I;
}

void calcInsert(int i) {
	LPE(v, 0, MaxV)
	{
		insert[i][v] = INF;

		if(M == 0)
			continue;

		LPE(tailV, 0, MaxV)
		{
			insert[i][v] = min(insert[i][v],
					pureInsert(tailV, v) + tail[i][tailV]);
		}
	}

}

int main() {

//	freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/B-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/B_large.out", "w", stdout);

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%d %d %d %d", &D, &I, &M, &N);
		//	printf("%d %d %d %d\n", D, I, M, N);

		LPE(i,1, N)
			scanf("%d", &nums[i]);

		LPE(newV, 0, MaxV)
			tail[1][newV] = singleCost(nums[1], newV);

		calcInsert(1);
		LPE(v, 0, MaxV)
			cost[1][v] = min(tail[1][v], insert[1][v]);

		LPE(i,2, N)
		{
			calcTail(i);
			calcInsert(i);

			LPE(v, 0, MaxV)
			{
				cost[i][v] = min(tail[i][v], insert[i][v]);

				if (i <= 2 && v <= 50) {
					//printf("%d %d %d %d\n", i, v, tail[i][v], insert[i][v]);
				}
			}

		}

		int minCost = INF;
		LPE(finalV, 0, MaxV)
			minCost = min(minCost, cost[N][finalV]);

		printf("Case #%d: %d\n", cn, minCost);
	}

	return 0;
}
