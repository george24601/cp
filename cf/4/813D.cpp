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
#define Ep 1e-13

#define INF 1e9
int const MaxSize = 5000 + 10;
int n, a[MaxSize], lastG1[MaxSize], lastL1[MaxSize], lastM[MaxSize];
int len[MaxSize][MaxSize];

void precalc() {
	memset(lastG1, -1, sizeof(lastG1));
	memset(lastL1, -1, sizeof(lastL1));
	memset(lastM, -1, sizeof(lastM));

	LP(i, 0, n)
		memset(len[i], -1, sizeof(len[i]));

	map<int, int> nToI;
	int lastMOD[7];

	memset(lastMOD, -1, sizeof(lastMOD));

	nToI[a[0]] = 0;
	lastMOD[a[0] % 7] = 0;

	LP(i, 1, n)
	{
		if (nToI.count(a[i] - 1)) {
			lastL1[i] = nToI[a[i] - 1];
		}

		if (nToI.count(a[i] + 1)) {
			lastG1[i] = nToI[a[i] + 1];
		}

		if (lastMOD[a[i] % 7] >= 0) {
			lastM[i] = lastMOD[a[i] % 7];
		}

		nToI[a[i]] = i;
		lastMOD[a[i] % 7] = i;
	}

}

int maxLen(int x, int y) {
	if (x == y)
		return 0;
	else if (x < y) {
		return maxLen(y, x);
	}

	if (len[x][y] >= 0)
		return len[x][y];

	int ans = 2;

	if (lastG1[x] >= 0)
		ans = max(ans, maxLen(lastG1[x], y) + 1);

	if (lastL1[x] >= 0)
		ans = max(ans, maxLen(lastL1[x], y) + 1);

	if (lastM[x] >= 0)
		ans = max(ans, maxLen(lastM[x], y) + 1);

	cout << x << " " << y << " " << ans << endl;

	return len[x][y] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
	{
		cin >> a[i];
	}

	precalc();

	len[1][0] = 2;
	len[0][1] = 2;

	int ans = 0;

	LP(i, 0, n)
	{
		LP(j, 0, i)
			ans = max(ans, maxLen(i, j));
	}

	cout << ans;
	return 0;
}
