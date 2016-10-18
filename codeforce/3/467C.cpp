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
#define Ep 1e-8

#define INF 2000000100

LL const LINF = 1e18;
/*
 best(i, k) = best(i - 1, k) + best(i - m, k - 1)

 if(i = 0)
 k = 1;

 calc prefix



 */
int const MaxSize = 5010;

LL seg[MaxSize];
LL p[MaxSize];
LL ans[MaxSize][MaxSize];

int n, m, k;

LL best(int i, int ns) {
	if (ns == 0)
		return 0;

	if (i < m - 1)
		return ns == 0 ? 0 : -2;

	if (ans[i][ns] != -1)
		return ans[i][ns];

	LL choice = best(i - 1, ns);

	LL choosePart = best(i - m, ns - 1);

	//cout << i << " " << ns << " " << choosePart << " " << seg[i] << " "		<< choice << endl;

	if (choosePart >= 0) {
		choice = max(choosePart + seg[i], choice);
	}

	return ans[i][ns] = choice;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n >> m >> k;

	LP(i, 0, n)
		cin >> p[i];

	LL curSum = 0;

	LP(i, 0, n)
	{
		curSum += p[i];
		if (i >= m)
			curSum -= p[i - m];

		seg[i] = curSum;
		//	cout << seg[i] << endl;
	}

	LP(i, 0, n)
		memset(ans[i], -1, sizeof(ans[i]));

	cout << best(n - 1, k) << endl;

	return 0;
}
