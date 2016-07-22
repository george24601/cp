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
 */

int n, k;
int const MaxSize = 1000000;

int a[MaxSize];
int beforeMatch[MaxSize];
int afterMatch[MaxSize];
map<LL, int> beforeCount;
map<LL, int> afterCount;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &k);

	LP(i, 0, n)
		scanf("%d", &a[i]);

	memset(beforeMatch, 0, sizeof(beforeMatch));
	memset(afterMatch, 0, sizeof(afterMatch));

	beforeCount[a[0]]++;

	LP(i, 1, n - 1)
	{
		int curN = a[i];

		if (curN % k == 0) {

			beforeMatch[i] = beforeCount[curN / k];

		//	cout << i << " " << beforeMatch[i] << " " << endl;
		}

		beforeCount[curN]++;
	}

	afterCount[a[n - 1]]++;

	for (int i = n - 2; i >= 1; i--) {
		int curN = a[i];

		afterMatch[i] = afterCount[(LL) curN * (LL) k];

		afterCount[curN]++;
	}

	LL res = 0;

	LP(i, 1, n - 1)
		res += (LL) beforeMatch[i] * (LL) afterMatch[i];

	cout << res << endl;

	return 0;
}

