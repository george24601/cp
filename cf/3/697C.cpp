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

/*

 */

map<LL, LL> el;

LL LCA(LL v, LL u) {
	while (v != u) {
		if (u >= v * 2) {
			LL temp = u;
			u = v;
			v = temp;
		}
		v = v / 2;        // v/2 is parent of vertex v
	}

	return v;
}

void incr(LL l, LL h, LL w) {

//	cout << "incr" << endl;

	LL lca = LCA(l, h);

//cout << "LCA is " << lca << endl;

	while (h > lca) {
		el[h] += w;

		h /= 2;
	}

//	cout << "first node done" << endl;

	while (l > lca) {
		el[l] += w;

		l /= 2;
	}
}

LL calc(LL l, LL h) {
	LL lca = LCA(l, h);

	LL total = 0;
	while (h != lca) {
		total += el[h];
		h /= 2;
	}
	while (l != lca) {
		total += el[l];
		l /= 2;
	}

	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	int q;
	cin >> q;

	LP(i, 0, q)
	{
		int action;
		LL v, u, w;

		cin >> action;

		if (1 == action) {
			cin >> v >> u >> w;
			incr(min(v, u), max(v, u), w);
		} else {
			cin >> v >> u;
			cout << calc(min(v, u), max(v, u)) << endl;
		}
	}

	return 0;
}
