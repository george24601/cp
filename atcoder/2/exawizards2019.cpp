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

LL const MaxSize = 1e5 + 5;
LL const MOD = 1e9 + 7;
LL const BASE = 256;

/*

option 1, pr( good) + 1 - pr(good)

 */

LL N, X;
vector<LL> s;
LL ans[MaxSize][205];
int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> N >> X;
	LP(i,0, N)
	{
		int num;
		cin >> num;
		s.push_back(num);
	}

	sort(s.begin(), s.end());

	LPE(v, 0, 1e5)
	{
		ans[v][0] = v % s[0];
	}

	LP(i, 1, N)
	{
		LPE(v, 0, 1e5)
		{
			ans[v][i] =  ans[v % s[i]][i - 1];
			ans[v][i] += i * ans[v][i - 1];
			ans[v][i] %= MOD;
		}
	}

	cout << ans[X][N - 1] << endl;

	return 0;
}

