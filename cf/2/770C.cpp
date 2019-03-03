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
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

int const MaxSize = 1e5 + 5;
int const MOD = 1e9 + 7;

int n, k;
int state[MaxSize];
vector<int> toVisit;
vector<int> ans;
bool hasCycle;
SAL g;

void dfs(int v, int p) {
	if (state[v] != 0)
		return;
	state[v] = 1;

	LP(i, 0, g.at(v).size())
	{
		int u = g.at(v)[i];
		//note that because this is directed, we can't ignore the case where u == parents
		//if it is undirected, we may need to ignore, espeically if it is a tree
		//more likely then not we need to check all

		if (state[u] == 1) {
			hasCycle = true;
			return;
		} else {
			dfs(u, v);
		}
	}

	ans.push_back(v);
	state[v] = 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n >> k;
	g = SAL(n + 1);

	LP(i, 0, k)
	{
		int c;
		cin >> c;
		toVisit.push_back(c);
	}

	LPE(v, 1, n)
	{
		int t;
		cin >> t;
		LP(i, 0, t)
		{
			int u;
			cin >> u;
			g.at(v).push_back(u);
		}
	}

	LP(i, 0, k)
	{
		dfs(toVisit[i], -1);
	}

	if (hasCycle) {
		cout << -1;
		return 0;
	}

	cout << ans.size() << endl;
	LP(i, 0, ans.size())
	{
		cout << ans[i] << " ";
	}

	return 0;
}
