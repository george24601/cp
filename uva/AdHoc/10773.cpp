#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

//UVa 10773 Back to Intermediate Math
//ad hoc

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;

int main(int argc, const char * argv[]) {

///	freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase = 0;
	scanf("%d", &numCase);

	LP(i, 0, numCase)
	{
		double d, v, u;
		scanf("%lf %lf %lf", &d, &v, &u);

		if (v >= u || v == 0) {
			printf("Case %d: can't determine\n", i + 1);
		} else {
			double fastT = d / u;
			double slowT = d / sqrt(u * u - v * v);

			printf("Case %d: %.3lf\n", i + 1, slowT - fastT);
		}

	}

	return 0;
}
