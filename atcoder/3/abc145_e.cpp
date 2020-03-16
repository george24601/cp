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

#define INF 1e16
const int MaxSize = 3000 + 10;
const LL MOD = 1e9 + 7;

int N, T, A[MaxSize], B[MaxSize], pref[MaxSize][MaxSize],
		suff[MaxSize][MaxSize];

void precalc() {
	LPE(i, 0, N)
	{
		memset(pref[i], 0, sizeof(suff[i]));
		memset(suff[i], 0, sizeof(suff[i]));
	}

	LPE(i, 1, N)
	{
		LP(t, 1, T)
		{
			pref[i][t] = max(pref[i][t], pref[i - 1][t]);

			if (t >= A[i]) {
				pref[i][t] = max(pref[i][t], pref[i - 1][t - A[i]] + B[i]);
			}
		}
	}

	for (int i = N; i >= 1; i--) {
		LP(t, 1, T)
		{
			suff[i][t] = max(suff[i][t], suff[i + 1][t]);

			if (t >= A[i]) {
				suff[i][t] = max(suff[i][t], suff[i + 1][t - A[i]] + B[i]);
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/pycp/A_1.in", "r", stdin);
	cin >> N >> T;
	LPE(i, 1, N)
	{
		cin >> A[i] >> B[i];
	}

	precalc();

	int ans = 0;
	LPE(li, 1, N)
	{
		LP(pt, 0, T)
		{
			ans = max(ans, pref[li - 1][pt] + suff[li + 1][T - 1 - pt] + B[li]);
		}
	}

	cout << ans;

	return 0;
}
