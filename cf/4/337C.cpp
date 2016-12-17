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

 suppose only 1 level



 */

int n, m, k;

/*
 f(num) + 2K = 2(f(num-1) + 2k)

 */

LL const MOD = 1000000009;

LL p2(LL pn) {
	if (0 == pn)
		return 1;

	LL halfPower = p2(pn / 2);

	LL res = halfPower * halfPower % MOD;

	if (pn % 2) {
		res *= 2;
		res %= MOD;
	}

	return res;
}

LL score(LL firstL) {
	LL numKRules = firstL / k;

	if (0 == numKRules)
		return m;

	LL remaining = m - numKRules * k;

	LL fn = (p2(numKRules - 1) * 4) % MOD;
	fn = (fn * k) % MOD;

	//cout << fn << " " << remaining << endl;

	LL ans = (fn - 2 * k + remaining) % MOD;

	if (ans < 0)
		ans += MOD;

	return ans;
}

LL maxFit(LL firstL) {

	LL numKBands = (n - firstL) / k;

	LL fromKBands = numKBands * (LL) (k - 1);

	LL remaining = 0;

	if ((n - firstL) % k)
		remaining = n - firstL - numKBands * k - 1; //1 for padding

	return firstL + fromKBands + remaining;
}

LL fl(LL l, LL h) {
	if (l == h)
		return l;

	assert(h >= 0);

	//cout << l << " " << h << endl;

	LL mid = (l + h) / 2;

	LL ansToFit = maxFit(mid);

	if (ansToFit < m) {
		//first too short to hold m
		return fl(mid + 1, h);
	} else {
		if (mid == l)
			return mid;
		else if (maxFit(mid - 1) >= m) //can squeeze more?
			return fl(l, mid - 1);
		else
			return mid;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &k);

	if (m == 0) {
		cout << 0 << endl;
		return 0;
	}

	int minFirstLen = fl(1, n);

	//cout << "len at: " << minFirstLen << endl;

	cout << score(minFirstLen) << endl;

	return 0;
}
