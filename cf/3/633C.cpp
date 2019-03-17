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

int const MaxSize = 10000 + 5;
LL const MOD = 1e9 + 7;
LL const BASE = 256;

/*
 1. reverse the string
 2. lower the words in dictionary, and maintain lowerhash -> actual word map
 3. calulate the hash one by the rolling window, can break at the first chance, add the result to the answer list
 for each

 reverse the answer list and print

 */
int n, m, state[MaxSize];
string t;
map<int, map<LL, int> > dDict; //reduce collision chance
vector<int> ans;
vector<string> wl;

LL sHash(string s) {
	LL h = 0;
	LP(i, 0, s.size())
	{
		h = h * BASE;
		if (s[i] >= 'a' && s[i] <= 'z')
			h += (LL) s[i] - 'a'; //very similar idea to base number calculation
		else
			h += (LL) s[i] - 'A'; //very similar idea to base number calculation

		h %= MOD;
	}

	return h;
}

int finAns(int ci) {
	if (state[ci] >= 0)
		return state[ci];
	else if (ci == n)
		return 1;

	LL h = 0;
	LP(i, ci, n)
	{
		h = h * BASE;
		h += (LL) t[i] - 'a';
		h %= MOD;

		int segLen = i - ci + 1;

		if (dDict.count(segLen) && dDict[segLen].count(h) && finAns(i + 1)) {
			ans.push_back(dDict[segLen][h]);
			return state[ci] = 1;
		}
	}

	return state[ci] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n >> t >> m;

	LP(i, 0, m)
	{
		string s;
		cin >> s;
		wl.push_back(s);
		dDict[s.size()][sHash(s)] = i;
	}

	reverse(t.begin(), t.end());

	memset(state, -1, sizeof(state));
	finAns(0);
	LP(i, 0, ans.size())
	{
		cout << wl[ans[i]] << " ";
	}

	return 0;
}
