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
#define Ep 1e-13

#define INF 2e9 + 20
int const MaxSize = 2e3 + 10;
int k, n;
LL a[MaxSize];
set<LL> bs;

bool good(LL cv) {

	set<LL> seen;
	LP(i, 0, k)
	{
		cv += a[i];

		if (bs.count(cv))
			seen.insert(cv);

	}

	return bs.size() == seen.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> k >> n;

	LP(i, 0, k)
	{
		cin >> a[i];
	}

	LL b;
	LP(i, 0, n)
	{
		cin >> b;
		bs.insert(b);
	}

	LL ps = 0;
	set<int> ans;
	LP(i, 0, k)
	{
		ps += a[i];

		if (good(b - ps)) {
			ans.insert(b - ps);
		}
	}

	cout << ans.size();

	return 0;
}
