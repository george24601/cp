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
#define INF 1e9
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;

int const MaxSize = 5000 + 10;

/*

 */

int n;
string s;
int fdi[MaxSize][MaxSize];
LL ways[MaxSize][MaxSize]; //total # of ways ending at index tl - 1, with last length <= len

void calcDiff() {
	for (int a = n - 1; a >= 0; a--) {
		for (int b = n - 1; b > a; b--) {
			if (s[a] == s[b]) {
				fdi[a][b] = fdi[a + 1][b + 1] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("/Users/george/A_1.in", "r", stdin);
	cin >> n >> s;

	LL const MOD = 1e9 + 7;

	calcDiff();

	ways[0][0] = 1;

	//cout << "START" << endl;

	LPE(tl, 1, n)
	{
		LP(ll, 1, tl)
		{
			int curStartI = tl - ll;

			if (s[curStartI] == '0') {
				ways[tl][ll] = ways[tl][ll - 1];
				continue;
			}

			LL shorter = ways[curStartI][ll - 1];

			LL same = 0;

			int lastStartI = curStartI - ll;
			if (lastStartI >= 0) {
				int diffI = fdi[lastStartI][curStartI];

				if (diffI < ll
						&& s[curStartI + diffI] > s[lastStartI + diffI]) {
					same = ways[tl - ll][ll] - ways[tl - ll][ll - 1];
				}
			}

			ways[tl][ll] = shorter + same + ways[tl][ll - 1];
			ways[tl][ll] %= MOD;

//			cout << tl << " " << ll << " " << ways[tl][ll] << endl;
		}

		ways[tl][tl] = 1 + ways[tl][tl - 1];
		ways[tl][tl] %= MOD;
		//cout << tl << " " << tl << " " << ways[tl][tl] << endl;

		LPE(ll, tl + 1, n)
		{
			ways[tl][ll] = ways[tl][ll - 1];
		}
	}

	cout << ways[n][n] << endl;
}
