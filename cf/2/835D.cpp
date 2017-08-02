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

int const MaxSize = 5000 + 10;
string s;
int n, cnt[MaxSize], d[MaxSize][MaxSize], isPa[MaxSize][MaxSize];

bool pa_dp(int start, int end) {
	if (start >= end) {
		return true;
	} else if (isPa[start][end] >= 0) {
		return isPa[start][end];
	}

	return isPa[start][end] = s[start] == s[end] && pa_dp(start + 1, end - 1);
}

int maxD_dp(int start, int end) {
	if (start >= end) {
		return 1;
	}

	if (!pa_dp(start, end))
		return 0;

	int leftLen = (end - start + 1) / 2;

	int leftDeg = maxD_dp(start, start + leftLen - 1);

	return d[start][end] = leftDeg + 1;

}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);
	cin >> s;
	n = s.size();

	LP(i, 0, n)
	{
		memset(isPa[i], -1, sizeof(isPa[i]));
		memset(d[i], -1, sizeof(d[i]));
	}

	LP(i, 0, n)
	{
		LP(j, i, n)
		{
			int maxDeg = maxD_dp(i, j);
			cnt[maxDeg]++;
		}
	}

	for (int deg = n - 1; deg >= 0; deg--)
		cnt[deg] += cnt[deg + 1];

	LPE(deg, 1, n)
		cout << cnt[deg] << " ";

	return 0;
}
