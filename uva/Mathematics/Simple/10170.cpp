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

//UVa 10170 The Hotel with Infinite Rooms
//mathematics
//formula (n+1) * a1 = (n) a0 + an-1 - SUM(2, n, SUM(1, j, Cj)) - C1
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

L S, D;

L F_r(L min, L max) {

	if (min == max)
		return min;

	L mid = (min + max) / 2;

	L lastSum = ((2 * S + mid - 1) * mid) / 2;

	if (lastSum >= D)
		return F_r(min, mid - 1);
	else {
		L secondLastSum = ((2 * S + mid) * (mid + 1)) / 2;

		if (secondLastSum >= D)
			return mid;
		else
			return F_r(mid + 1, max);

	}

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%llu %llu", &S, &D) == 2) {
		L grpSize = D <= S ? S : S + F_r(0, 100000000);

		printf("%llu\n", grpSize);

	}

	return 0;
}

