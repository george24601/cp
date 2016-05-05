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
 To capture state
 length, start of the known seg, length of the knownseg

 cost(length, segStart, segLength) {

for i for 1 to segStart -1
	noHit = 1 + cost(length - i, segStart - i, segLengh)
	hit = segStart - i + (length, i, segLength + segStart  - i)
	pick max(noHit, hit)

for i from segStart + length  to length
	noHit = 1 + cost(i -1, segStart, segLength)
	hit = i - segStart - segLength + (length, segStart, i)
	pick max(noHit,hit)
 }

 pick min i, s.t. it is min

 */

int T, R, C, W;
int MaxC = 20;

int noHit [21][21];
int hitCost [21][21][21];

int cost(int length, int segStart, int segLen){

	if (length == segStart + segLen - 1)
		return 0; //we are done

	assert(length > segStart + segLen - 1);

	if (hitCost[length][segStart][segLen] >= 0)
		return hitCost[length][segStart][segLen];

	int curMin = INF;

	LP(i, 1, segStart){
		int noHit = 1 + cost(length - i, segStart - i, segLen);

		int hit = segStart - i + cost(length, i, segLen + segStart - i);

		curMin = min(curMin, max(noHit, hit));
	}

	LPE(i, segStart + segLen, length){
		int noHit = 1 + cost(i-1, segStart, segLen);

		int hit = i - segStart - segLen + 1 + cost(length, segStart, i - segStart + 1);

		curMin = min(curMin, max(noHit, hit));
	}

	return hitCost[length][segStart][segLen] = curMin;
}

//know w exists
int no_hit(int c, int w){
	assert(c >=w);

	if (c == w)
		return c; //all filled

	if (noHit[c][w] >= 0)
		return noHit[c][w];

	int curMin = INF;

	LPE(i, 1, c){
		int notHitScore = 1;

		int biggerSeg = max(i-1, c - i);
		if (biggerSeg >= w) //otherwise, no hit can not happen!
			notHitScore += no_hit(biggerSeg, w);

		int smallerSeg = min(i-1, c - i);
		if (smallerSeg >= w) //otherwise, no hit can not happen!
			notHitScore += no_hit(smallerSeg, w);

		int hitScore = 1 + cost(c, i, 1);

		//printf("%d %d %d %d %d\n", c, w, i, notHitScore, hitScore);

		curMin = min(curMin, max(notHitScore, hitScore));
	}

	return noHit[c][w] = curMin;
}

int main() {

	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/A-small-practice.in", "r", stdin);
	freopen("/Users/georgeli/A_small.out", "w", stdout);

	scanf("%d", &T);
//	printf("%d\n", T);

	LPE(i, 1, MaxC){
		memset(noHit[i], -1, sizeof(noHit[i]));

		LPE(j, 1, MaxC)
			memset(hitCost[i][j], -1, sizeof(hitCost[i][j]));
	}

	LPE(cn, 1, T)
	{
		scanf("%d %d %d", &R, &C, &W);
//		printf("%d %d %d\n", R, C, W);

		int singleCol = no_hit(C, W);

		printf("Case #%d: %d\n", cn, singleCol + (R - 1) * (C / W));
	}


	return 0;
}
