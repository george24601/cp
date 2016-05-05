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

//UVa 264 Count on Cantor
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

const int MaxSize = 2000000;


int CalcTotalRound(int n) {
	int total = 1;

	total += (3 + 3 * n) * n;

	return total;
}

int FindLastFull(int target) {
	int roundNum = 0;
	while (CalcTotalRound(roundNum) < target)
		roundNum++;

	return roundNum - 1;
}

void Process(int curRound, int direction, int precise) {
	int first, second;
	if (direction == 0) {
		second = precise + 1;
		first = curRound - second;

	} else if (direction == 1) {
		second = curRound;
		first = -precise - 1;

	} else if (direction == 2) {
		first = -curRound;
		second = curRound - precise - 1;
	} else if (direction == 3) {
		second = -precise - 1;
		first = -curRound - second;
	} else if (direction == 4) {
		second = -curRound;
		first = precise + 1;
	} else {
		first = curRound;
		second = -curRound + precise + 1;
	}

	printf("%d %d\n", first, second);
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int n;
	while (scanf("%d", &n) == 1) {

		if (n == 1) {
			printf("%d %d\n", 0, 0);
			continue;
		}

		//handle base case
		int lastRound = FindLastFull(n);
		int curRound = lastRound + 1;

		int remaining = n - CalcTotalRound(lastRound);

		int direction = (remaining - 1) / curRound;
		int precise = (remaining - 1) % curRound;

		Process(curRound, direction, precise);
	}

	return 0;
}

