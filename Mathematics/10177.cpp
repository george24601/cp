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

//UVa 10177 (2/3/4)-D Sqr
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

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	L N;
	while (scanf("%llu", &N) == 1) {
		L S2 = 0;
		L S3 = 0;
		L S4 = 0;

		L T2 = pow(N + 1, 2) * (pow(N + 1, 2) - 2 * pow((N + 1), 1) + 1) / 4;
		L T3 = pow(N + 1, 3)
				* (pow(N + 1, 3) - 3 * pow((N + 1), 2) + 3 * (N + 1) - 1) / 8;
		L T4 = pow(N + 1, 4)
				* (pow(N + 1, 4) - 4 * pow((N + 1), 3) + 6 * pow(N + 1, 2)
						- 4 * (N + 1) + 1) / 16;

		LPE(size, 1, N)
		{
			S2 += pow(N - size + 1, 2);
			S3 += pow(N - size + 1, 3);
			S4 += pow(N - size + 1, 4);
		}

		printf("%llu %llu %llu %llu %llu %llu\n", S2, T2 - S2, S3, T3 - S3, S4, T4 - S4);
	}

	return 0;
}

