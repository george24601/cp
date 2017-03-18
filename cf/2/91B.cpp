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
//typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-7

#define INF 1e9
/*
 mins,
 rightmostI

 */

int const MaxSize = 1e5;

int n, a[MaxSize], ans[MaxSize];
set<int> mins;
map<int, int> rightMostI;

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
		cin >> a[i];

	int curMin = INF;

	for (int i = n - 1; i >= 0; i--) {
		int curN = a[i];

		set<int>::iterator it = mins.lower_bound(curN);

		if (it == mins.begin()) {
			ans[i] = -1;
		} else {
			it--;
			int firstV = *it;
			ans[i] = rightMostI[firstV] - i - 1;
		}

		curMin = min(curMin, curN);

		if (rightMostI.count(curN)) {
		} else {
			mins.insert(curMin);
			rightMostI[curN] = i;
		}
	}

	LP(i, 0, n)
	{
		if (i > 0) {
			cout << " ";
		}

		cout << ans[i];
	}

	return 0;
}
