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

int const MaxSize = 1e5 + 10;
int n, m;
LL x[MaxSize], y[MaxSize];

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);
	cin >> n >> m;
	LP(i, 0, n)
	{
		cin >> x[i];
	}
	sort(x, x + n);

	LL MOD = 1e9 + 7;
	LL xSum = 0;
	LP(i, 0, n)
	{
		xSum += (2 * i - n + 1) * x[i];
		xSum %= MOD;
	}

	LP(i, 0, m)
		cin >> y[i];

	sort(y, y + m);

	LL ySum = 0;
	LP(i, 0, m)
	{
		ySum += (2 * i - m + 1) * y[i];
		ySum %= MOD;
	}

	LL ans = xSum * ySum;
	ans %= MOD;

	cout << (ans + MOD) % MOD << endl;

	return 0;
}
