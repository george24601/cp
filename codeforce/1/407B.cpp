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

int const MaxSize = 1010;
int n, p[MaxSize], ans[MaxSize][MaxSize];

LL const MOD = 1000000007;

LL visit(int from, int to) {
	if (from == to)
		return 0;

	if (ans[from][to] >= 0)
		return ans[from][to];


	LL sum = visit(from, to - 1) + visit(p[to - 1], to - 1) + 2;

	sum %= MOD;

	//cout << from << " " << to << " " << sum << endl;

	return ans[from][to] = sum;

}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	LPE(i, 1, n)
	{
		scanf("%d", &p[i]);
		memset(ans[i], -1, sizeof(ans[i]));
	}

	cout << visit(1, n + 1) << endl;

	return 0;
}
