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

int const MaxSize = 500010;
int n, a[MaxSize], ans[MaxSize], maxRound;

void updateAlt(int si, int ns) {
	int len = ns - si;
	//cout << si << " " << ns << endl;

	maxRound = max(maxRound, (len + 1) / 2);

	if (len % 2) {
		LP(i, si, ns)
			ans[i] = a[si - 1];
	} else {
		int mid = si + len / 2;

		LP(i, si, mid)
			ans[i] = a[si - 1];

		LP(i, mid, ns)
			ans[i] = a[ns];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	LP(i, 0, n)
		scanf("%d", &a[i]);

	bool isA[MaxSize];

	memset(isA, false, sizeof(isA));

	LP(i, 1, n - 1)
		isA[i] = a[i] != a[i - 1] && a[i] != a[i + 1];

	int segStart = -1;
	LP(i, 0, n)
	{
		if (isA[i]) {
			if (segStart == -1)
				segStart = i;

		} else {
			if (segStart >= 0) {
				updateAlt(segStart, i);

				segStart = -1;
			}
			ans[i] = a[i];
		}
	}

	if(segStart >= 0)
		updateAlt(segStart, n);

	printf("%d\n", maxRound);

	LP(i, 0, n)
	{
		if (i < n - 1)
			printf("%d ", ans[i]);
		else
			printf("%d\n", ans[i]);
	}

	return 0;
}

