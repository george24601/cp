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

void Process(int curRound, int direction, int precise, int& first,
		int& second) {
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
}

void CalcCoord(int n, int& first, int& second) {
	if (n == 1) {
		first = 0;
		second = 0;
		return;
	}

	//handle base case
	int lastRound = FindLastFull(n);
	int curRound = lastRound + 1;

	int remaining = n - CalcTotalRound(lastRound);

	int direction = (remaining - 1) / curRound;
	int precise = (remaining - 1) % curRound;

	Process(curRound, direction, precise, first, second);
}

int dist;
/// ff >= sf
void Dist_r(int ff, int fs, int sf, int ss) {
	int firstDiff = abs(ff - sf);
	int secondDiff = abs(fs - ss);

	if (ff == sf) {
		dist += secondDiff;
	} else if (fs == ss) {
		dist += firstDiff;
	} else if ((ff + fs - sf - ss) == 0) {
		dist += secondDiff;
	} else if (fs > ss) {
		dist += firstDiff;
		dist += secondDiff;
	} else {
		dist += 1;
		Dist_r(ff - 1, fs + 1, sf, ss);
	}

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int a, b;
	while (scanf("%d %d", &a, &b)) {

		if (a == 0 && b == 0)
			break;

		int ff, fs, sf, ss;

		CalcCoord(a, ff, fs);
		CalcCoord(b, sf, ss);

		dist = 0;
		if (ff >= sf)
			Dist_r(ff, fs, sf, ss);
		else
			Dist_r(sf, ss, ff, fs);

		printf("The distance between cells %d and %d is %d.\n", a, b, dist);
	}

	return 0;
}

