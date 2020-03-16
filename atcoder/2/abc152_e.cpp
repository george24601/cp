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
const int MaxSize = 1e4 + 10;
const LL MOD = 1e9 + 7;

int N, A[MaxSize], cnt[1000000];
LL lcm;

LL p(LL b, LL po) {
	if (po == 0)
		return (LL)1;
	LL half = p(b, po / (LL)2);

	LL ans = half * half;
	ans %= MOD;

	if (po % 2) {
		ans *= b;
		ans %= MOD;
	}

	return ans;
}

void precalc() {
	LP(i, 0, N)
	{
		int a = A[i];
		LPE(d, 2, floor(sqrt(a)))//note i didn't use A[i]
		{

			int curC = 0;
			while(a % d  == 0){ //better order of actions
				curC++;
				a /= d;
			}
			cnt[d] = max(cnt[d], curC);
		}
		if (a > 1) {
			cnt[a] = max(cnt[a], 1);
		}
	}

	lcm = 1;

	LP(i, 2, 1000000)
	{
		lcm = lcm * p(i, cnt[i]);
		lcm %= MOD;
	}
}
/*
https://atcoder.jp/contests/abc152/tasks/abc152_e
E - Flatten
*/

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/pycp/A_1.in", "r", stdin);
	cin >> N;
	LP(i, 0, N)
	{
		cin >> A[i];
	}

	precalc();

	LL ans = 0;
	LP(i, 0, N)
	{
		ans += (lcm * p(A[i], MOD - 2)) % MOD;
		ans %= MOD;
	}

	cout << ans;

	return 0;
}
