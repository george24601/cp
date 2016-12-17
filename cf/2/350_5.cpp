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
 so need to know
 1. prev[i]
 2. next[i]
 3. match[i]

 when an R
 p =next[p]

 when an L
 p = prev[p]

 when D
 mP = match[p]
 WLOG, assume p > mP
 next[prev[p]] = next[mP]
 prev[next[mP]] = prev[p];

 */

int const MaxSize = 500000;

string seq;
string op;
int match[MaxSize];
int pr[MaxSize];
int ne[MaxSize];

int n, m, p;

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-large.in", "r", stdin);
	//freopen("/Users/georgeli/B_large.out", "w", stdout);

	cin >> n >> m >> p;

	cin >> seq;
	cin >> op;

	p--;

	LP(i, 0, n)
	{
		pr[i] = i - 1;
		ne[i] = i + 1; //case tail??
	}

	ne[n - 1] = -1;

	stack<int> ms;
	LP(i, 0, n)
	{
		if ('(' == seq[i]) {
			ms.push(i);
		} else {
			int lB = ms.top();
			ms.pop();
			match[lB] = i;
			match[i] = lB;
		}
	}

	LP(i, 0, m)
	{
		if ('R' == op[i]) {
			p = ne[p];
		} else if ('L' == op[i]) {
			p = pr[p];
		} else {
			assert('D' == op[i]);

			int mI = match[p];
			int dB = min(mI, p);
			int dE = max(mI, p);

			if (pr[dB] >= 0)
				ne[pr[dB]] = ne[dE]; //TODO: -1 and n case!

			if (ne[dB] >= 0)
				pr[ne[dE]] = pr[dB];

			if (ne[dE] >= 0)
				p = ne[dE];
			else
				p = pr[dB];
		}
	}

	while (pr[p] >= 0)
		p = pr[p];

	while (true) {

		printf("%c", seq[p]);
		if (ne[p] < 0)
			break;
		else
			p = ne[p];
	}

	printf("\n");

	return 0;
}
