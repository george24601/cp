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
 1. cconsider the first winter tier day, when to take off?
 consider list of negative days segmsnets, need to allocate remaining tire days to merge the segments

 calucate # of segments, and interval between segments, each merge reduce segment size by 1

 calculate both ends with summer tire or winter tire

 */

int n, k;
vector<int> gap;

int nm(int cap) {

	int ans = 0;

	LP(i, 0, gap.size())
	{

		//	cout << i << " " << gap[i] << " cap:" << cap << endl;
		if (gap[i] > cap)
			break;

		cap -= gap[i];
		ans++;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> k;

	int prevNegI = -1;

	int negC = 0;
	int lastNI = n;

	LP(i, 0, n)
	{
		int t;
		cin >> t;

		if (t >= 0)
			continue;

		if (prevNegI < i - 1 || -1 == prevNegI) {

			if (prevNegI >= 0)
				gap.push_back(i - prevNegI - 1);
		}

		lastNI = i;
		negC++;

		prevNegI = i;
	}

	if (k - negC < 0) {
		cout << -1 << endl;
		return 0;
	} else if (prevNegI < 0) {
		cout << 0 << endl;
		return 0;
	}

	sort(gap.begin(), gap.end());

	int merges = nm(k - negC);

	int numSeg = gap.size() + 1;

	int ans = 2 * (numSeg - merges) - 1;

	//cout << numSeg << " " << merges << endl;

	if (lastNI < n - 1) {
		ans++;

		int rc = k - negC - (n - 1 - lastNI);
		if (rc >= 0) {
			int winterMerge = nm(rc);
			ans = min(ans, 2 * (numSeg - winterMerge) - 1);
		}
	}

	cout << ans << endl;

	return 0;
}
