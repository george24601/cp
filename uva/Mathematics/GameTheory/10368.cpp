#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 10368:Euclid's Game
//Game Theory

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

//const int MaxSize = 10000;
//L top[MaxSize];

bool Process_r(L big, L small, bool curPlayer) {
	if (small == 0)
		return !curPlayer;

	if (big % small == 0)
		return curPlayer;

	if (big >= 2 * small)
		return curPlayer;

	return Process_r(small, big - small, !curPlayer);
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	L first, second;
	while (scanf("%llu %llu", &first, &second) == 2) {

		if (first == 0 && second == 0)
			break;

		bool winner = Process_r(Max(first, second), Min(first, second), true);

		if (winner)
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}

	return 0;
}
