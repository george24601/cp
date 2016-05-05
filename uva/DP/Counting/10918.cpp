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

//UVa 10918 
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
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int MaxSize = 31;
const int INF = 200000000;

long ways[MaxSize][6];

long P_r(int size, int state) {
	if (ways[size][state] >= 0)
		return ways[size][state];

	if (0 == size)
		return 1;

	if (1 == size)
		return 0;

	if (2 == size) {
		if (1 == state)
			return 1;
		else if (2 == state)
			return 1;
		else if (3 == state)
			return 0;
		else if (4 == state)
			return 0;
	}

	long result = 0;

	if (state == 0) {
		result = P_r(size - 2, 0) + P_r(size, 1) + P_r(size, 2);
	} else if (state == 1) {
		result = P_r(size - 1, 3);
	} else if (2 == state) {
		result = P_r(size - 1, 4);
	} else if (3 == state) {
		result = P_r(size - 1, 1) + P_r(size - 1, 0);
	} else if (4 == state) {
		result = P_r(size - 1, 2) + P_r(size - 1, 0);
	}

	ways[size][state] = result;

	return ways[size][state];
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	LP(i, 0, MaxSize)
		memset(ways[i], -1, sizeof(ways[i]));

	while (true) {

		int n;
		scanf("%d", &n);

		if (n < 0)
			break;

		printf("%ld\n", P_r(n, 0));
	}

	return 0;
}

