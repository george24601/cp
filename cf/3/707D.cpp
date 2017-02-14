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

#define INF 2000000000
//#define INF 1e18
/*

 */

int const MaxSize = 1e5 + 1;
int n, m, q;
int ans[MaxSize];

bool bookcase[1001][1001];
int ops[MaxSize], is[MaxSize], js[MaxSize];

SAL g;
int curNum;

void flip(int i) {
	LPE(col, 1, m)
	{
		if (bookcase[i][col])
			curNum--;
		else
			curNum++;

		bookcase[i][col] = !bookcase[i][col];
	}
}

void dfs(int step) {

	int i = is[step];
	int j = js[step];

	bool needRevert = false;

	if (ops[step] == 1 && !bookcase[i][j]) {
		bookcase[i][j] = true;
		curNum++;
		needRevert = true;
	} else if (ops[step] == 2 && bookcase[i][j]) {
		bookcase[i][j] = false;
		curNum--;
		needRevert = true;
	} else if (ops[step] == 3) {
		flip(i);
		needRevert = true;
	}

	ans[step] = curNum;

	LP(i, 0, g[step].size())
	{
		int next = g[step][i];

		//cout << step << " " << next << " Before: " << curNum << endl;
		dfs(next);
		//cout << step << " " << next << " After: " << curNum << endl;
	}

	if (!needRevert)
		return;

	if (ops[step] == 1) {
		bookcase[i][j] = false;
		curNum--;
	} else if (ops[step] == 2) {
		bookcase[i][j] = true;
		curNum++;
	} else if (ops[step] == 3) {
		flip(i);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> m >> q;
	int curStep = 0;

	g = SAL(q + 1);

	LPE(step, 1, q)
	{
		int op = 0, i = 0, j = 0, k = 0;
		cin >> op;

		if (1 == op) {
			cin >> i >> j;

		} else if (2 == op) {
			cin >> i >> j;

		} else if (3 == op) {
			cin >> i;
		} else {
			cin >> k;
			curStep = k;
		}

		ops[step] = op;
		is[step] = i;
		js[step] = j;

		g[curStep].push_back(step);

		curStep = step;
	}

	dfs(0);

	LPE(step, 1, q)
		cout << ans[step] << endl;
}
