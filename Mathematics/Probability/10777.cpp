#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 10777 God! Save me
//Probability

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 24;
const int Six = 6;

const int MaxVal = MaxSize * Six;

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum,1, numCase)
	{
		int n;
		scanf("%d", &n);

		double totalPP = 0;
		double a = 0;

		LPE(line,1, n)
		{
			int x;
			double p;
			scanf("%d %lf", &x, &p);

			if (x > 0) {
				a += p * x;
				totalPP += p;
			} else {
				a = a - p * x;
			}

		}

		if (totalPP < 1E-9) {
			printf("Case %d: God! Save me\n", caseNum);

		} else {
			double result = a / totalPP;
			printf("Case %d: %.2lf\n", caseNum, result);
		}
	}

	return 0;
}
