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
#define LP(i, a, b) for (LL i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (LL i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

LL const MaxSize = 1e5 + 5;
LL const MOD = 1e9 + 7;
LL const BASE = 256;

/*


 */

int n, l[MaxSize], r[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n;

	LP(i, 0, n)
	{
		cin >> l[i] >> r[i];
	}

	sort(l, l + n);
	sort(r, r+ n);

	LL ans = n;
	for (int i = n - 1; i >= 0; i--) {
		ans += max(l[i], r[i]);
	}

	cout << ans;

	return 0;
}
