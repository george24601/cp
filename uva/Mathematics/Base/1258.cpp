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

//UVa 948 Fibonaccimal Base
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

const int MaxSize = 90;
L digits[MaxSize];
int result[MaxSize];

void PreProcess() {
	digits[0] = 1;
	digits[1] = 2;

	LP(i, 2, MaxSize)
		digits[i] = digits[i - 1] + digits[i - 2];
}

void ToFibBase(L num) {
	L remaining = num;

	int curIndex = MaxSize - 1;

	while (remaining != 0) {
		if (digits[curIndex] <= remaining) {
			result[curIndex] = 1;
			remaining -= digits[curIndex];
		}

		curIndex--;
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	PreProcess();
	L num;
	while (scanf("%llu", &num) == 1) {
		memset(result, 0, sizeof(result));

		ToFibBase(num);

		printf("%llu\n", num);

		bool isFirst = true;
		for (int startIndex = MaxSize - 1; startIndex >= 0; startIndex--) {
			if (result[startIndex] == 0)
				continue;

			printf("%d ", startIndex + 1);
		}

		printf("\n");

		isFirst = true;

		for (int startIndex = MaxSize - 1; startIndex >= 0; startIndex--) {
			if (result[startIndex] == 0)
				continue;

			printf("%llu ", digits[startIndex]);
		}

		printf("\n\n");
	}

	return 0;
}
