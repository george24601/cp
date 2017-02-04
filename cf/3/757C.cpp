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

int n, m;
//1e9 = 10^9
LL const mod = 1000000007;

LL fact(LL f) {
	LL ans = 1;

	for (LL i = f; i >= 1; i--) {
		ans *= i;
		ans %= mod;
	}

	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);
	cin >> n >> m;
	//cout << n << " " << m << endl;

	SAL idToGroup(m);

	LP(group, 0, n)
	{
		int nc;
		cin >> nc;

		LP(i, 0, nc)
		{
			int id;
			cin >> id;

			idToGroup[id - 1].push_back(group);
		}
	}

	sort(idToGroup.begin(), idToGroup.end());

	int sizeC = 1;
	LL ans = 1;

	LP(i, 1, m)
	{
		if (idToGroup[i] == idToGroup[i - 1]) {
			sizeC++;
		} else {
			ans *= fact(sizeC);
			ans %= mod;
			sizeC = 1;
		}
	}

	ans *= fact(sizeC);
	ans %= mod;

	cout << ans << endl;

	return 0;
}
