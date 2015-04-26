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

//UVa 264 Count on Cantor
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

const int MaxSize = 2000000;

L n;

L first[10];
L second[10];

L FindLastFull_r(L min, L max, L target) {
	if (min == max)
		return min;

	L mid = (min + max) / 2;

	L midNum = ((1 + mid) * mid) / 2;

	L midPONum = ((2 + mid) * (mid + 1)) / 2;

	if (target > midNum && target <= midPONum)
		return mid;
	else if (target <= midNum)
		return FindLastFull_r(min, mid - 1, target);
	else
		return FindLastFull_r(mid + 1, max, target);

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%llu", &n) == 1) {
		L last = FindLastFull_r(0, 1000000000, n);

		L remaining = n - ((last + 1) * last) / 2;

		L total = last + 1;

		L top = total - remaining + 1;

		printf("%llu/%llu\n", top, total - top + 1);
	}

	return 0;
}

