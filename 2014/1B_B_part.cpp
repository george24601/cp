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
 */

int A, B, K;
int const MaxSize = 32;

LL _ways[MaxSize][2][2][2];

int getBit(int num, int bitPos) {
	return (num >> bitPos) & 1;
}

LL ways(int bitPos, int APre, int BPre, int KPre) {

	if (_ways[bitPos][APre][BPre][KPre] >= 0)
		return _ways[bitPos][APre][BPre][KPre];

	LL result = 0;

	int curABit = getBit(A, bitPos);
	int curBBit = getBit(B, bitPos);
	int curKBit = getBit(K, bitPos);

	bitPos--;

	//Insight: how to simplify it?instead of turning it into a giant nested statement?

	return _ways[bitPos][APre][BPre][KPre] = result;
}

int main() {
	freopen("/Users/georgeli/B_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/B_large.out", "w", stdout);

	int T;

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%d %d %d", &A, &B, &K);
		//printf("%d %d\n", N, Len);

		printf("Case #%d: %lld\n", cn, ways(31, 1, 1, 1));
	}

	return 0;
}
