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
#define LP(i, a, b) for (LL i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (LL i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

LL const MOD = 1e9 + 7;
LL const MaxSize = 2000 + 5;
//LL const MOD = 998244353;

/*

https://atcoder.jp/contests/abc110/tasks/abc110_c
#C - String Transformation
 */

//NOTE WORKS ONLY WHEN MOD IS PRIME
//test case, either = 1 or all = 1
string S, T;
int m[26];
int cnt[26];

//NOTE WORKS ONLY WHEN MOD IS PRIME

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> S >> T;
	LP(i, 0, 26)
	{
		m[i] = -1;
		cnt[i] = 0;
	}

	LP(i, 0, S.size())
	{
		int si = S[i] - 'a';
		int ti = T[i] - 'a';

		int from = si;
		int to = ti;
		if (m[from] >= 0 && m[from] != to) {
			cout << "No";
			return 0;
		}
		m[from] = to;
	}

	LP(i, 0, 26)
	{
		if (m[i] >= 0 && cnt[m[i]]) {
			cout << "No";
			return 0;
		}
		cnt[m[i]] += 1;
	}

	cout << "Yes";
	return 0;
}
