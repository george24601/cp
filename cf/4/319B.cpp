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

#define INF 1e9
int const MaxSize = 1e5 + 10;
int n, a[MaxSize], kt[MaxSize];
stack<int> toL;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
		cin >> a[i];

	kt[0] = -1; //means never killed
	toL.push(0);

	LP(i, 1, n)
	{
		kt[i] = 0;
		while (toL.size() && a[toL.top()] < a[i]) {
			kt[i] = max(kt[i], kt[toL.top()] + 1);
			toL.pop();
		}

		if (toL.size()) {
		} else {
			kt[i] = -1;
		}

		toL.push(i);
	}

	int ans = 0;

	LP(i, 0, n)
		ans = max(ans, kt[i] + 1);

	cout << ans;

	return 0;
}
