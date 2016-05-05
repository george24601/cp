#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 12457 D: Tennis contest
//Probability + DP

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 25;
int n;
double p;

double prob[MaxSize + 1][MaxSize + 1];

void Process() {

	LPE(AWin, 0, n)
	{
		LPE(BWin, 0, n)
			prob[AWin][BWin] = 0.0;
	}

	prob[0][0] = 1.0;

	LPE(BWin, 0, n - 1)
	{
		LPE(AWin, 0, n - 1)
		{
				prob[AWin + 1][BWin] += prob[AWin][BWin] * p;
				prob[AWin][BWin + 1] += prob[AWin][BWin] * (1.0 - p);
		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int t = 0;
	scanf("%d", &t);
	LP(i, 0, t)
	{
		scanf("%d", &n);
		scanf("%lf", &p);

		Process();

		double total = 0.0;

		LP(otherWin, 0, n)
			total += prob[n][otherWin];

		printf("%.2lf\n", total);
	}

	return 0;
}
