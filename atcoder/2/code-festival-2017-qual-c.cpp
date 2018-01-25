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

int const MaxSize = 1e5 + 5;

string s;
int ans;

void calc(int si, int ei) {
	if (si >= ei) {
		return;
	}

	//cout << si << " " << ei << endl;
	if (s[si] == s[ei]) {
		calc(si + 1, ei - 1);
	} else if (s[si] == 'x') {
		ans++;
		calc(si + 1, ei);
	} else if (s[ei] == 'x') {
		ans++;
		calc(si, ei-1);
	} else {
		ans = -1;
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);
	cin >> s;

	calc(0, s.size() - 1);
	cout << ans << endl;

	return 0;
}
