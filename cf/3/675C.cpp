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
 Consider the final state

 each edge passed exactly once

 so the overall count to n - # of bands

 each band will have sum to 0 => we decomposed the problem!

 how to find max # of bands?

 if a band exists, then there exists 2 prefix sums where they are equal

 if 2 prefix sums are equal, we can infer a 0 segments

 */

int const MaxSize = 100010;

int n;
int a[MaxSize];
LL sum[MaxSize];

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	scanf("%d", &n);

	LP(i, 0, n)
		scanf("%d", &a[i]);

	sum[0] = a[0];

	LP(i, 1, n)
		sum[i] = sum[i - 1] + (LL) a[i];

	map<LL, int> count;

	LP(i, 0, n)
		count[sum[i]] += 1;

	int curMax = 0;

	map<LL, int>::iterator it;

	for (it = count.begin(); it != count.end(); it++) {
		curMax = max(curMax, it->second);
	}

	cout << n - curMax << endl;

	return 0;
}
