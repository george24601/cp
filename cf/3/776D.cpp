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
#define Ep 1e-13

#define INF 1e9
int const MaxSize = 1e5 + 10;
int n, m;
int open[MaxSize], visited[MaxSize];
WAL g;
bool good;

void dfs(int v, int c) {
	if (visited[v]) {
		if (visited[v] != c)
			good = false;
	} else {
		visited[v] = c;

		LP(i, 0, g.at(v).size())
		{
			PII uw = g.at(v)[i];
			int u = uw.first;
			int w = uw.second;

			if (w) {
				dfs(u, c);
			} else {
				dfs(u, c == 1 ? 2 : 1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> m;

	LPE(d, 1, n)
		cin >> open[d];

	SAL dToHs(n + 1);
	g = WAL(m);
	LP(h, 0, m)
	{
		int x;
		cin >> x;

		LP(j, 0, x)
		{
			int d;
			cin >> d;
			dToHs[d].push_back(h);

			if (dToHs[d].size() == 2) {
				int fh = dToHs[d][0];
				int sh = dToHs[d][1];

				g.at(fh).push_back(PII(sh, open[d]));
				g.at(sh).push_back(PII(fh, open[d]));
			}
		}
	}

	good = true;
	LP(h, 0, m)
	{
		if (!visited[h])
			dfs(h, 1);
	}

	if (good)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
