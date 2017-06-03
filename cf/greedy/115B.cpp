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
int const MaxSize = 150 + 1;
int n, m;
string g[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> m;
	LP(i, 0, n)
		cin >> g[i];

	int curPos = 0;
	bool right = true;
	int ans = 0;
	int lastRow = n - 1;

	while (lastRow >= 0) {
		bool has = false;

		LP(i, 0, m)
		{
			if (g[lastRow][i] == 'W') {
				has = true;
				break;
			}
		}

		if (has)
			break;
		else
			lastRow--;
	}

	if (lastRow < 0) {
		cout << 0;
		return 0;
	}

	LPE(i, 0, lastRow)
	{
		int nextPos = curPos;
		if (right) {
			LP(j, 0, m)
			{
				if (g[i][j] == 'W' || (i < lastRow && g[i + 1][j] == 'W'))
					nextPos = j;
			}
		} else {
			for (int j = m - 1; j >= 0; j--) {
				if (g[i][j] == 'W' || (i < lastRow && g[i + 1][j] == 'W'))
					nextPos = j;
			}
		}

		ans += abs(nextPos - curPos);
		right = !right;
		curPos = nextPos;
	}

	ans += lastRow;

	cout << ans << endl;

	return 0;
}
