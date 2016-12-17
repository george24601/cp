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
 He does not visit

 start = smallest of biggest index to appear
 end = biggest of smallest index to appear
 */

int n, m, t;

int const MaxSize = 70;

LL chooseRes[MaxSize][MaxSize];

LL choose(int top, int bottom) {

	if (top < bottom)
		return 0;
	else if (top == bottom || 0 == bottom)
		return 1;

	if (chooseRes[top][bottom] >= 0)
		return chooseRes[top][bottom];

	return chooseRes[top][bottom] = choose(top - 1, bottom - 1)
			+ choose(top - 1, bottom);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n >> m >> t;

	LPE(i, 0, n+m)
	{
		LPE(j, 0, n+m)
			chooseRes[i][j] = -1;
	}

	LL total = choose(n + m, t);
//	cout << total << endl;

	total -= choose(n, t);
//	cout << total << endl;

	LP(nb, 0, 4)
		total -= choose(n, nb) * choose(m, t - nb);

	cout << total << endl;

	return 0;
}

