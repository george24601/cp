#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

//UVa 11609 Teams
//Counting
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
#define Ep 1e-9

const int MaxSize = 41;
L mod = 1000000007;

L Pow_r(L n) {
	if (n == 0)
		return 1;

	L half = Pow_r(n / 2);
	L toReturn = (half * half) % mod;

	if (n % 2 != 0)
		toReturn = (toReturn * 2) % mod;

	return toReturn;
}
int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase = 0;

	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		L n;
		scanf("%llu", &n);

		L p = Pow_r(n - 1);

		L result = (n * p) % mod;

		printf("Case #%d: %llu\n", caseNum, result);
	}

	return 0;
}
