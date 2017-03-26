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
int n, state[MaxSize][2], badVote[MaxSize][2], s[MaxSize][2], k[2];

void eW(int mp, int p);

void eL(int mp, int p) {
	if (state[mp][p])
		return;

	state[mp][p] = 2;
	int pP = !p;

	LP(i, 0, k[pP])
	{
		int pMP = (mp - 1 - s[i][pP] + n) % n + 1;

		if(pMP == 1)
			continue;

		//cout << "eL: " << mp << " " << p << " " << pMP << " " << pP << " " << endl;
		eW(pMP, pP);
	}
}

void eW(int mp, int p) {
	if (state[mp][p])
		return;

	state[mp][p] = 1;

	int pP = !p;

	LP(i, 0, k[pP])
	{
		int pMP = (mp - 1 - s[i][pP] + n) % n + 1;

		if(pMP == 1)
			continue;

		badVote[pMP][pP]++;
		if (badVote[pMP][pP] == k[pP]) {

		//	cout << "eW: " << mp << " " << p << " " << pMP << " " << pP << " " << endl;
			eL(pMP, pP);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n;

	LP(p, 0, 2)
	{
		cin >> k[p];

		LP(i, 0, k[p])
			cin >> s[i][p];
	}

	LP(p, 0, 2)
	{
		eL(1, p);
	}

	LP(p, 0, 2)
	{
		LP(i, 1, n)
		{
			if (i > 1)
				cout << " ";

			int res = state[i + 1][p];

			if (res == 1) {
				cout << "Win";
			} else if (res == 2)
				cout << "Lose";
			else {
				assert(res == 0);
				cout << "Loop";
			}

		}
		cout << endl;
	}

	return 0;
}
