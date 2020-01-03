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

LL const MOD = 1e9 + 7;
LL const MaxSize = 300 + 5;
//LL const MOD = 998244353;

/*

https://atcoder.jp/contests/abc132/tasks/abc132_d
D - Blue and Red Balls

 Easy problem, but python version gives TLE in the last two cases
 */

//NOTE WORKS ONLY WHEN MOD IS PRIME
LL N, K;
//test case, either = 1 or all = 1

LL p(LL base, LL power) {
	if (power == 0)
		return 1;
	else if (power == 1)
		return base;
	LL half = p(base, power / 2);
	LL ans = (half * half) % MOD;

	if (power % 2) {
		ans *= base;
		ans %= MOD;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> N >> K;

	cout << N - K + 1 << endl; //only 1 move

	int moveUB = (N - K) >= K - 1 ? K : N - K + 1;
	LPE(i, 2, moveUB)
	{
		LL freeB = K - i;
		LL freeR = N - K - (i - 1);
		LL ways = p(i, freeB) * p(i + 1, freeR);
		ways %= MOD;
		cout << ways << endl;
	}

	LPE(i, moveUB + 1, K)
		cout << 0 << endl;
	return 0;
}

