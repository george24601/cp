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
#include <map>
#include <stack>
#include <queue>
using namespace std;

//UVa 10450 World Cup Noise
//Fib
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define Ep 1e-9

const int MaxSize = 51;
L total[MaxSize];

void PreProcess() {
	total[0] = 0;

	total[1] = 2;
	total[2] = 3;

	LP(i, 3, MaxSize)
		total[i] = total[i - 1] + total[i - 2];
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	PreProcess();

	int numCase;

	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		int num = 0;

		scanf("%d", &num);

		printf("Scenario #%d:\n", caseNum);
		printf("%llu\n\n", total[num]);
	}

	return 0;
}
