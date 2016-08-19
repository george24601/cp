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

LL ans(bool left, int h, LL n) {
	if (0 == h) {
		assert(1 == n);
		return 0;
	}

	LL half = 1LL << (h - 1);

	if (left) {
		if (n > half)
			return half * 2LL + ans(true, h - 1, n - half);
		else
			return 1LL + ans(false, h - 1, n);
	} else {
		if (n > half)
			return 1LL + ans(true, h - 1, n - half);
		else
			return half * 2LL + ans(false, h - 1, n);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	LL h, n;

	cin >>h >> n;

	cout << ans(true, h, n) << endl;

	return 0;
}
