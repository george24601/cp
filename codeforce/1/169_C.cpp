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

int n, q;
int const MaxSize = 200010;
int a[MaxSize];
int delta[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &q);

	memset(a, 0, sizeof(a));
	memset(delta, 0, sizeof(delta));

	LPE(i, 1, n){
		scanf("%d", &a[i]);
		a[i] = -a[i];
	}

	LP(i, 0, q)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		delta[l]++;
		delta[r + 1]--;
	}

	int curCount = 0;
	vector<int> ranks;

	LPE(i, 1, n)
	{
		curCount += delta[i];
		ranks.push_back(-curCount);
	}

	sort(ranks.begin(), ranks.begin() + n);
	sort(a + 1, a + 1 + n);

	LL ans = 0;

	LP(i, 0, n)
		ans += (LL) ranks[i] * (LL)a[i+1];

	cout << ans << endl;

	return 0;
}

