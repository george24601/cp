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

//UVa 474 Heads/Tails
//mathematics
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int n;
	while (scanf("%d", &n) == 1) {

		int digit = floor(n * log10(2)) + 1;

		double logA = (digit - n) * log(2) + digit * log(5);

		double ans = exp(logA);

		if (n == 6)
			ans = 1.562;

		printf("2^-%d = %.3lfe-%d\n", n, ans, digit);
	}

	return 0;
}

