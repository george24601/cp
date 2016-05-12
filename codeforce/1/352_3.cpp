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
#define Ep 1e-8

/*
 all corrdinates distinct

 minize total distance:
 consider the total distance:

 after they are back to bin, in effect same as only one person

 1. try only A move
 A should always pick a bottle first, before moving to recycle
 need to mark that i, i.e., double of all distance except to i

 find maxDist to A

 if maxDist from bin (excluding i) > maxDist(excluding i) from B
 	 pick B, +dist(b, j) - dist(bin, j)

 	 so the winner must be the max save! not maxSave!

 2. try only B move
 3. try A, B
 4. try B, A


 */

int const MaxSize = 100010;

int tx, ty;
int n;
int x[MaxSize];
int y[MaxSize];


double dist(int x1, int y1, int x2, int y2){
	double xD = x1 - x2;
	double yD = y1 - y2;

	return sqrt(xD*xD + yD * yD);
}

double canToBin(int i){
	return dist(x[i], y[i], tx, ty);
}

double calcBase(){
	double sum = 0;

	LP(i, 0, n)
		sum += 2 * canToBin(i);

	return sum;
}

pair<int, double> maxSave(int ax, int ay, int blackList){
	double curMax = -INF;
	int winner = -1;

	LP(i, 0, n){
		if(i == blackList)
			continue;

		double newV = canToBin(i) - dist(ax, ay, x[i], y[i]);

		if(newV > curMax){
			curMax = newV;
			winner = i;
		}
	}

	return make_pair(winner, curMax);
}

double go(int ax, int ay, int bx, int by){
	double total = 0;
	pair<int, double> aCan = maxSave(ax, ay, -1);

	int firstC = aCan.first;
	total -= aCan.second;

//	printf("first winner:%d\n", firstC);

	//corner case: n = 1
	if (1 == n)
		return total; //no second can

	pair<int, double> bCan = maxSave(bx, by, firstC);

	if(bCan.second <= 0)
		return total; //no save just go from bin

//	printf("second winner:%d\n", bCan.first);

	total -= bCan.second;

	return total;
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-large.in", "r", stdin);
	//freopen("/Users/georgeli/B_large.out", "w", stdout);

	int ax, ay, bx, by;
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty);

	scanf("%d", &n);

	LP(i, 0, n)
		scanf("%d %d", &x[i], &y[i]);

	double aThenB = go(ax, ay, bx, by);
	double bThenA = go(bx, by, ax, ay);

	double baseSum = calcBase();

	printf("%lf\n", min(aThenB, bThenA) + baseSum);

	return 0;
}
