#include <iostream>
#include <sstream>
#include <stdio.h>
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
#define Ep 1e-8

/*
 count[root][dist]

 dfs to calculate [root][dist]
 ans += count[root][dist];
 ans +=
 count[root][i] , k - i - 1
 i from 1 to k - 1

 */

int const MaxSize = 50010;

int const MOD = 1000000007;

SAL tree;

int n, k;

LL c[MaxSize][501];
LL ans;

void dfs(int node, int parent) {
	LP(i, 0, tree[node].size())
	{
		int next = tree[node][i];

		if (next == parent)
			continue;

		dfs(next, node);
	}

	c[node][0] = 1;

	LPE(length, 1, k)
	{
		LP(i, 0, tree[node].size())
		{
			int next = tree[node][i];

			if (next == parent)
				continue;

			c[node][length] += c[next][length - 1];
		}
	}

	ans += c[node][k];

	//cout << node << " " << c[node][k] << endl;

	LL fromRoot = 0;

	LPE(childLen, 0, k-2)
	{
		LP(i, 0, tree[node].size())
		{
			int next = tree[node][i];

			if (next == parent)
				continue;

			fromRoot += c[next][childLen]
					* (c[node][k - childLen - 1] - c[next][k - childLen - 2]);

//			cout << "fromRoot " << fromRoot << endl;
		}
	}
	ans += fromRoot / 2;

}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &k);

	tree = SAL(n + 1);

	LP(i, 0, n-1)
	{
		int first, second;
		scanf("%d %d", &first, &second);
		tree[first].push_back(second);
		tree[second].push_back(first);
	}

	LPE(i, 1, n)
		memset(c[i], 0, sizeof(c[i]));

	ans = 0;

	dfs(1, -1);

	cout << ans << endl;

	//print remaining
	return 0;
}
