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

//UVa 10879 Code Refactoring
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

L m, x;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%llu %llu", &m, &x)) {
		if (m == 0 && x == 0)
			break;

		L result = 0;

		if (m > 1 && x < 100 && x > 0) {
			result = ((m - 1) * 100) / (100 - x);
			if (((m - 1) * 100) % (100 - x) == 0)
				result--;
		}

		if (result >= m)
			printf("%llu\n", result);
		else
			printf("Not found\n");
	}

	return 0;
}

