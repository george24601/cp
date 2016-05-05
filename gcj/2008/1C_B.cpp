#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
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
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-9

int const GroupSize = 210;
int const MaxLen = 40;

char lit[MaxLen];
int len;
int N;
LL ways[MaxLen][GroupSize];

void process() {
	LL total = 0;

	LP(i, 0, len)
	{
		total = (total * 10 + (lit[i] - '0')) % GroupSize;

		ways[i][total]++; //just concate, no + or -

		//cout << total % GroupSize << endl;

		LP(m, 0, GroupSize)
		{
			LL sufN = 0;

			LP(endIndex, i + 1, len)
			{
				sufN = (sufN * 10 + (lit[endIndex] - '0')) % GroupSize;

				int add = (m + sufN) % GroupSize;
				ways[endIndex][add] += ways[i][m];

				int minus = (m - (sufN % GroupSize) + GroupSize) % GroupSize;
				ways[endIndex][minus] += ways[i][m];
			}
		}
	}
}

void reset() {
	LP(i, 0, MaxLen)
		memset(ways[i], 0, sizeof(ways[i]));
}

int main() {
	freopen("/Users/georgeli/Downloads/B-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/B_large_1.out", "w", stdout);

	scanf("%d", &N);

	LPE(cn, 1, N)
	{
		scanf("%s", lit);
		len = strlen(lit);

		reset();
		LL ans = 0;

		process();

		LP(remainder, 0, GroupSize)
		{
			if ((remainder % 2 == 0) || (remainder % 3 == 0) || (remainder % 5 == 0)
					|| (remainder % 7 == 0)) {
				ans += ways[len - 1][remainder];
			}
		}

		printf("Case #%d: %lld\n", cn, ans);
	}

	return 0;
}
