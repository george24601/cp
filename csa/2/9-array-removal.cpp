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
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

/*
 cycle len =
 if (d >=k) = d, power =
 if( d < k) = d * ((k/d) + 1)
 */

int const MaxSize = 1e5 + 10;
int parent[MaxSize];
LL sum[MaxSize];

int Find(int a) {
	//assumption: parent[a] is set a itself on init
	if (parent[a] != a) {
		int pa = Find(parent[a]);
		parent[a] = pa;
	}

	return parent[a];
}

void Union(int a, int b) {

	int aP = Find(a);
	int bP = Find(b);

	if (aP == bP)
		return;

	LL newSum = sum[aP] + sum[bP];
	//cout << "newSum:" << aP << " " << bP << " " << newSum << endl;
	parent[max(aP, bP)] = min(aP, bP);
	//NOTE: spent time debugging this
	sum[min(aP, bP)] = newSum;
}

LL N, order[MaxSize];
//NOTE: forgot to set ans LL
LL a[MaxSize], ans[MaxSize];

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> N;
	LP(i, 0, N)
	{
		cin >> a[i];
		parent[i] = i;
	}

	LP(i, 0, N)
	{
		cin >> order[i];
		order[i]--;
	}

	memset(sum, -1, sizeof(sum));

	LL curMax = 0;

	for (int i = N - 1; i >= 0; i--) {
		int ri = order[i];
		sum[ri] = a[ri];

		if (ri > 0 && sum[ri - 1] >= 0) {
			Union(ri, ri - 1);
		}

		if (ri < N && sum[ri + 1] >= 0) {
			Union(ri, ri + 1);
		}

		int cp = Find(ri);

		//	cout << ri << " " << cp << " " << sum[cp] << endl;

		curMax = max(curMax, sum[cp]);
		ans[i] = curMax;
	}

	LP(i, 0, N)
		cout << ans[i] << endl;

	return 0;
}

