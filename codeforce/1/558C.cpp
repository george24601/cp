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

int const MaxSize = 100010;
int n, a[MaxSize];

int calcP(int a, int b) {
	if (a == b)
		return a;

	int big = max(a, b);
	int small = min(a, b);

	int tempB = big;
	int tempS = small;

	while (tempS > 0) {
		tempS = tempS >> 1;
		tempB = tempB >> 1;
	}

	while (tempB > 0) {
		tempB = tempB >> 1;
		big = big >> 1;
	} //align the prefixes

	int xorRes = big ^ small;

	while (xorRes > 0) {
		big = big >> 1;
		xorRes /= 2;
	}

	return big;
}

int cost(int from, int to) {

	int prefix = calcP(from, to);

	int steps = 0;
	while (from != prefix) {
		from = from >> 1;
		steps++;
	}

	while (from != to) {
		from = from << 1;
		steps++;
	}

	return steps;
}

int main() {
	ios_base::sync_with_stdio(false);
//	freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	int maxA = -INF;

	LP(i, 0,n)
	{
		scanf("%d", &a[i]);
		maxA = max(maxA, a[i]);
	}

	int prefix = a[0];

	LP(i, 1, n)
		prefix = calcP(prefix, a[i]);

	int lowestCost = INF;

	int target = prefix;

	while (target <= maxA) {

		int totalCost = 0;

		LP(i, 0, n)
			totalCost += cost(a[i], target);

		lowestCost = min(lowestCost, totalCost);

		//cout << target << " " << totalCost << endl;

		target *= 2;
	}

	cout << lowestCost << endl;

	return 0;
}
