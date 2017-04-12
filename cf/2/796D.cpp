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
#define INF 1e18
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;

int const MaxSize = 3 * 1e5 + 10;

/*

 */

int n, k, d;

bool visited[MaxSize];
PII e[MaxSize];
SAL g;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);
	cin >> n >> k >> d;

	queue<PII> toExpand;

	LP(i, 0, k)
	{
		int v;
		cin >> v;
		toExpand.push(PII(v, 0));
		visited[v] = true;
	}

	g = SAL(n + 1);

	LP(i, 1, n)
	{
		int u, v;
		cin >> u >> v;
		e[i] = PII(min(u, v), max(u, v));

		g.at(u).push_back(v);
		g.at(v).push_back(u);
	}

	set<PII> toKeep;

	while (toExpand.size()) {
		int v = toExpand.front().first;
		int dist = toExpand.front().second;
		toExpand.pop();
		//cout << "at:" << v << " " << dist << endl;
		LP(i, 0, g.at(v).size())
		{
			int next = g.at(v)[i];

			if (dist >= d || visited[next]) {
				//can't expand anymore;
			} else {
				visited[next] = true;
				toExpand.push(PII(next, dist + 1));
				toKeep.insert(PII(min(v, next), max(v, next)));
			}
		}
	}

	cout << n - 1 - toKeep.size() << endl;

	LP(ei, 1, n)
	{
		if (toKeep.count(e[ei])) {

		} else {
			cout << ei << " ";
		}

	}
}
