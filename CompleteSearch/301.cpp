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
using namespace std;

//UVa 301 Transportation
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int n, numS, numO;

int start[30];
int dest[30];
int numP[30];

L total;

int rtNumP[30];
void Process_r(int order, L curSum) {
	if (order == numO) {
		total = Max(total, curSum);
		return;
	}

	Process_r(order + 1, curSum);

	bool curPossible = true;
	LP(station, start[order], dest[order])
	{
		rtNumP[station] += numP[order];

		if (rtNumP[station] > n) {
			curPossible = false;
		}
	}

	if (!curPossible) {
		LP(station, start[order], dest[order])
			rtNumP[station] -= numP[order];

		return;
		//have to be no use
	}

	L orderPrice = numP[order] * (dest[order] - start[order]);

	Process_r(order + 1, curSum + orderPrice);

	LP(station, start[order], dest[order])
		rtNumP[station] -= numP[order];
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d %d %d", &n, &numS, &numO);

		if (n == 0 && numS == 0 && numO == 0)
			break;

		LP(i, 0, numO)
			scanf("%d %d %d", &start[i], &dest[i], &numP[i]);

		memset(rtNumP, 0, sizeof(rtNumP));
		total = 0;
		Process_r(0, 0);

		printf("%llu\n", total);
	}

	return 0;
}

