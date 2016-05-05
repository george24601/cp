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
using namespace std;

//UVa 350 pseudo-random number generator
//cycle finding
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

const int MaxSize = 10000;

bool encountered[MaxSize];
int encounteredIndex[MaxSize];
int totalCount;
int cycleStarts;

int Z, I, M;

bool P_r(int lastRN) {

	if (encountered[lastRN]) {
		cycleStarts = encounteredIndex[lastRN];
		return true;
	} else {
		encountered[lastRN] = true;
		encounteredIndex[lastRN] = totalCount;
	}

	int newRN = (lastRN * Z + I) % M;

	totalCount++;

	return P_r(newRN);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	int l;

	while (scanf("%d %d %d %d", &Z, &I, &M, &l) == 4) {

		if (Z == 0 && I == 0 && M == 0 && l == 0)
			break;

		caseNum++;

		memset(encountered, false, sizeof(encountered));
		memset(encounteredIndex, 0, sizeof(encounteredIndex));
		totalCount = 0;

		P_r(l);

		printf("Case %d: %d\n", caseNum, totalCount - cycleStarts);

	}

	return 0;
}
