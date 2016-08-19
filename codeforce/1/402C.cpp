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

void ans(int n, int p) {
	if (n == 5) {
		assert(p == 0);

		LPE(i, 1, n)
		{
			printf("%d %d\n", i, i + 1 > n ? i + 1 - n : i + 1);
			printf("%d %d\n", i, i + 2 > n ? i + 2 - n : i + 2);
		}

		return;
	}

	int prevMaxP = (n - 1) * (n - 2) / 2 - 2 * (n - 1);

	if (prevMaxP < p) {
		LP(i, 0, 2 + p - prevMaxP)
			printf("%d %d\n", 1 + i, n);

		ans(n - 1, prevMaxP);
	} else {
		LP(i, 0, 2)
			printf("%d %d\n", 1 + i, n);

		ans(n - 1, p);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	int t;
	cin >> t;

	LP(i, 0, t)
	{
		int n, p;
		cin >> n >> p;

		ans(n, p);
	}

	return 0;
}
