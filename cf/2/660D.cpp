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

int n, x[MaxSize], y[MaxSize];
map<PII, int> cnt;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n;

	LP(i, 0, n)
	{
		cin >> x[i] >> y[i];
	}

	LP(i, 0, n)
	{
		LP(j, i + 1, n)
		{
			cnt[PII(x[i] + x[j], y[i] + y[j])]++;
		}
	}

	LL ans = 0;
	for (map<PII, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
		LL curC = it->second;
		ans += curC * (curC - (LL)1) / (LL)2;
	}

	cout << ans;

	return 0;
}
