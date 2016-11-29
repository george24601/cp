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

int n, l, v1, v2, k;

bool possible(double t) {
	double onBusDur = (double) (l - (v1 * t)) / (v2 - v1);
	if (onBusDur <= 0)
		return true;

	double newGap = onBusDur * (v2 - v1);
	double meetCost = newGap / (v2 + v1);

	double ngroup = ceil((double)n / k);
	double totalBusRun = (meetCost + onBusDur) * ngroup;

	return (totalBusRun - meetCost) <= t;
}

double bs(double minT, double maxT) {
	if (maxT - minT <= Ep)
		return maxT;

	double mid = (maxT + minT) / 2.0;

	//cout << "mid:" << mid << endl;

	if (possible(mid)) {
		if (possible(mid - Ep))
			return bs(minT, mid - Ep);
		else
			return mid;
	} else {
		return bs(mid + Ep, maxT);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> l >> v1 >> v2 >> k;

	double minTime = l / (double) v2;
	double maxTime = l / (double) v1;

	double ans = bs(minTime, maxTime);

	cout << setprecision(8) << fixed;
	cout << ans << endl;

	return 0;
}
