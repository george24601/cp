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
#define Ep 1e-7

//#define INF 2000000000
#define INF 1e18

/*
 notice,

 */

int n;
int const MaxSize = 50000;

int y[MaxSize];

set<int> res;

bool tryReduce(int cap) {
	res.clear();

	LP(i, 0, n)
	{
		bool canShift = false;
		LPE(shift, 0, 30)
		{
			int prefix = y[i] >> shift;

			if (prefix && prefix <= cap && res.count(prefix) == 0) {
				res.insert(prefix);
				canShift = true;
				break;
			}
		}

		if (!canShift)
			return false;

	}

	return true;
}

int bs(int l, int r) {
	if (l == r)
		return l;

	int mid = (l + r) / 2;

	if (tryReduce(mid)) {
		if (tryReduce(mid - 1))
			return bs(l, mid - 1);
		else
			return mid;
	} else
		return bs(mid + 1, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
		cin >> y[i];

	sort(y, y + n);

	int minUpperBound = bs(1, y[n - 1]);

	tryReduce(minUpperBound);

	for (set<int>::iterator it = res.begin(); it != res.end(); it++)
		cout << *it << " ";

	return 0;
}
