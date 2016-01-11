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

/*

 cost[i][j], make 1...i smooth, with end value j

 cost[i+1][k] =
 if k is in range of j
 update vs delete and insert
 if k is outside range of j
 padding, and back to previous case

 cost(i, v)
 from min(0,v-M), max(255,v+M)
 cost[i][j] = cost(i -1, v') + v- v' +
 from 0 to v-M -1
 insert cost + cost(i, v')
 from v+M+1 to 255
 insert cost + cost(i, v')




 */

int T;
int D, I, M, N;
int const MaxN = 110;
int const MaxV = 255;
int nums[MaxN];

LL cost[MaxN][MaxV + 1];

int singleCost(int from, int to) {
	return min(D + I, abs(to - from));
}

LL increaseCost(int fromV, int toV, int oldN) {
	int smoothFloor = max(0, toV - M);
	int numInserts = (smoothFloor - fromV) / M;

	if ((smoothFloor - fromV) % M)
		numInserts++;

	LL thisCost = numInserts * I + singleCost(oldN, toV);

	return thisCost;
}

LL decreaseCost(int fromV, int toV, int oldN) {

	int smoothCeil = min(toV + M, MaxV);
	int numInserts = (fromV - smoothCeil) / M;

	if ((fromV - smoothCeil) % M)
		numInserts++;

	LL thisCost = numInserts * I + singleCost(oldN, toV);

	return thisCost;
}

LL ccost(int i, int v) {
	assert(i >= 1);
	assert(v >= 0 && v <= MaxV);

	if (cost[i][v] >= 0)
		return cost[i][v];

	LL minVal = INF;
	int smoothFloor = max(0, v - M);

	if (M > 0) {
		LP(fromV, 0, smoothFloor)
		{
			minVal = min(minVal,
					ccost(i - 1, fromV) + increaseCost(fromV, v, nums[i]));
		}
	}

	int smoothCeil = min(v + M, MaxV);

	LPE(fromV, smoothFloor, smoothCeil)
	{
		minVal = min(minVal, ccost(i - 1, fromV) + singleCost(nums[i], v));
	}

	if (M > 0) {
		LPE(fromV, smoothCeil + 1, MaxV)
		{
			minVal = min(minVal,
					ccost(i - 1, fromV) + decreaseCost(fromV, v, nums[i]));
		}
	}

	return cost[i][v] = minVal;
}

void init() {
	int v = nums[1];

	LPE(newV, 0, MaxV)
		cost[1][newV] = singleCost(v, newV);
}

int main() {

	//freopen("/Users/georgeli/B_1.in", "r", stdin);
freopen("/Users/georgeli/Downloads/B-small-practice.in", "r", stdin);
freopen("/Users/georgeli/B_small.out", "w", stdout);

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%d %d %d %d", &D, &I, &M, &N);
	//	printf("%d %d %d %d\n", D, I, M, N);

		LPE(i,1, N)
		{
			memset(cost[i], -1, sizeof(cost[i]));
			scanf("%d", &nums[i]);
		}

		LL minCost = INF;

		init();


		LPE(finalV, 0, MaxV)
			minCost = min(minCost, ccost(N, finalV));

		printf("Case #%d: %d\n", cn, minCost);
	}

	return 0;
}
