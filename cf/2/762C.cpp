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
//#define INF 1e18
/*

 */

int const MaxSize = 10000;
int n;
string a, b;

vector<int> process() {
	vector<int> ans(n);

	int bl = 0;

	for (int ai = 0; ai < n && bl < b.size(); ai++) {
		if (a[ai] == b[bl])
			bl++;

		ans[ai] = bl;
	}

	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> a >> b;
	n = a.size();

	vector<int> prefix = process();
	string ca(a);
	string cb(b);

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	vector<int> suffix = process();

	int bestBPLen = 0;
	int bestBSLen = 0;
	int bestLen = 0;

	LP(ai, -1, n)
	{
		int si = n - 1 - ai - 1;

		int curPL = 0;

		if (ai >= 0)
			curPL = prefix[ai];

		int curSL = 0;

		if (si >= 0 && si < a.size())
			curSL = suffix[si];

		if (curPL + curSL > bestLen) {
			bestLen = curPL + curSL;
			bestBPLen = curPL;
			bestBSLen = curSL;
		}

//		cout << prefix[ai] << " " << suffix[si] << endl;
	}

	if (bestLen > b.size()) {
		bestBPLen = b.size();
		bestBSLen = 0;
	}

	if (bestLen) {

		cout << cb.substr(0, bestBPLen);

		string sh = b.substr(0, bestBSLen);

		//cout << sh << endl;

		reverse(sh.begin(), sh.end());
		cout << sh << endl;
	} else {
		cout << "-" << endl;
	}

	return 0;
}
