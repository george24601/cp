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
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-13
#define INF 1e9

int const MaxSize = 1e6 + 10;
LL cacheC[MaxSize], cacheV[MaxSize];

pair<LL, LL> maxN(LL m) {
	if (m <= 0) {
		return PLL(0, 0);
	}

	if (m < MaxSize && cacheC[m]) {
		//cout << "m:" << m << endl;
		return PLL(cacheC[m], cacheV[m]);
	}

	LL maxCb = cbrt(m);
	LL maxCb1 = (maxCb - 1L) * (maxCb - 1L) * (maxCb - 1L);

	//cout << m << " " << maxCb << endl;

	maxCb = maxCb * maxCb * maxCb;

	PLL useMax = maxN(m - maxCb);
	LL useC = 1 + useMax.first;
	LL useV = maxCb + useMax.second;

	LL noUseC = 0;
	LL noUseV = 0;

	if (maxCb - 1 - maxCb1 >= 0) {
		PLL noUse = maxN(maxCb - 1 - maxCb1);
		noUseC = 1 + noUse.first;
		noUseV = maxCb1 + noUse.second;
	}

	LL ansC, ansV;

	if (useC > noUseC || (useC == noUseC && useV > noUseV)) {
		ansC = useC;
		ansV = useV;
	} else {
		ansC = noUseC;
		ansV = noUseV;
	}

	if (m < MaxSize) {
		cacheC[m] = ansC;
		cacheV[m] = ansV;
		//cout << "m:" << m << endl;
	}

	return PLL(ansC, ansV);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	LL m;
	cin >> m;

	pair<LL, LL> ans = maxN(m);
	cout << ans.first << " " << ans.second;

	return 0;
}
