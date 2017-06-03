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
int const MaxSize = 1e5 + 1;
int n, m;
WAL g;
vector<set<int> > travellers;
int vt[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> m;

	g = WAL(n + 1);
	travellers = vector<set<int> >(n + 1);

	LP(i, 0, m)
	{
		int a, b, c;
		cin >> a >> b >> c;

		g.at(a).push_back(PII(b, c));
		g.at(b).push_back(PII(a, c));
	}

	LPE(v, 1, n)
	{
		vt[v] = INF;
		int k;
		cin >> k;

		LP(j, 0, k)
		{
			int tt;
			cin >> tt;
			travellers.at(v).insert(tt);
		}
	}

	priority_queue<PII> toVisit;

	toVisit.push(PII(0, 1));

	while (toVisit.size()) {

		PII tv = toVisit.top();
		toVisit.pop();

		int t = -tv.first;
		int v = tv.second;

		if (vt[v] != INF)
			continue;

		vt[v] = t;

		if (v == n)
			break;

		int delta = 0;
		while (travellers[v].count(t + delta)) {
			delta++;
		}

		LP(i, 0, g.at(v).size())
		{
			int nv = g.at(v)[i].first;
			int w = g.at(v)[i].second;

			toVisit.push(PII(-w - t - delta, nv));
		}
	}

	if (vt[n] == INF)
		cout << -1;
	else
		cout << vt[n];

	return 0;
}
