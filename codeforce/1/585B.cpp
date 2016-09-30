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

int const MaxSize = 26;

/*
 each train at least 2 cells long, moves at 2 cell per second
 hero runs L to R at 1 cell per second

 canMove()

 possible(row, col){
 if(col == n)
 return true;

 if(!canMove(row, col+1))
 return false;

 foreach delta
 if(row + delta, col + 1) is valid && canMove(row + delta, col + 1, true)

 }

 total cost: n * 3 * k


 */

int n, k;

int sr, sc;

int ts[MaxSize];
int te[MaxSize];
int row[MaxSize];
int visited[3][210];

int delta[3] = { -1, 0, 1 };

bool canMove(int r, int c, bool train) {

	LP(t, 0, 26)
	{
		if (ts[t] == -1)
			continue;
		else if (row[t] != r)
			continue;

		assert(c >= 1);

		int curStart = ts[t] - 2 * (c - 1);
		int curEnd = te[t] - 2 * (c - 1);

		if (train) {
			curStart -= 2;
			curEnd -= 2;
		}

		if (curStart <= c && curEnd >= c)
			return false;
	}

	return true;
}

bool within(int r, int c) {
	return r >= 0 && r < 3 && c >= 0 && c < n;
}

int possible(int r, int c) {
	if (visited[r][c] != 0)
		return visited[r][c];

	int res = -1;

	if (c == n - 1) {
		res = 1;
	} else if (canMove(r, c + 1, false)) {

		LP(i, 0, 3)
		{
			if (within(r + delta[i], c + 1) && canMove(r+delta[i], c+1, false) && canMove(r+delta[i], c+1, true) &&
					(possible(r + delta[i], c + 1) > 0)) {
				res = 1;
				break;
			}
		}

	}

	return visited[r][c] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int t;
	cin >> t;

	LP(i, 0, t)
	{
		memset(ts, -1, sizeof(ts));

		LP(i, 0, 3)
			memset(visited[i], 0, sizeof(visited[i]));

		cin >> n >> k;

		LP(r, 0, 3)
		{
			string rs;
			cin >> rs;

			LP(col, 0, n)
			{
				if (rs[col] == 's') {
					sr = r;
					sc = col;
				} else if (rs[col] == '.') {

				} else {
					int idx = rs[col] - 'A';
					te[idx] = col;
					if (ts[idx] < 0)
						ts[idx] = col;
					row[idx] = r;
				}
			}
		}

		if (possible(sr, sc) > 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
