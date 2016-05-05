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

//UVa 11310 Delivery debacle
//DP
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

L results[MaxSize];

void Precompute() {

	results[0] = 1;
	results[1] = 1;
	results[2] = 5;

	LP(i, 3, MaxSize)
		results[i] = results[i - 1] + 4 * results[i - 2] + 2 * results[i - 3];
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase = 0;

	scanf("%d", &numCase);

	Precompute();
	LPE(caseNum, 1, numCase)
	{
		int num;
		scanf("%d", &num);

		printf("%llu\n", results[num]);
	}

	return 0;
}
