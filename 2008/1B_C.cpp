#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
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
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-9

/*

 unknown:
 value of card

 known:
 card at index

 condition:
 deck is perfect, meaning we can generate the layout in a brute force, deterministic way

 subproblem:
 given an index i, what the index of j, where there are k unoccupied between i and j

 idea: since we have only 100 entries, we just want to know, how many occupied between indices,
 the DS approaches allow "keep and skip" approach, here we will do "delete and iterate" approach

 In the first approach, we maintain the view where we keep the mark fields at each iteration
 the second apporach means we maintain the view where we keep all fields to be clear.
 This means at each step, we need to update all indices so that so we can do the translation from new view to old view via a series of steps

 for i 1 to K
 pos = next to remove

 for j in 0 to n
 if (q[j] == pos)
 we found it, output ans[j] = value
 else
 if q[j] > pos
 remove that


 */

int T, K, n;

int const Maxn = 100;
int qs[Maxn];
int ans[Maxn];

void process() {
	memset(ans, 0, sizeof(ans));

	int prev = 0;

	LPE(val, 1, K)
	{
		int curSize = K - val + 1;
		int next = (prev + val - 1) % curSize; //Notice the mod trick here
		prev = next;
		next++;

		LP(i, 0 , n)
		{
			if (ans[i])
				continue;

			if (qs[i] == next)
				ans[i] = val;
			else if (qs[i] > next) {
				qs[i]--;
			}
		}
	}
}

int main() {
	freopen("/Users/georgeli/Downloads/C-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/C_1.in", "r", stdin);
	freopen("/Users/georgeli/C_large.out", "w", stdout);

	cin >> T;

	LPE(cn, 1, T)
	{
		cin >> K >> n;

		LP(i, 0, n)
			cin >> qs[i];

		process();

		printf("Case #%d:", cn);

		LP(i, 0, n)
			printf(" %d", ans[i]);

		printf("\n");
	}

	return 0;
}
