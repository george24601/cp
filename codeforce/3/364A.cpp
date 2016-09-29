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
#define Ep 1e-8

#define INF 2000000000

LL const LINF = LL(1e18);
/*
 when seeing an int, hash to another int, add to population

 on input

 */

int const MaxSize = 4010;
int ps[MaxSize];
string s;
int a, n;
map<int, int> vc;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> a >> s;

	n = s.length();
	ps[0] = 0;

	LPE(i, 1, n)
		ps[i] = ps[i - 1] + (s[i - 1] - '0');

	LPE(start, 1, n)
	{
		LPE(end, start, n)
		{
			int diff = ps[end] - ps[start - 1];

			vc[diff]++;
		}
	}

	LL ans = 0;

	int srt = sqrt(a);
	if (a) {

		LPE(factor, 1, srt)
		{
			if (a % factor)
				continue;

			ans += (LL) vc[factor] * (LL) vc[a / factor];
		}

	} else {
		LL allPossibles = n * (n + 1) / 2;
		ans = (LL) vc[0] * allPossibles;
	}

	ans *= 2;

	if (srt * srt == a)
		ans -= (LL) vc[srt] * (LL) vc[srt];

	cout << ans << endl;

	return 0;
}

