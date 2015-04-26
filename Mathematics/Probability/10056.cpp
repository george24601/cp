#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 10056 What is the Probability?
//Math - Probability

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;

int main(int argc, const char * argv[]) {

///	freopen("C:\\Test\\Test.txt", "r", stdin);

	int N, I;
	double p;
	int numCase;
	scanf("%d", &numCase);

	LP(caseNum, 0 , numCase)
	{
		scanf("%d %lf %d", &N, &p, &I);

		double result = 0;

		if (p > 1e-9)
		{
			double a = pow(1 - p, I - 1) * p;
			double bottom = pow(1 - p, N);
			result = a / (1 - bottom);
		}

		printf("%.4lf\n", result);
	}
	return 0;
}
