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

#define INF 1e16

pair<double, double> timeRange(double s, double v, double l, double h) {
	if (v == 0) {
		if (s > l && s < h) {
			return make_pair(0, 1e9);
		} else {
			return make_pair(1e9, -1);
		}

	} else if (v < 0) {
		return timeRange(-s, -v, -h, -l);
	} else {
		double timeToL = (l - s) / v;
		timeToL += Ep;
		double timeToR = (h - s) / v;
		timeToR -= Ep;

		if (s <= l)
			return make_pair(timeToL, timeToR);
		else if (s >= h) {
			return make_pair(1e9 + 1, -1);
		} else {
			return make_pair(0, timeToR);
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;

	double minT = -1e9;
	double maxT = 1e9;

	LP(i, 0, n)
	{
		int rx, ry, vx, vy;
		cin >> rx >> ry >> vx >> vy;

		pair<double, double> xt = timeRange(rx, vx, x1, x2);

		//cout << xt.first << " " << xt.second << endl;
		minT = max(minT, xt.first);
		maxT = min(maxT, xt.second);

		pair<double, double> yt = timeRange(ry, vy, y1, y2);
		minT = max(minT, yt.first);
		maxT = min(maxT, yt.second);
	}

	if (minT <= maxT && minT >= 0) {
		cout << setprecision(12);
		cout << minT << endl;
	} else {
		cout << -1;
	}

	return 0;
}
