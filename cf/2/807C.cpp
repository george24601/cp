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

#define INF 1e16

/*
 */

LL t, x, y, p, q;

bool same(LL x, LL y, LL p, LL q) {
	return x * q == y * p;
}

bool good(LL t) {
	LL newSub = q * t - y;

	LL newGood = p * t - x;

	return newGood >= 0 && newGood <= newSub;
}

LL minT(LL l, LL h) {
	if (l == h)
		return l;

	LL mid = (l + h) / 2;

	if (good(mid)) {
		return minT(l, mid);
	} else {
		return minT(mid + 1, h);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> t;
	LP(i, 0, t)
	{
		cin >> x >> y >> p >> q;

		if (same(x, y, p, q)) {
			cout << 0 << endl;
		} else if (p == 0 || p == q) {
			cout << -1 << endl;
		} else {
			LL t = minT(1, 1e9);
			cout << t * q - y << endl;
		}
	}

	return 0;
}
