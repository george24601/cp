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
#define Ep 1e-13

#define INF 1e9
int const MaxSize = 1010;
int n, m;
set<int> badRows;
set<int> badCols;
bool cells[MaxSize][MaxSize];
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> m;

	LP(i, 0, m)
	{
		int r, c;
		cin >> r >> c;
		badRows.insert(r);
		badCols.insert(c);
		cells[r][c] = true;
	}

	LPE(i, 2, n/2)
	{
		if (!cells[i][1] && !badRows.count(i)) {
			//	cout << i << " " << 1 << endl;
			ans++;
		}

		if (!cells[n][i] && !badCols.count(i)) {

			//	cout << n << " " << i << endl;
			ans++;
		}

		if (!cells[n - i + 1][n] && !badRows.count(n - i + 1)) {

			//	cout << n - i + 1 << " " << n << endl;
			ans++;
		}

		if (!cells[1][n - i + 1] && !badCols.count(n - i + 1)) {

			//	cout << 1 << " " << n - i + 1 << endl;
			ans++;
		}
	}

	if (n % 2) {
		int i = n / 2 + 1;

		bool canAdd = false;

		if (!cells[i][1] && !badCols.count(i)) {
			canAdd = true;
		}

		if (!cells[n][i] && !badRows.count(i)) {

			canAdd = true;
		}

		if (!cells[n - i + 1][n] && !badCols.count(n - i + 1)) {

			canAdd = true;
		}

		if (!cells[1][n - i + 1] && !badRows.count(n - i + 1)) {
			canAdd = true;
		}

		if (canAdd)
			ans++;

	}

	cout << ans << endl;

	return 0;
}
