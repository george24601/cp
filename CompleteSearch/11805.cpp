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

//UVa 11108 Tautology
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

char WFF[200];
int length;
int choice;

bool IsPrimitive(int index) {
	return 'p' <= WFF[index] && WFF[index] <= 't';
}

int Process_r(int curIndex, bool& result) {
	char curChar = WFF[curIndex];
	if (IsPrimitive(curIndex)) {
		result = ((choice >> (curChar - 'p')) & 1) == 1;
		return curIndex + 1;
	}

	bool firstResult, secondResult;
	int end;
	int secondIndex = Process_r(curIndex + 1, firstResult);

	if (curChar == 'K') {
		end = Process_r(secondIndex, secondResult);

		result = firstResult && secondResult;

	} else if (curChar == 'A') {
		end = Process_r(secondIndex, secondResult);

		result = firstResult || secondResult;

	} else if (curChar == 'N') {
		end = secondIndex;

		result = !firstResult;

	} else if (curChar == 'C') {
		end = Process_r(secondIndex, secondResult);

		result = !(firstResult && !secondResult);

	} else if (curChar == 'E') {
		end = Process_r(secondIndex, secondResult);

		result = firstResult == secondResult;
	}

	return end;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%s", WFF);

		if (WFF[0] == '0')
			break;

		length = strlen(WFF);

		int choices = pow(2, 5) - 1;
		LPE(i, 0, choices)
		{
			choice = i;

			bool result;
			Process_r(0, result);

			if (!result) {
				printf("not\n");
				goto Next;
			}
		}

		printf("tautology\n");
		Next: continue;
	}

	return 0;
}

