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
 only 5 cards,
 either a 3 + 2

 get all number, calc potential diff

 */

int const MaxSize = 30;
int n = 5;

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int sum = 0;
	int curMaxSub = 0;
	map<int, int> c;

	LP(i, 0, n)
	{
		int num;
		cin >> num;
		sum += num;

		if (c.count(num) == 0)
			c[num] = 0;

		c[num] += 1;

		int nc = c[num];

		if (nc >= 2) {
			int numDis = min(3, nc);

			curMaxSub = max(curMaxSub, num * numDis);
		}
	}

	cout << sum - curMaxSub << endl;

	return 0;
}
