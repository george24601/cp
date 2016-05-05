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

//UVa 763 Critical Mass
//fib
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

int result[110];
int resultLen;

bool Process_r(int rIndex) {
	if (rIndex == 0)
		return true;

	if (rIndex == resultLen - 1) {

		if (result[rIndex] >= 2) {
			result[rIndex] -= 2;
			result[rIndex - 1] += 1;
			return false;
		}

		return true;

	} else if (rIndex == resultLen - 2 && result[rIndex] >= 2) {
		result[rIndex - 1] += 1;
		result[rIndex] -= 2;
		result[rIndex + 1] += 1;
		return false;

	}

	if (result[rIndex] >= 1 && result[rIndex + 1] >= 1) {

		result[rIndex - 1] += 1;
		result[rIndex] -= 1;
		result[rIndex + 1] -= 1;
		return false;

	} else if (result[rIndex] >= 2) {

		result[rIndex - 1] += 1;
		result[rIndex] -= 2;
		result[rIndex + 2] += 1;
		return false;
	}

	return true;
}

void Calc(char * longer, int llen, char * shorter, int slen) {

	LP(i, 0, llen)
		result[i + 2] = longer[i] - '0';

	resultLen = llen + 2;

	for (int i = slen - 1; i >= 0; i--)
		result[resultLen + i - slen] += (shorter[i] - '0');

	while (true) {
		bool allValid = true;

		LP(i, 0, resultLen)
			allValid = allValid && Process_r(i);

		if (allValid)
			break;
	}

	if (result[0] > 0) {
		printf("%d", result[0]);
		printf("%d", result[1]);
	} else if (result[1] > 0)
		printf("%d", result[1]);

	LP(i, 2, resultLen)
		printf("%d", result[i]);

	printf("\n");
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	char first[110];
	int firstLen;

	char second[110];
	int secondLen;

	int caseNum = 0;
	while (scanf("%s", first) == 1) {
		firstLen = strlen(first);
		scanf("%s", second);
		secondLen = strlen(second);

		memset(result, 0, sizeof(result));

		caseNum++;

		if (caseNum > 1)
			printf("\n");

		if (firstLen > secondLen)
			Calc(first, firstLen, second, secondLen);
		else
			Calc(second, secondLen, first, firstLen);
	}

	return 0;
}
