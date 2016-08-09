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

int const MaxSize = 200010;

int n, k;
string l, r;

int t[MaxSize];

queue<int> toExpand;

bool canSit(int id) {
	if (id % 2)
		return r[(id >> 1) - 1] == '-';
	else
		return l[(id >> 1) - 1] == '-';
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n >> k;
	cin >> l >> r;

	LP(i, 0, MaxSize)
		t[i] = INF;

	//10
	t[2] = 0;
	toExpand.push(2);

	bool canEscape = false;

	while (toExpand.size()) {
		int curID = toExpand.front();
		toExpand.pop();

		int curTime = t[curID];
		int nextTime = curTime + 1;

		int curHeight = curID >> 1;

		//cout << curID << endl;

		if (curHeight == n) {
			canEscape = true; //just go 1 level up
			break;
		} else {
			//jump one up
			int upID = curID + 2;

			if (canSit(upID) && t[upID] == INF) {
				t[upID] = nextTime;
				toExpand.push(upID);
			}
		}

		if (curHeight > 1) {
			int downID = curID - 2;

			if (canSit(downID) && t[downID] == INF
					&& nextTime < (curHeight - 1)) {
				t[downID] = nextTime;
				toExpand.push(downID);
			}
		}

		if (curHeight > n - k) {
			canEscape = true;
			break;
		} else {
			int upID = curID + 2 * k;

			if (upID % 2)
				upID--;
			else
				upID++;

			if (canSit(upID) && t[upID] == INF) {
				t[upID] = nextTime;
				toExpand.push(upID);
			}
		}
	}

	if (canEscape)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}

