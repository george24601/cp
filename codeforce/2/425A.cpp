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
#define INF 2000000000
#define Ep 1e-8

/*

 suppose only 1 level



 */

int const MaxSize = 210;
int n, k, a[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &k);

	LP(i, 0, n)
		scanf("%d", &a[i]);

	int best = -INF;

	LP(i, 0, n)
	{
		LP(j,i , n)
		{
			multiset<int> inside;
			multiset<int> outside;

			int sum = 0;

			LP(si, 0, n)
			{
				if (si >= i && si <= j) {
					inside.insert(a[si]);
					sum += a[si];
				} else
					outside.insert(-a[si]);
			}

			int segLen = j - i + 1;

			LP(si, 0, min(segLen, k))
			{
				if (inside.empty() || outside.empty())
					break;

				int inMin = *inside.begin();
				int outMax = -*outside.begin();

				if (inMin < outMax) {
					sum += outMax;
					sum -= inMin;

					inside.erase(inside.begin());
					outside.erase(outside.begin());
				}
			}

			best = max(best, sum);
		}
	}

	cout << best << endl;

	return 0;
}
