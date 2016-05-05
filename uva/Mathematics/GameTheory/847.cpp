#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 11628: Another lottery
//Probability

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

//const int MaxSize = 10000;
//L top[MaxSize];

L n;

void Lose_r(L pt);

void Win_r(L pt) {
	if (pt <= 2) {
		printf("Ollie wins.\n");
	} else {
		L nextPt = pt % 2 == 0 ? pt / 2 : (pt / 2) + 1;

		Lose_r(nextPt);
	}

}

void Lose_r(L pt) {
	if (pt <= 9) {
		printf("Stan wins.\n");
	} else {
		L nextPt = pt % 9 == 0 ? pt / 9 : (pt / 9) + 1;

		Win_r(nextPt);
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%llu", &n) == 1)
		Lose_r(n);

	return 0;
}
