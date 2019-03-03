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

int const MaxSize = 1000 + 5;
LL const MOD = 1e9 + 7;
LL const BASE = 256;

/*
 */
string t, sBegin, sEnd;
set<int> bi, ei;
map<int, int> cnt;
void pre() {
	int i = 0;
	while (true) {
		i = t.find(sBegin, i);
		if (i == string::npos) {
			break;
		} else {
			bi.insert(i);
			i++;
		}
	}

	i = 0;
	while (true) {
		i = t.find(sEnd, i);
		if (i == string::npos) {
			break;
		} else {
			ei.insert(i);
			i++;
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> t >> sBegin >> sEnd;

	pre();

	int n = t.size();
	int ans = 0;
	LPE(winL, max(sBegin.length(), sEnd.length()), n)
	{
		LL hash = 0;
		LL topBase = 1;
		LP(i, 0, winL)
		{
			if (i > 0) {
				topBase *= BASE;
				topBase %= MOD;
			}

			hash *= BASE;
			hash %= MOD;
			hash += (LL)(t[i] - 'a');
			hash %= MOD;
		}

		if (bi.count(0) && ei.count(winL - sEnd.length())) {
		//	cout << 0 << " " << winL << " " << hash << endl;
			cnt[hash]++;
		}

		LP(i, winL, n)
		{
			//slide the hash
			LL oh = hash;
			hash -= topBase * (LL)(t[i - winL] - 'a');
			hash %= MOD; //watch out for the negative case!
			hash += MOD;
			hash %= MOD;

	//		cout << (i - winL + 1) << " " << winL << " " << (LL)oh << " " << (LL)hash << endl;
			hash *= BASE;
			hash %= MOD;
			hash += (LL)(t[i] - 'a');
			hash %= MOD;

				//cout << (i - winL + 1) << " " << winL << " " << (LL)oh << " " << (LL)hash << endl;
			bool goodIs = bi.count(i + 1 - winL) && ei.count(i + 1 - sEnd.length());
			if (goodIs) {
			//	cout << (i - winL + 1) << " " << winL << " " << oh << " " << hash << endl;
				cnt[hash]++;
			}
		}

		ans += cnt.size();
		cnt.clear();
	}

	cout << ans;

	return 0;
}
