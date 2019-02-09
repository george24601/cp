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
 for each two segments
 1. if the two are parallel, same length
 otherwise, the two must share exactly 1 point,
 the two must be orthogonal

 //CATCHES:
  same lines for BOTH para and orth case

 */

int const MaxSize = 5 + 5;
long x1[MaxSize], y11[MaxSize], x2[MaxSize], y2[MaxSize], cl[MaxSize];

bool parallel(int i, int j) {
	if (x1[i] == x2[i])
		return x1[j] == x2[j];

	if (y11[i] == y2[i])
		return y11[j] == y2[j];

	return (x1[i] - x2[i]) * (y11[j] - y2[j])
			== (y11[i] - y2[i]) * (x1[j] - x2[j]);
}

bool orth(int i, int j) {
	if (x1[i] == x2[i])
		return y11[j] == y2[j];

	if (y11[i] == y2[i])
		return x1[j] == x2[j];

	return (x1[i] - x2[i]) * (x1[j] - x2[j])
			== (y11[i] - y2[i]) * (y11[j] - y2[j]);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	LP(i, 0, 4)
	{
		cin >> x1[i] >> y11[i] >> x2[i] >> y2[i];
		cl[i] = (x1[i] - x2[i]) * (x1[i] - x2[i])
				+ (y11[i] - y2[i]) * (y11[i] - y2[i]);
	}

	int goodParallel = 0;
	LP(i, 0, 4)
	{
		LP(j, 0, 4)
		{
			if (i == j)
				continue;

			int samePoint = 0;
			if (x1[i] == x1[j] && y11[i] == y11[j])
				samePoint++;
			if (x1[i] == x2[j] && y11[i] == y2[j])
				samePoint++;
			if (x2[i] == x1[j] && y2[i] == y11[j])
				samePoint++;
			if (x2[i] == x2[j] && y2[i] == y2[j])
				samePoint++;

			if (parallel(i, j)) {
				if (cl[i] == cl[j] && !samePoint) {
					goodParallel++;
				} else {
					cout << "NO";
					return 0;
				}
			} else {
				if (samePoint != 1 || !orth(i, j)) {
					cout << "NO";
					return 0;
				}
			}
		}
	}

	if (goodParallel == 4) {
		cout << "YES";
	} else {
		cout << "NO";
	}

	return 0;
}
