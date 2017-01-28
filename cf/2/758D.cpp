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
#define Ep 1e-7

#define INF 2000000000
//#define INF 1e18
/*
 since we want min decimal number, each lower digit must take as many spaces as possible
 */

LL n;
string k;

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> k;

	int len = k.length();

	LL ans = 0;

	LL power = 1;
	int i = len - 1;

	while (i >= 0) {
		LL best = 0;
		LL dShift = 1;
		int tempI = i;

		while (tempI >= 0 && (i - tempI + 1) <= 9) {
			LL sd = k[tempI] - '0';

			if (sd) {
				LL curTry = best + (LL) sd * dShift;

				if (curTry < n) {
					//cout << i << " " << best << " " << sd << " " << dShift << endl;

					best = curTry;
					i = tempI - 1;
				} else {
					break;
				}

			}

			dShift *= (LL) 10;
			tempI--;
		}

		ans += (LL) best * power;
		power *= n;

		if (best == 0)
			i--;
	}

	cout << ans << endl;

	return 0;
}

