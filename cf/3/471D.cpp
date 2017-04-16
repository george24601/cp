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
#define INF 1e9
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-5

int const MaxSize = 2 * 1e5 + 10;

/*

 */
int n, w, da[MaxSize], db[MaxSize];
vector<int> s;
int sl, z[MaxSize * 2 + 1];

void runZ() {
	int l = 0, r = 0;
	z[0] = 0;

	LP(i, 1, sl)
	{
		int curLen;
		if (i > r) {
			curLen = 0;
		} else {
			curLen = min(r - i + 1, z[i - l]);
		}
		while ((i + curLen) < sl && s[curLen] == s[i + curLen]) {
			curLen++;
		}

		z[i] = curLen;

		if (i + z[i] - 1 > r) {
			l = i;
			r = i + curLen - 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
//freopen("/Users/george/A_1.in", "r", stdin);
	cin >> n >> w;

	if(w == 1){
		cout << n << endl;
		return 0;
	}

	int pa;
	cin >> pa;

	LP(i, 1, n)
	{
		int ca;
		cin >> ca;
		da[i] = ca - pa;
		pa = ca;
	}

	cin >> pa;

	LP(i, 1, w)
	{
		int ca;
		cin >> ca;
		db[i] = ca - pa;
		pa = ca;
	}

	LP(i, 1, w)
		s.push_back(db[i]);

	s.push_back(1e9 + 10);

	LP(i, 1, n)
	{
		s.push_back(da[i]);
	}

	sl = n + w - 1;
	runZ();

	int ans = 0;
	LP(i, 1, sl)
	{
		if (z[i] == w - 1)
			ans++;
	}

	cout << ans << endl;

	return 0;
}
