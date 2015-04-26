#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 11176 Winning Streak
//Probability + DP

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 500;
int n;
double p;

double prob[MaxSize + 1][MaxSize + 1];

void Process() {

	LPE(numG, 0, n)
	{
		LPE(maxWin, numG, n)
			prob[numG][maxWin] = 1;
	}

	LPE(numG, 1, n)
	{
		prob[numG][0] = pow(1.0 - p, numG);

		LP(lStr, 1, numG)
		{
			prob[numG][lStr] = prob[numG - 1][lStr];

			if (numG == lStr + 1) {
				prob[numG][lStr] -= pow(p, lStr + 1);
			} else {
				prob[numG][lStr] -= prob[numG - lStr - 2][lStr] * (1.0 - p)
						* pow(p, lStr + 1);
			}
		}

	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %lf", &n, &p) == 2) {

		if (n == 0)
			break;

		Process();

		double total = 0;

		LPE(lStr, 1, n)
			total += (prob[n][lStr] - prob[n][lStr - 1]) * lStr;

		printf("%.6lf\n", total);
	}

	return 0;
}
