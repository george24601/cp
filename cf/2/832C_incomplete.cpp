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

int const MaxSize = 1e5 + 10;
int n, ts[MaxSize];
LD s, x[MaxSize], v[MaxSize];

LL le(double t) {
	LL ans = 1e6;

	LP(i, 0, n)
	{
		if (ts[i] == 1)
			continue;

		LD X = 1e6 - (double) x[i];
		LD dS = (v[i] * t + s * t - X) * (s - v[i]) / s;

		LL pos = (LL) (((double) x[i]) - dS);

		if (pos > x[i]) {
			ans = min(ans, (LL) x[i]);
		} else {
			ans = min(ans, pos);
		}
	}

	return ans;
}

LL ri(double t) {
	LL ans = 0;

	LP(i, 0, n)
	{
		if (ts[i] == 2)
			continue;

		LD X = (double) x[i];
		LD dS = (v[i] * t + s * t - X) * (s - v[i]) / s;

		LL pos = ceil(X + dS);

		if (pos > x[i]) {
			ans = max(ans, pos);
		} else {
			ans = max(ans, (LL) x[i]);
		}
	}

	return ans;
}

bool good(double t) {
	LL leftMost = le(t);
	LL rightMost = ri(t);

	cout << leftMost << " " << rightMost << endl;

	return leftMost <= rightMost;
}

double minT(double l, double h) {
	if (h - l <= Ep) {
		return l;
	}

	assert(h >= l);

	double mid = (l + h) / 2.0;

	if (good(mid)) {
		return minT(l, mid);
	} else {
		return minT(mid + Ep, h);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> s;

	LP(i, 0, n)
	{
		cin >> x[i] >> v[i] >> ts[i];
	}
	cout << setprecision(12);
	cout << minT(0, 1e6) << endl;

	return 0;
}
