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
#define Ep 1e-8

#define INF 2000000000
#define LSB(i) ((i) & -(i))

int fenSum(int *a, int i) {
	int sum = 0.0;
	i++;
	while (i > 0) {
		sum += a[i - 1];
		i -= LSB(i);
	}
	return sum;
}

void fenAdd(int *a, int size, int delta, int i) {
	i++;
	size++;
	while (i < size) {
		a[i - 1] += delta;
		i += LSB(i);
	}
}

int fenGet(int *a, int i) {
	return fenSum(a, i) - fenSum(a, i - 1);
}

void fenSet(int *a, int size, int value, int i) {
	fenAdd(a, size, value - fenGet(a, i), i);
}


int const MaxSize = 1000010;
int a[MaxSize];

int rToL[MaxSize];
map<int, int> current;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int n;
	cin >> n;
	memset(rToL, 0, sizeof(rToL));

	LP(i, 0, n)
		cin >> a[i];

	map<int, int> rToLCur;
	for (int i = n - 1; i >= 0; i--) {
		int newFreq = ++rToLCur[a[i]];
		fenAdd(rToL, n, +1, newFreq);
	}

	LL ans = 0;

	LP(i, 0, n)
	{
		int remainingFreq = rToLCur[a[i]]--;
		fenAdd(rToL, n, -1, remainingFreq);

		int curFreq = ++current[a[i]];

		int delta = fenSum(rToL, curFreq - 1);

		ans += delta;
	}

	cout << ans << endl;

	return 0;
}
