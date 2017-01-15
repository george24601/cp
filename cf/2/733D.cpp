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
#define Ep 1e-7

//#define INF 2000000000
#define INF 1e18
/*
 alternate solution:

 seperate the 1 compoent and 2 comp case,

 when we get a new element, update the 1 element case

 try updating the 2 elements case


 */

int const MaxSize = 300;
int n;

map<PII, PII> best;
int best1, best1i, best2, best2i1, best2i2;

void updateAns(PII bottom, PII state) {
	if (!best.count(bottom))
		return;

	PII curState = best[bottom];

	int tryHeight = curState.first + state.first;

	int tryAns = min(bottom.first, tryHeight);

	if (tryAns > best2) {
		best2 = tryAns;

		best2i1 = curState.second;
		best2i2 = state.second;
	}
}

void updateState(PII bottom, PII state) {
	if (best.count(bottom)) {
		PII curState = best[bottom];

		if (curState.first < state.first)
			best[bottom] = state;
	} else
		best[bottom] = state;
}

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	int lens[3];

	LPE(i, 1, n)
	{
		cin >> lens[0] >> lens[1] >> lens[2];
		sort(lens, lens + 3);

		if (best1 < lens[0]) {
			best1 = lens[0];
			best1i = i;
		}

		PII b1 = PII(lens[0], lens[1]);
		PII s1 = PII(lens[2], i);
		updateAns(b1, s1);

		PII b2 = PII(lens[0], lens[2]);
		PII s2 = PII(lens[1], i);
		updateAns(b2, s2);

		PII b3 = PII(lens[1], lens[2]);
		PII s3 = PII(lens[0], i);
		updateAns(b3, s3);

		updateState(b1, s1);
		updateState(b2, s2);
		updateState(b3, s3);
	}

	if (best1 > best2)
		cout << 1 << endl << best1i << endl;
	else
		cout << 2 << endl << best2i1 << " " << best2i2 << endl;
}
