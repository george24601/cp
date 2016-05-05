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
 start from rightmost

 if a chick can reach end,
 total # += unable
 possible++
 else
 unable++




 */

int C;
int N, K, B, T;
int const MaxN = 50;
int x[MaxN];
int v[MaxN];

int main() {

	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/B-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/B_large.out", "w", stdout);

	scanf("%d", &C);

	LPE(cn, 1, C)
	{
		scanf("%d %d %d %d", &N, &K, &B, &T);

		LP(i, 0, N)
			scanf("%d", &x[i]);

		LP(i, 0, N)
			scanf("%d", &v[i]);

		int possible = 0;
		int impossible = 0;
		int passes = 0;

		int i = N - 1;

		while (i >= 0 && possible < K) {
			int distToCover = B - x[i];
			double minV = ((double) distToCover) / ((double) T);

			//printf("%d %d %d %d\n", x[i], v[i], possible, impossible);

			if (minV <= v[i]) {
				possible++;
				passes += impossible;
			} else {
				impossible++;
			}

			i--;
		}

		if (possible < K) {
			printf("Case #%d: IMPOSSIBLE\n", cn);
		} else {
			printf("Case #%d: %d\n", cn, passes);
		}
	}

	return 0;
}
