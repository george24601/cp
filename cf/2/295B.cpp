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

int const MaxSize = 510;
LL const INF = LL(1e18);

int n;
LL adj[MaxSize][MaxSize];

LL shortest[MaxSize][MaxSize];

int revX[MaxSize];

LL ans[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n;

	LPE(i, 1, n)
	{
		LPE(j, 1, n)
		{
			cin >> adj[i][j];
			shortest[i][j] = INF;
		}
	}

	LPE(i, 1, n)
		cin >> revX[n + 1 - i];

	LPE(from, 1, n)
	{
		LPE(to, 1, n)
			shortest[from][to] = adj[revX[from]][revX[to]];
	}

	LL total = 0;

	LPE(inter, 1, n)
	{
		LPE(from, 1, n)
		{
			LPE(to, 1, n)
			{
				LL before = shortest[from][to];

				LL after = min(before,
						shortest[from][inter]
								+ shortest[inter][to]);

				shortest[from][to] = after;

//				cout << inter << " " << from << " " << to << " " << before
//						<< " " << after << endl;

				if (from > inter || to > inter)
					continue;

				if (from == inter || to == inter)
					total += after;
				else
					total += after - before;

			}
		}

		ans[inter] = total;
	}

	for (int i = n; i >= 1; i--) {
		cout << ans[i];

		if (i == 1)
			cout << endl;
		else
			cout << " ";
	}

}

