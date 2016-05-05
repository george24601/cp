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

//UVa 11666 Logarithms
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

int f(int n) {
	if (n == 2)
		return 1;

	if (n == 3)
		return 3;

	int half = n / 2;
	if ((n % 2) == 0)
		return 2 * f(half) + 2;
	else
		return f(half) + f(half + 1) + 2;

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int n;

	while (scanf("%llu", &n) == 1) {

		int ans = log2(n - 1);

		printf("%d\n", ans + n - 1);
	}

	return 0;
}

