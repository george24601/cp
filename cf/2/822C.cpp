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
int const MaxSize = 2e5 + 10;
int n, x;
string s, t;
map<int, vector<PII> > lenToEI;
pair<int, PII> vs[MaxSize];

int bsMaxI(int targetLen, int l, int h, int left) {
	if (l == h)
		return l;

	int mid = (l + h) / 2;

	int curR = lenToEI[targetLen][mid].first;

	if (curR >= left) {
		return bsMaxI(targetLen, l, mid, left);
	} else if (mid + 1 <= h && lenToEI[targetLen][mid + 1].first < left) {
		return bsMaxI(targetLen, mid + 1, h, left);
	} else {
		return mid;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
//	freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> x;

	LP(i, 0, n)
	{
		int l, r, cost;
		cin >> l >> r >> cost;

		vs[i] = pair<int, PII>(l, PII(r, cost));
	}

	sort(vs, vs + n);

	LL ans = INF;

	LP(i, 0, n)
	{
		int l = vs[i].first;
		int r = vs[i].second.first;
		int len = r - l + 1;
		int cost = vs[i].second.second;

		int targetLen = x - len;

		if (lenToEI.count(targetLen)) {

			int maxI = bsMaxI(targetLen, 0, lenToEI[targetLen].size() - 1, l);

			int foundR = lenToEI[targetLen][maxI].first;
			int thenMinCost = lenToEI[targetLen][maxI].second;

			if (foundR < l) {
				LL newAns = cost + thenMinCost;
				ans = min(ans, newAns);
			}
		}

		int curMinC = cost;

		if (lenToEI.count(len)) {
			int lastI = lenToEI[len].size() - 1;
			curMinC = min(curMinC, lenToEI[len][lastI].second);
		}

		lenToEI[len].push_back(PII(r, curMinC));
	}

	if (ans >= INF)
		cout << -1;
	else
		cout << ans << endl;

	return 0;
}
