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

int k;

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);
	cin >> k;

	if (k % 2 == 0) {
		cout << "NO";
		return 0;
	}

	cout << "YES" << endl;

	if (k == 1) {
		cout << 2 << " " << 1 << endl;
		cout << 2 << " " << 1 << endl;
		return 0;
	}

	int n = k + 2;
	cout << 2 * n << " " << n * k << endl;

	cout << 1 << " " << n + 1 << endl;

	LPE(v, 2, k)
	{
		cout << 1 << " " << v << endl;
		cout << n + 1 << " " << n + v << endl;
	}

	int skipped = 0;
	LPE(v, 2, n)
	{
		LPE(next, v+ 1, n)
		{ if (next == v + 1 && v % 2 == 0 && skipped < (k - 1) / 2) {
				skipped++;
				continue;
			}

			cout << v << " " << next << endl;
			cout << n + v << " " << n + next << endl;
		}
	}

	return 0;
}
