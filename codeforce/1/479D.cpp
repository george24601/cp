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
int n, l, x, y, a[MaxSize];
set<LL> marks;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d %d %d", &n, &l, &x, &y);

	LP(i, 0, n)
	{
		scanf("%d", &a[i]);
		marks.insert(a[i]);
	}

	bool xGood = false;
	bool yGood = false;

	LP(i, 0, n)
	{
		LL mark = a[i];
		xGood = xGood || marks.count(mark - x) || marks.count(mark + x);
		yGood = yGood || marks.count(mark - y) || marks.count(mark + y);
	}

	if (xGood && yGood) {
		printf("0\n");
		return 0;
	}

	if (xGood) {
		printf("1\n%d\n", y);
		return 0;
	}

	if (yGood) {
		printf("1\n%d\n", x);
		return 0;
	}

	LP(i, 0, n)
	{
		LL lessMark = a[i] - x;

		if (lessMark >= 0
				&& (marks.count(lessMark - y) || marks.count(lessMark + y))) {
			cout << "1" << endl;
			cout << lessMark << endl;
			return 0;
		}

		LL moreMark = a[i] + x;

		if (moreMark <= l
				&& (marks.count(moreMark - y) || marks.count(moreMark + y))) {

			cout << "1" << endl;
			cout << moreMark << endl;
			return 0;
		}
	}

	printf("2\n%d %d\n", x, y);

	return 0;
}
