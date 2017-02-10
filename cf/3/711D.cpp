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
#define Ep 1e-7

#define INF 2000000000
//#define INF 1e18
/*

 */

int const MaxSize = 2e5 + 1;
LL const MOD = 1e9 + 7;
SAL g;
int n, nv;
int visited[MaxSize];
int compSize, cycleSize, depth[MaxSize];

void dfs(int v) {
	if (visited[v] > 0)
		return;

	visited[v] = nv;

	compSize++;

	LP(i, 0, g[v].size())
	{
		int next = g[v][i];

		if (visited[next] == nv) {
			cycleSize = depth[v] - depth[next] + 1;
		} else {
			depth[next] = depth[v] + 1;
			dfs(next);
		}
	}
}

LL p2(int t) {
	if (0 == t)
		return 1;
	else {
		LL half = p2(t / 2);
		LL ans = (half * half) % MOD;

		if (t % 2)
			ans = (ans * 2L) % MOD;

		return ans;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	g = SAL(n + 1);

	LPE(from, 1, n)
	{
		int to;
		cin >> to;
		g[from].push_back(to);
	}

	LL ways = 1;

	LPE(v, 1, n)
	{
		if (visited[v])
			continue;

		nv++;
		compSize = 0;
		cycleSize = 0;
		dfs(v);

		if (cycleSize) {
			ways *= p2(cycleSize) - 2;
			ways %= MOD;
		}

		//cout << compSize << " " << cycleSize <<endl;

		ways *= p2(compSize - cycleSize);
		ways %= MOD;
	}

	cout << ways << endl;
}
