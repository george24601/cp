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
 Total set C, pack size N
 Having collected n cards, what is the prob getting m new card out of the next pack?

 Pr(collected, newCollect) =  (C-collected choose newCollect) * (collected choose N-newCollect)  /(C choose N)

 E(collected + newCollect) = 1 +
 Pr(collected + newCollect, 0) * E(collected + newCollect) +
 Pr(collected+newCollect-1, 1) * (E(collected + newCollect -1) +
 .....
 */

int T, N, C;
int const MaxSize = 40;

double eN[MaxSize + 1];

LL chooseN[MaxSize + 1][MaxSize];

void initChoose() {
	LPE(i, 0, MaxSize)
	{
		memset(chooseN[i], 0, sizeof(chooseN[i]));
		chooseN[i][0] = 1;
		chooseN[i][i] = 1;
	}
}

LL choose(int top, int bottom) {

	if (top < 0 || bottom < 0 || bottom > top)
		return 0;

	assert(top >= bottom);

	if (chooseN[top][bottom])
		return chooseN[top][bottom];

	return chooseN[top][bottom] = choose(top - 1, bottom - 1)
			+ choose(top - 1, bottom);
}

//having collected cards, what is the prob to get newFromPack from a new pack
//hypergeometric distribution
double Pr(int collected, int newFromPack){
		return (double) choose(C - collected, newFromPack) * choose(collected, N - newFromPack) / (double) choose(C, N);
}

void calcEx() {
	eN[0] = 0;

	for (int collected = C -1; collected >= 0; collected--){
		int remainNew = C - collected;

		double total = 1; //open 1 new pack

		int maxPossible = min(N, remainNew);

		LPE(newFromPack, 1, maxPossible){
			total += Pr(collected, newFromPack) * eN[remainNew - newFromPack];
		}

		double prob = 1 - Pr(collected, 0); //0 new card collected from the pack
		eN[remainNew] = total / prob;
	}
}

int main() {
	freopen("/Users/georgeli/Downloads/C-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/C_1.in", "r", stdin);
	freopen("/Users/georgeli/C_large.out", "w", stdout);

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%d %d", &C, &N);

		memset(eN, 0.0, sizeof(eN));
		initChoose();

		calcEx();

		printf("Case #%d: %lf\n", cn, eN[C]);
	}

	return 0;
}
