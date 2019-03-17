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
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

int const MaxSize = 5000 + 5;
LL const MOD = 1e9 + 7;
LL const BASE = 256;

/*
 bsearch the effort, the two pointer to check if the solution is feasible
 */
int n;
int f[MaxSize][MaxSize], ans[MaxSize][MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
	{
		int a;
		cin >> a;
		f[i][i] = a;
		ans[i][i] = a;
	}

	LPE(d, 1, n)
	{
		LP(l, 0, n)
		{
			if (l + d >= n)
				break;

			f[l][l + d] = f[l][l + d - 1] ^ f[l + 1][l + d];
		}
	}

	LPE(d, 1, n)
	{
		LP(l, 0, n)
		{
			if (l + d >= n)
				break;

			ans[l][l + d] = max(f[l][l + d], ans[l + 1][l + d]);
			ans[l][l+d] = max(ans[l][l + d], ans[l][l + d - 1]);
		}
	}

	int q;
	cin >> q;
	LP(i, 0, q)
	{
		int l, r;
		cin >> l >> r;
		l --;
		r--;
		cout << ans[l][r] << endl;
	}

	return 0;
}
