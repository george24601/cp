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

int N;
SAL tree;

int const MaxN = 1010;

int cost[MaxN][MaxN];

int fullSize(int from, int root) {
	if (from >= 1 && cost[from][root] >= 0)
		return cost[from][root];

	vector<int> neighbors = tree.at(root);
	int numNeighbor = neighbors.size();

	if (from >= 1 && 1 == numNeighbor)
		return 1;
	else if ((-1 == from && 1 == numNeighbor)
			|| (from >= 1 && 2 == numNeighbor))
		return 1;
	else {

		int subSizes[MaxN];
		int j = 0;

		LP(i, 0, numNeighbor)
		{
			int neighbor = neighbors[i];
			if (neighbor == from)
				continue;

			subSizes[j] = -fullSize(root, neighbor);

			j++;
		}

		sort(subSizes, subSizes + j);

		int overall = 1 - subSizes[0] - subSizes[1];

		if (from >= 1)
			return cost[from][root] = overall;
		else
			return overall;
	}

	assert(false);

	return cost[from][root];
}

int main() {
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/B-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/B_large.out", "w", stdout);

	int T;

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%d", &N);
		//printf("%d %d\n", N, Len);

		tree.clear();

		tree = SAL(N + 1);

		LPE(i, 1,N)
			memset(cost[i], -1, sizeof(cost[i]));

		LP(i, 1 , N)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			tree.at(from).push_back(to);
			tree.at(to).push_back(from);
		}

		int maxSize = 0;

		LPE(root, 1, N)
			maxSize = max(maxSize, fullSize(-1, root));

		printf("Case #%d: %d\n", cn, N - maxSize);
	}

	return 0;
}
