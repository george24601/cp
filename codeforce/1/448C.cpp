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

int const MaxSize = 5010;
LL const INF = LL(1e18);

int n;
LL a[MaxSize], ans[MaxSize][MaxSize];

LL mC(int i, int baseI) {

	if (0 == i)
		return 0;

	if (ans[i][baseI] >= 0)
		return ans[i][baseI];

	LL newA;
	if (a[baseI] >= a[i])
		newA = mC(i - 1, i);
	else
		newA = min(mC(i - 1, baseI) + 1, mC(i - 1, i) + a[i] - a[baseI]);

	return ans[i][baseI] = newA;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n;

	a[0] = 0;
	LPE(i, 1, n)
	{
		cin >> a[i];

		memset(ans[i], -1, sizeof(ans[i]));
	}

	cout << mC(n, 0) << endl;

}

