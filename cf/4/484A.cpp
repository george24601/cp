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
#define INF 2000000000
#define Ep 1e-8

/*


 */

LL ans(LL l, LL r) {
	if (l == r)
		return l;

	int di = 62;
	while (true) {
		if ((1ll << di) <= r)
			break;
		else
			di--;
	}

	LL curP = 1ll << di;

	if (l >= curP)
		return curP + ans(l - curP, r - curP);
	else if (r == (curP * 2 - 1))
		return curP * 2 - 1;
	else
		return curP - 1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int n;
	cin >> n;

	LP(i, 0, n)
	{
		LL l, r;

		cin >> l >> r;
		cout << ans(l, r) << endl;
	}
}
