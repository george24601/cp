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
#define Ep 1e-8

#define INF 2000000100

/*
 need start and end for segs

 when inserting, update the end of previous start when merge with left
 update the start of next end when with right

 start[p] =p;
 end[p] = p

 if(canMerge)
 end[start[p-1]] = end[p]
 start[p] = start[p-1]

 start[end[p+1]] = start[p]
 end[p] = end[p+1]

 then calc prefix sum, and insert the max

 and finally print ans in reverse order


 */

int const MaxSize = 100010;
int n;
LL a[MaxSize], ps[MaxSize], ans[MaxSize], prefix[MaxSize];
set<int> remain;


int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n;

	a[0] = 0;
	remain.insert(0);
	LPE(i, 1, n){
		cin >> a[i];
		remain.insert(i);
	}

	LPE(i, 1, n)
		cin >> ps[i];

	prefix[0] = 0;
	LPE(i, 1, n)
		prefix[i] = prefix[i - 1] + a[i];

	LL curMax = 0;

	for (int pi = n; pi >= 1; pi--) {
		ans[pi] = curMax;
		int pos = ps[pi];

		remain.erase(pos);

		int curEnd;

		set<int>::iterator nextIt = remain.lower_bound(pos);

		if(nextIt == remain.end())
			curEnd = n;
		else
			curEnd = (*nextIt) - 1;

		int prevEnd;

		prevEnd = *(--nextIt);

		LL newSum = prefix[curEnd] - prefix[prevEnd];

		//cout << curEnd << " " << prevEnd << " " << newSum << endl;

		curMax = max(curMax, newSum);
	}

	LPE(ai, 1, n)
		cout << ans[ai] << endl;

	return 0;
}
