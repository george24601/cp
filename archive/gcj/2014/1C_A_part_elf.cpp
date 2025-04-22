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
 */

int gen(LL P, LL Q){
	if (Q % 2)
		return -1;

	if (Q == 2){
		assert(P == 1);
		return 1;
	}

	if (P * 2 >= Q){
		int theOtherSide = gen (P - Q/2, Q);
		return theOtherSide < 0? -1 : 1;
	}
	else{
		int prev = gen(P, Q/2);
		return prev < 0 ? -1 : 1 + prev;
	}
}

LL gcd (LL P, LL Q){
	if (Q % P == 0)
		return P;

	return gcd(Q%P, P);
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/A-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/A_large.out", "w", stdout);

	int T;

	LL P, Q;

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%lld/%lld", &P, &Q);

		LL cf = gcd(P, Q);

		P /= cf;
		Q /= cf;

		int ans = gen(P, Q);


		if (ans < 0)
			printf("Case #%d: impossible\n", cn);
		else
			printf("Case #%d: %d\n", cn, ans);
	}

	return 0;
}
