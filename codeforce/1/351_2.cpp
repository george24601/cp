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
#define Ep 1e-9

/*
 for all pairs, all higher go to the div1, leave div 2 alone
=> keep lowest of div 1 sims as guard, all higher than that goes to div 1
=> # of ways =  (lowest of div1 sims - highest of div2 sims), 0
=> keep track of all simed ones as they are fixed

so read all
	let min update highest of div2
	let max update lowest of div 1


 */

int n, m;

int main() {
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-small-attempt1.in", "r", stdin);
	//freopen("/Users/georgeli/B_1.out", "w", stdout);

	scanf("%d %d", &n, &m);

	int div2Max = 0;
	int div1Min = n + 1; //?

	//case m = 0?
	LP(i, 0, m){
		int u, v;
		scanf("%d %d", &u, &v);

		int g2 = min (u, v);
		int g1 = max (u, v);

		//printf("%d %d\n", g2, g1);

		div2Max = max(div2Max, g2);
		div1Min = min(div1Min, g1);
	}

	int ans = n - 1;

	if(m > 0)
		ans = max(-div2Max + div1Min, 0);

	printf("%d\n", ans);

	return 0;
}
