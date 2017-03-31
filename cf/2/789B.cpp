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

#define INF 1e9

/*
 at each step they just play
 state[monste][true] currently monster at monster and true moves
 at each step, try all of them, look for the case the other will lose, or it will be inf

 when will that be infite game?
 state = 0; no visited yet
 1, first win
 2. second win
 3. inf

 consider the case with n = 1!!!

 */

int const MaxSize = 7000 + 10;
LL b, q, l, m;

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> b >> q >> l >> m;

	set<LL> bads;

	LP(i, 0, m)
	{
		int bad;
		cin >> bad;
		bads.insert(bad);
	}

	if(abs(b) > l)
	{
		cout << 0;
		return 0;
	}

	if (0 == b || 0 == q) {
		if (bads.count(0)) {
			if (bads.count(b))
				cout << 0;
			else
				cout << 1;
		} else {
			cout << "inf";
		}
	} else if (q == 1) {
		if (bads.count(b))
			cout << 0;
		else
			cout << "inf";
	} else if (q == -1) {
		if((bads.count(b) && bads.count(-b))){
			cout << 0;
		}else
			cout << "inf";
	} else {
		LL cur = b;
		int ans = 0;

		while (abs(cur) <= l) {
			//cout << cur << endl;
			if (!bads.count(cur))
				ans++;

			cur *= q;
		}

		cout << ans;
	}

	return 0;
}
