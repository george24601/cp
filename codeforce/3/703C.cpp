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

 */

int const MaxSize = 200010;
int n, w, v, u;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d %d %d", &n, &w, &v, &u);

	bool tooSlow = true;
	bool tooFast = true;

	double ans = 0;

	LP(i, 0, n)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		double passTime = (double) x / (double) v;

		if (passTime < 0) {
			tooFast = false;
		} else {
			double pwalk = passTime * (double) u;

			if (pwalk > y)
				tooSlow = false;

			if (pwalk >= y) {
				ans = max(ans, passTime + (double) (w - y) / (double) u);
			}

			if (pwalk < y)
				tooFast = false;
		}
	}

	if (tooSlow || tooFast)
		ans = (double) w / (double) u;

	cout << setprecision(10) << fixed;
	cout << ans << endl;

	return 0;
}

