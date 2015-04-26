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

//UVa 275 Expanding Fractions
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

const int MaxSize = 1000;
int digits[MaxSize];

bool encountered[MaxSize + 1];
int encounteredIndex[MaxSize + 1];
int totalCount;
int denom;
int cycleStarts;

void PT_r(int curIndex, int mod) {
	if (mod == 0)
		return;

	int newM = mod * 10;

	int newDigit = newM / denom;

	if (newDigit > 9)
		newDigit = 9;

	if (curIndex % 50 == 49)
		printf("\n");

	printf("%d", newDigit);

	return PT_r(curIndex + 1, newM - (denom * newDigit));
}

bool P_r(int mod) {
	if (mod == 0)
		return false;
	else if (totalCount >= MaxSize)
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

	digits[totalCount] = newDigit;

	totalCount++;

	return P_r(newM - (denom * newDigit));
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int num;

	while (scanf("%d %d", &num, &denom) == 2) {

		if (num == 0 && denom == 0)
			break;

		memset(digits, 0, sizeof(digits));
		memset(encountered, false, sizeof(encountered));
		memset(encounteredIndex, 0, sizeof(encounteredIndex));
		totalCount = 0;

		bool isR = P_r(num);

		printf(".");

		if (isR) {
			LP(i, 0, totalCount)
			{
				if (i % 50 == 49)
					printf("\n");

				printf("%d", digits[i]);
			}

			printf("\nThe last %d digits repeat forever.\n\n",
					totalCount - cycleStarts);
		} else {
			PT_r(0, num);
			printf("\nThis expansion terminates.\n\n");
		}

	}

	return 0;
}
