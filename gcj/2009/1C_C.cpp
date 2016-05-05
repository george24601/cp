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

int N, Q, P;
int const MaxSize = 110;
int qs[MaxSize];

int val[MaxSize][MaxSize];

int dist(int sI, int eI) {
	assert(1 <= sI <= eI <= Q);

	int ps = qs[sI - 1];
	if (sI > 1)
		ps++;

	int pe = qs[eI + 1];
	if (eI < Q)
		pe--;

	return pe - ps;
}

int p_r(int sI, int eI) {
	if (val[sI][eI] >= 0)
		return val[sI][eI];

	assert(eI >= sI);

	//printf("%d %d\n", sI, eI);

	int leftMostCut = max(1, sI);
	int rightMostCut = min(Q, eI);

	if (leftMostCut == rightMostCut)
	{
		val[sI][eI] = dist(sI, eI);
		//printf("%d %d %d\n", sI, eI, val[sI][eI]);
		return val[sI][eI];
	}

	int minVal = dist(sI, eI) + p_r(leftMostCut+1, eI);
	minVal = min(minVal,
			dist(sI, eI) + p_r(sI, rightMostCut -1));

	LPE(toGo, leftMostCut + 1, rightMostCut - 1)
	{
		minVal = min(minVal,
				p_r(sI, toGo - 1) + p_r(toGo + 1, eI) + dist(sI, eI));
	}

	//printf("%d %d %d\n", sI, eI, minVal);

	return val[sI][eI] = minVal;
}

int main() {

	//freopen("/Users/georgeli/C_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/C-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/C_large.out", "w", stdout);

	scanf("%d", &N);

	LPE(cn, 1, N)
	{
		scanf("%d %d", &P, &Q);

		LPE(i,0, Q + 1)
			memset(val[i], -1, sizeof(val[i]));

		LPE(i,1, Q)
			scanf("%d", &qs[i]);
		qs[0] = 1;

		qs[Q + 1] = P;

		int minVal = p_r(1, Q);

		printf("Case #%d: %d\n", cn, minVal);
	}

	return 0;
}
