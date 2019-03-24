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
typedef long double LD;
#define LP(i, a, b) for (LL i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (LL i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

LL const MaxSize = 400000 + 5;
LL const MOD = 1e9 + 7;
LL const BASE = 256;

/*
 */

SAL big;
int n, m, q;
bool visited[MaxSize];

void dfs(int v) {
	if (visited[v])
		return;

	visited[v] = true;

	LP(i, 0, big[v].size())
	{
		int u = big[v][i];
		dfs(u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n >> m >> q;

	big = SAL(n + m + 1);

	LP(i, 0, q)
	{
		int r, c;
		cin >> r >> c;

		big[r].push_back(n + c);
		big[n + c].push_back(r);
	}

	int cnt = 0;

	LPE(v, 1, n + m)
	{
		if (visited[v]) {

		} else {
			cnt++;
			dfs(v);
		}
	}

	cout << cnt - 1 << endl;

	return 0;
}
