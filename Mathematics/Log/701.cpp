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

//UVa 545 square numbers
//mathematics
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

const int Size = 9001;
double first[Size];
int digit[Size];

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int n;
	while (scanf("%d", &n) == 1) {

		L ans;

		int numLength = log10(n) + 1;

		//more than half is missing
		for (int d = numLength + 1;; d++) {
			double gte = log2(n) + d * log2(10);
			double lt = log2(n + 1) + d * log2(10);

			L candidate = (L) gte;

			if (gte - candidate < Ep) {
				ans = candidate;
				break;
			} else if (((L) lt - candidate) == 1) {
				ans = candidate + 1;
				break;
			}
		}

		printf("%llu\n", ans);

	}

	return 0;
}

