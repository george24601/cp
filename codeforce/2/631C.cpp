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
 keep an start and end index,

 for the highest, add all indices > highest to the tail

 sort the first highest numbers

 if the current is ascending, add the end delta to the tail

 if the current is descending, add the front delta to the tail

 for the last one, if ascending, add from small to large

 if descending, add from large to small


 */

int const MaxSize = 200010;

int n, m;
int a[MaxSize];
PII op[MaxSize];

vector<PII> decOp;

int ans[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
//	freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n >> m;

	LPE(i,1, n)
		cin >> a[i];

	LP(i, 0, m)
	{
		int t, r;
		cin >> t >> r;
		op[i] = PII(t, r);
	}

	int curMax = 0;
	for (int i = m - 1; i >= 0; i--) {
		PII curOp = op[i];

		if (curOp.second > curMax) {
			decOp.push_back(curOp);
			curMax = curOp.second;
		}
	}

	reverse(decOp.begin(), decOp.end());

	int si = 1;
	int ei = n;
	int ai = n;

	while (ei > decOp[0].second) {
		ans[ai] = a[ei];
		ei--;
		ai--;
	}

	sort(a + 1, a + ei + 1);

	int nValidOps = decOp.size();

	LP(i, 0, nValidOps)
	{
		int t = decOp[i].first;
		int r = decOp[i].second;

		int nextR = i == nValidOps - 1 ? 0 : decOp[i + 1].second;

		int steps = r - nextR;

		LP(step, 0, steps)
		{
			if (1 == t) {
				ans[ai] = a[ei];
				ei--;

			} else {
				ans[ai] = a[si];
				si++;
			}

			ai--;
		}
	}

	LPE(i, 1, n)
	{
		cout << ans[i];

		if (i < n)
			cout << " ";
		else
			cout << endl;
	}

	return 0;
}
