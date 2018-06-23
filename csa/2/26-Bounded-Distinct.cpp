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
typedef long double LD;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

/*

*/

int const MaxSize = 1e5 + 5;

int L, R, N;
int a[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//	freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> N >> L >> R;

	LPE(i, 1, N) //starts with 1, so that we can use 0 and base case instead of 1
	{
		cin >> a[i];
	}

	LL ans = 0;

	map<int, int> id;

	int pe = 0;

	LPE(ei, 1, N)
	{
		int cn = a[ei];
		pe = max(pe, id[cn]); //max, otherwise it may move backwards!!!
		int curLen = ei - pe;

		//		cout << curLen << endl;

		if (curLen >= L) {
			ans += (LL) (min(curLen, R) - L + 1);
		}

		id[cn] = ei;
	}

	cout << ans;

	return 0;
}

