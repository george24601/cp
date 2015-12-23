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

 E(collected + newCollect) = Pr(collected+newCollect-1, 1) * (E(collected + newCollect -1) + 1)
 */

int T, N, C;
int const MaxSize = 40;

double pNM[MaxSize][MaxSize + 1];

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
	assert(top >= bottom);

	if (chooseN[top][bottom])
		return chooseN[top][bottom];

	LL calced = choose(top - 1, bottom - 1) + choose(top - 1, bottom);

	chooseN[top][bottom] = calced;
	return chooseN[top][bottom];
}

void calcPnm() {
	initChoose();

	LP(i, 0, C)
		memset(pNM, 0.0, sizeof(pNM));

	pNM[0][N] = 1;

	int chooseCN =  choose(C, N);

	assert(choose(2,1) == 2);
	assert(choose(2,2) == 1);

	assert(choose(2,0) == 1);

	LP(collected, N, C)
	{
		int maxPossibleNewCollect = min(C - collected, N);

		LPE(newCollect, 1, maxPossibleNewCollect)
		{
			int newChosen = choose(C - collected, newCollect);
			int oldChosen = choose(collected, N - newCollect);

			pNM[collected][newCollect] = newChosen * oldChosen/(chooseCN * 1.0);
///			printf("%d %d %lf\n", collected, newCollect, pNM[collected][newCollect]);
///			printf("%d %d %d\n", newChosen, oldChosen, chooseCN);
		}
	}
}

double calcEx(int collected) {
	assert(collected >= 0 && collected <= C);

	if (collected == 0)
		return 0.0;

	if (collected == N)
		return 1.0;

	if (eN[collected])
		return eN[collected];

	int maxToCollectThisRound = min(collected, N);

	double curEx =0.0;

	LPE(thisRound, 1, maxToCollectThisRound){ //since we answer state on collected something already, we skip 0 case
		int lastRound = collected - thisRound;

		if (lastRound >= N){
			//printf("last, this: %d %d\n", lastRound, thisRound);

			curEx += pNM[lastRound][thisRound] * calcEx(lastRound);
		}
	}

	curEx++;//open this pack

	eN[collected] = curEx;
	return eN[collected];
}

int main() {
	//freopen("/Users/georgeli/Downloads/C-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/C_1.in", "r", stdin);
	//freopen("/Users/georgeli/C_large.out", "w", stdout);

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%d %d", &C, &N);

		memset(eN, 0.0, sizeof(eN));

		printf("calcPNM\n");
		calcPnm();

		printf("calcEx\n");

		double ans = calcEx(C);

		printf("Case #%d: %lf\n", cn, ans);
	}

	return 0;
}
