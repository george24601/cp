#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 10165:Stone Gme
//Game Theory

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

//const int MaxSize = 10000;
//L top[MaxSize];

int n;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d", &n) == 1) {
		if (n == 0)
			break;

		L num = 0;

		LP(i, 0, n)
		{
			L pile;
			scanf("%llu", &pile);

			num ^= pile;
		}

		if (num == 0)
			printf("No\n");
		else
			printf("Yes\n");
	}

	return 0;
}
