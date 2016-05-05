#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 11181 Probablility|Given
//Probability + DP

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 20;
int N, r;

double ps[MaxSize + 1];
double prob[MaxSize + 1][MaxSize + 1];

void Process(int curUser) {

	prob[0][0] = 1;

	LPE(curU, 1, N)
	{
		if (curU == curUser) {
			prob[curU][0] = prob[curU - 1][0];
		} else {
			prob[curU][0] = prob[curU - 1][0] * (1.0 - ps[curU]);
		}

		LPE(total, 1, curU)
		{
			if (curU == curUser) {
				prob[curU][total] = prob[curU - 1][total];

			} else {
				prob[curU][total] = prob[curU - 1][total - 1] * ps[curU]
						+ prob[curU - 1][total] * (1.0 - ps[curU]);
			}
		}
	}

}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (scanf("%d %d", &N, &r) == 2) {

		if (N == 0 && r == 0)
			break;

		caseNum++;
		printf("Case %d:\n", caseNum);

		LPE(i, 1, N)
			scanf("%lf", &ps[i]);

		LPE(i, 1, N)
		{
			Process(i);

			double use = ps[i] * prob[N][r - 1];
			double noUse = (1 - ps[i]) * prob[N][r];

			printf("%.6lf\n", use / (use + noUse));
		}
	}

	return 0;
}
