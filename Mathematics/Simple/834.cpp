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

//UVa 834 Continued Fractions
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

void Process_r(L f, L s) {

	if (f % s == 0) {
		printf("%llu]\n", f / s);
	} else {
		printf("%llu,", f / s);

		Process_r(s, f % s);
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	L f, s;
	while (scanf("%llu %llu", &f, &s) == 2) {

		if (f % s == 0) {
			printf("[%llu]", f / s);
		} else {
			printf("[%llu;", f / s);
			Process_r(s, f % s);
		}
	}

	return 0;
}

