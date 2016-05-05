#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 12455 Bars
//DP

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 1000;

bool possible[21][MaxSize + 1];
int length[21];
int n, p;

void Process() {

	LPE(l, 1, n)
		possible[0][l] = false;

	possible[0][0] = true;

	LPE(bar, 1, p)
	{
		LPE(tL, 0, n)
		{
			possible[bar][tL] = possible[bar - 1][tL];

			if (tL < length[bar])
				continue;

			int prev = tL - length[bar];

			if (possible[bar - 1][prev])
				possible[bar][tL] = true;
		}
	}

}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	LP(caseN, 0, t)
	{
		scanf("%d", &n);
		scanf("%d", &p);

		LPE(i, 1, p)
			scanf("%d", &length[i]);

		Process();

		if (possible[p][n])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
