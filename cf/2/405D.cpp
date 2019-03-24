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

LL const MaxSize = 1e6 + 5;
LL const MOD = 1e9 + 7;
LL const BASE = 256;

/*
 find matching pair, there
 if both exists, find matching pair, if does not exist, add it to the new set
 */

int a[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int n;
	scanf("%d", &n);
	memset(a, 0, sizeof(a));

	int s = 1e6;

	LP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		a[x] = 1;
	}

	int lastMi = 0;
	int cnt = 0;

	LPE(i, 1, s)
	{
		if (a[i] != 1)
			continue;

		//cout << i << " ";

		if (a[s - i + 1]) {
			if (i <= s / 2) {

				do {
					lastMi++;
				} while (a[lastMi] || a[s - lastMi + 1]);

				a[lastMi] = 2;
				a[s - lastMi + 1] = 2;
				cnt += 2;
			}
		} else {
			a[s - i + 1] = 2;
			cnt++;
			//cout << i << " " << s - i + 1 << endl;
		}
	}

	printf("%d\n", cnt);

	LPE(i, 1, s)
	{
		if (a[i] == 2)
			printf("%d ", i);
	}

	return 0;
}
