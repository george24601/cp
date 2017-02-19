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
//typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-7

//#define INF 2000000000
#define INF 1e18
/*

 */
int const MaxSize = 100000 + 1;

LL ts, tf, t, arrival[MaxSize];
int n;

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> ts >> tf >> t >> n;

	LP(i, 0, n)
		cin >> arrival[i];

	LL nextT = ts;
	LL shortWait = INF;
	LL bestT = INF;

	//try before someone
	for (int i = 0; i < n && nextT <= tf - t; i++) {
		LL tryTime = arrival[i] - 1;

		if (tryTime >= 0) {
			LL thisWait = nextT - tryTime;

			if (thisWait <= 0) {
				cout << nextT;
				return 0;
			}

			if (thisWait < shortWait) {
				shortWait = thisWait;
				bestT = tryTime;
			}
		}

		nextT = max(arrival[i], nextT) + t;
	}

	//try after every one
	if (nextT <= tf - t) //try tail
		cout << tf - t;
	else
		cout << bestT;
}
