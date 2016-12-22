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

#define INF 2000000000

/*

 */

int const MaxSize = 501;
int n, a[MaxSize], k, b[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
		cin >> a[i];

	cin >> k;
	LP(i, 0, k)
		cin >> b[i];

	int aLastEnd = -1;

	vector<PII> segs;

	LP(bi, 0, k)
	{
		int total = 0;
		int maxV = -INF;
		int segStart = aLastEnd + 1;
		int segEnd = -1;

		for (int i = segStart; i < n; i++) {

			maxV = max(maxV, a[i]);

			total += a[i];

			if (total == b[bi]) {
				segEnd = i;
				break;
			} else if (total > b[bi]) {
				cout << "NO" << endl;
				return 0;
			}
		}

		int maxI = -1;
		LPE(i, segStart, segEnd)
		{
			if (a[i] != maxV)
				continue;

			if ((i > segStart && a[i] > a[i - 1])
					|| (i < segEnd && a[i] > a[i + 1]) || segStart == segEnd) {

				maxI = i;
				segs.push_back(PII(i, segEnd));
				break;
			}
		}

		if (maxI < 0) {
			cout << "NO" << endl;
			return 0;
		}

		aLastEnd = segEnd;
	}

	if (aLastEnd < n - 1) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	aLastEnd = -1;
	LP(si, 0, segs.size())
	{
		int aMaxI = segs[si].first;
		int aSegEnd = segs[si].second;

		int curSegStart = si + 1;

		int curMaxI = curSegStart + aMaxI - aLastEnd - 1;
		int aLeftI = aMaxI - 1;
		int aRightI = aMaxI + 1;

		int curNum = a[aMaxI];

		while (aLeftI >= aLastEnd + 1 || aRightI <= aSegEnd) {

			if (aLeftI >= aLastEnd + 1 && curNum > a[aLeftI]) {
				cout << curMaxI << " L" << endl;

				curNum += a[aLeftI];
				aLeftI--;
				curMaxI--;
			} else if (aRightI <= aSegEnd && curNum > a[aRightI]) {
				cout << curMaxI << " R" << endl;
				curNum += a[aRightI];
				aRightI++;
			}
		}

		aLastEnd = aSegEnd;
	}

	return 0;
}
