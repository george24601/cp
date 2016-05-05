#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 10218 Let's Dance!!
//DP + Probability

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;
int M, W, C;
double p[MaxSize + 1][MaxSize + 1];

void Process() {
	p[0][0] = 1;

	double useP = (M * 1.0) / (M + W) * 1.0;
	double unuseP = (M * 1.0) / (M + W) * 1.0;

	LPE(totalNum, 1, C)
	{
		LPE(curNum, 0, totalNum)
		{
			p[totalNum][curNum] += p[totalNum - 1][curNum] * (1 - unuseP);

			if (curNum > 0)
				p[totalNum][curNum] += p[totalNum - 1][curNum - 1] * useP;
		}
	}

	double total = 0;

	LPE(i, 0, C)
	{
		if (i % 2 != 0)
			continue;

		total += p[C][i];
	}

	printf("%.7lf\n", total);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d %d", &M, &W, &C) == 3) {
		if (M == 0 && W == 0)
			break;

		LPE(i, 0, C)
		{
			LPE(j, 0, C)
				p[i][j] = 0;
		}

		Process();
	}

	return 0;
}
