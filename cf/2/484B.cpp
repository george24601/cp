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

int const MaxSize = 200010;
int n, a[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	LP(i, 0, n)
		scanf("%d", &a[i]);

	sort(a, a + n);

	int prevV[2000010];

	LP(i, 1, n)
	{
		int curA = a[i];
		int prevA = a[i - 1];
		if (curA == prevA)
			continue;

		LPE(v, prevA + 1, curA)
			prevV[v] = prevA;
	}

	int aMax = a[n - 1];

	LPE(i, aMax + 1, 2 * aMax)
		prevV[i] = aMax;

	int best = 0;

	LP(i, 0, n)
	{
		int curA = a[i];
		int prevA = a[i - 1];
		if (curA == prevA)
			continue;

		int upperB = curA * 2;

		while (upperB <= (2 * aMax)) {

			int mod = prevV[upperB] - (upperB - curA);

			if (mod >= 0)
				best = max(best, mod);

			upperB += curA;

			//cout << upperB << endl;
		}
	}

	cout << best << endl;

	return 0;
}
