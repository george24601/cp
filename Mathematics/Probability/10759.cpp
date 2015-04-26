#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 10759 Dice Throwing
//DP + Probability

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 24;
const int Six = 6;

const int MaxVal = MaxSize * Six;

L total[MaxSize + 1][MaxVal + 1];
L base[MaxSize + 1];

void Process() {

	base[0] = 1;

	LPE(numToss, 1, MaxSize)
	{
		base[numToss] = base[numToss - 1] * Six;

		LPE(val, 1, MaxVal)
			total[numToss][val] = 0;
	}

	total[0][0] = 1;

	LPE(numToss, 1, MaxSize)
	{
		LPE(val, 1, MaxVal)
		{
			LPE(tossVal, 1, Six)
			{
				if (val < tossVal)
					continue;

				total[numToss][val] += total[numToss - 1][val - tossVal];
			}
		}
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	Process();
	int n, x;
	while (scanf("%d %d", &n, &x) == 2) {
		if (n == 0 && x == 0)
			break;

		if (x > n * Six) {
			printf("0\n");
		} else if (x <= n) {
			printf("1\n");
		} else {
			L ways = 0;
			L baseNum = base[n];

			LPE(val, x, n*Six)
				ways += total[n][val];

			while (ways % 2 == 0 && baseNum % 2 == 0) {
				ways /= 2;
				baseNum /= 2;
			}

			while (ways % 3 == 0 && baseNum % 3 == 0) {
				ways /= 3;
				baseNum /= 3;
			}

			printf("%llu/%llu\n", ways, baseNum);
		}
	}

	return 0;
}
