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

 suppose only 1 level



 */

int const MaxSize = 19;
int const SetSize = 1 << 19;
int m, n, k, a[MaxSize];

LL score[MaxSize][SetSize], r[MaxSize][MaxSize];

int nb(int bs) {
	int ans = 0;

	while (bs > 0) {
		if (bs % 2)
			ans++;

		bs /= 2;
	}

	return ans;
}

bool has(int bs, int t) {
	return 1 << t & bs;
}

int rm(int bs, int t) {
	assert(has(bs, t));
	return bs - (1 << t);
}

LL calc(int bs, int t) {
	assert(has(bs, t));

	if (1 == nb(bs))
		return a[t];

	if (score[t][bs] >= 0)
		return score[t][bs];

	LL best = 0;
	LP(prevTail, 0, n)
	{
		if(prevTail == t)
			continue;//appeared once already

		if (!has(bs, prevTail))
			continue;

		LL choice = calc(rm(bs, t), prevTail) + (LL) a[t] + r[prevTail][t];

		best = max(best, choice);
	}

	return score[t][bs] = best;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d %d", &n, &m, &k);

	LP(i, 0, n)
	{
		scanf("%d", &a[i]);
		memset(r[i], 0, sizeof(r[i]));
		memset(score[i], -1, sizeof(score[i]));
	}

	LP(i, 0, k)
	{
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		x--;
		y--;
		r[x][y] = c;
	}

	LL best = 0;

	LP(bs, 1, 1 << n)
	{
		LP(t, 0, n)
		{
			if (!has(bs, t))
				continue;

			LL res = calc(bs, t);

//			cout << bs << " " << nb(bs) << " " << t << " " << res << endl;

			if (nb(bs) == m)
				best = max(best, res);
		}
	}

	cout << best << endl;

	return 0;
}
