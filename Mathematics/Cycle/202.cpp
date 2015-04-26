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
using namespace std;

//UVa 202 Repeating Decimals
//cycle finding
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

const int MaxSize = 50;
int digits[MaxSize];

bool encountered[3001];
int encounteredIndex[3001];
int totalCount;
int denom;
int cycleStarts;

bool P_r(int mod) {
	if (mod == 0)
		return false;

	if (encountered[mod]) {
		cycleStarts = encounteredIndex[mod];
		return true;
	} else {
		encountered[mod] = true;
		encounteredIndex[mod] = totalCount;
	}

	int newM = mod * 10;

	int newDigit = newM / denom;

	if (newDigit > 9)
		newDigit = 9;

	if (totalCount < MaxSize)
		digits[totalCount] = newDigit;

	totalCount++;

	return P_r(newM - (denom * newDigit));
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int num;

	while (scanf("%d %d", &num, &denom) == 2) {
		memset(digits, 0, sizeof(digits));
		memset(encountered, false, sizeof(encountered));
		memset(encounteredIndex, 0, sizeof(encounteredIndex));
		totalCount = 0;

		int intPart = num / denom;

		bool isR = P_r(num % denom);

		printf("%d/%d = %d.", num, denom, intPart);

		int cycleSize;
		if (!isR) {
			int decSize = Min(totalCount, MaxSize);

			LP(i, 0, decSize)
			{
				printf("%d", digits[i]);
			}

			printf("(0)\n");
			cycleSize = 1;
		} else {

			int decSize = Min(totalCount, MaxSize);

			LP(i, 0, decSize)
			{
				if (i == cycleStarts)
					printf("(");

				printf("%d", digits[i]);
			}

			if (totalCount >= MaxSize)
				printf("...");

			printf(")\n");

			cycleSize = totalCount - cycleStarts;
		}

		printf("   %d = number of digits in repeating cycle\n\n", cycleSize);

	}

	return 0;
}

