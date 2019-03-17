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
LL const MOD = 1e9 + 7;
LL const BASE = 256;

/*
 since the overall no more than 2*n costs,
 so we can populate count so far
 */
int sofar[640][MaxSize];
int a[MaxSize];
map<int, int> vToCI;
vector<int> candidates;
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	memset(a, 0, sizeof(a));
	LP(i, 0, 640){
		memset(sofar[i], 0, sizeof(sofar[i]));
	}

	cin >> n >> m;
	map<int, int> cnt;
	LPE(i, 1, n)
	{
		cin >> a[i];
		cnt[a[i]]++;
		if (cnt[a[i]] >= a[i] && !vToCI.count(a[i])) {
			vToCI[a[i]] = candidates.size();
			candidates.push_back(a[i]);
		}
	}

	LPE(i, 1, n)
	{
		LP(ci, 0, candidates.size())
		{
			sofar[ci][i] = sofar[ci][i - 1];
		}

		if (vToCI.count(a[i])) {
			sofar[vToCI[a[i]]][i]++;
		}
	}

	LP(i, 0, m)
	{
		int l, r;
		cin >> l >> r;

		int ans = 0;

		LP(ci, 0, candidates.size())
		{
			if (sofar[ci][r] - sofar[ci][l - 1] == candidates[ci]) {
				ans++;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
