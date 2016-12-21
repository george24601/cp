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

LL m;

LL solve(LL x) {

	LL total = 0;

	LL k = 2;

	while ((k * k * k) <= x) {

		LL cube = k * k * k;

		total += (x / cube);

		k++;
	}

	return total;
}
/*
 LL solve(LL x) {
 LL ans = 0;
 for (LL k = 2; ans < INF; k++) {
 LL p = k * k * k;
 if (p > x)
 break;
 ans += x / p;
 }
 return ans;
 }
 */

LL bs(LL l, LL r) {
	if (l == r)
		return solve(l) == m ? l : -1;
	if (l > r)
		return -1;

	LL mid = (l + r) / 2;

	if (solve(mid) == m) {
		if (solve(mid - 1) == m)
			return bs(l, mid - 1);
		else
			return mid;
	} else if (solve(mid) > m)
		return bs(l, mid - 1);
	else
		return bs(mid + 1, r);
}

/*
 while (r - l > 1) {
 LL x = (l + r) / 2;
 if (solve(x) >= m)
 r = x;
 else
 l = x;
 }


 if (solve(r) == m)
 printf("%lld\n", r);
 else
 printf("-1\n");
 return l;
 else
 return -1;
 */

int main() {
	ios_base::sync_with_stdio(false);
	freopen("/Users/george/A_1.in", "r", stdin);

	cin >> m;

	cout << bs(1, 8 * m) << endl;

	return 0;
}
