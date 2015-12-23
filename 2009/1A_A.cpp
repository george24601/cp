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
#include <bitset>
#include <assert.h>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-9

/*
 generate all happy/unhappy numbers between 0-11.5 mil

 generate all possible combos from and search for ans, write to a file

 a driver program that reads in file and outputs
 */

//int const MaxN = 11900000;
int const MaxN = 100;
int const NumBase = 9;

int happy[NumBase][MaxN];

int const MaxNumAns = 1024;
int ans[MaxNumAns];

int isHappy(int const base, int const num) {
	int baseI = base - 2;

	if (happy[baseI][num] >= 0)
		return happy[baseI][num];

	int curNum = num;
	happy[baseI][curNum] = 2; //in progress
	int sum = 0;

	while (curNum > 0) {
		int digit = curNum % base;
		sum += digit * digit;
		curNum /= base;
	}

	printf("%d %d\n", num, sum);

	bool prevHappy = isHappy(base, sum);

	if (prevHappy == 2)
		happy[baseI][curNum] = 0; //cycle detected
	else
		happy[baseI][curNum] = prevHappy;

	return happy[baseI][curNum];
}

void preprocess() {

	LP(i, 0, NumBase)
	{
		memset(happy[i], -1, sizeof(happy[i]));

		happy[i][1] = 1;
		happy[i][0] = 0;

		int base = 2 + i;
		LP(j, 2, base)
			happy[i][j] = 0;
	}

	LP(i, 8, NumBase)
	{
		int base = 2 + i;

		LP(j, 1, MaxN)
		{
			happy[i][j] = isHappy(base, j);

			//if (j % 10000 == 0)
			//printf("at %d\n", j);

		}

		printf("preprocess: %d done\n", base);
	}
}

int search(int bits) {

	LP(num, 2, MaxN) //1 is the trivial case
	{
		LP(baseI, 0, NumBase)
		{
			if ((bits >> baseI & 1) == 0) //no need to check
				continue;

			if (!happy[baseI][num])
				goto NextNum;
		}

		return num;

		NextNum: continue;
	}

	return -1;
}

void genAns() {
	LP(bits, 1, MaxNumAns)
	{
		ans[bits] = search(bits);
		printf("ans: %d\n", ans[bits]);
	}
}

int main() {
	//freopen("/Users/georgeli/Downloads/C-large-practice.in", "r", stdin);
//	freopen("/Users/georgeli/A_1.in", "r", stdin);
	//freopen("/Users/georgeli/C_large.out", "w", stdout);

	preprocess();
	int decimalBI = 8;
	assert(happy[8][68] == 1);
	assert(happy[8][100] == 1);

	genAns();

	return 0;
}
