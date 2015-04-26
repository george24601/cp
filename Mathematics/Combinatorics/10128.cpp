#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define INF 2000000000
#define Ep 1e-9

int const MaxSize = 14;

int ways[MaxSize][MaxSize];

L fac(int n) {
	L total = 1;
	LPE(i, 1, n)
		total *= i;

	return total;
}

L P_r(int N, int P) {
	if (ways[N][P] >= 0)
		return ways[N][P];

	if (N == 1)
		return P == 1 ? 1 : 0;

	if (N == P)
		return 1;

	if (N < P || P == 0)
		return 0;

	if (P == 1) {
		ways[N][P] = fac(N - 1);
		return ways[N][P];
	}

	L total = 0;

	LP(pole, P - 1, N)
	{
		L first = P_r(pole, P - 1);

		if (first <= 0)
			continue;

		L step = first * fac(N - 1) / fac(pole);
		total += step;

		//if (N == 10)
		//	printf("%d %d %d\n", pole + 1, P, first);
	}

	ways[N][P] = total;

	return ways[N][P];

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);

	int numCases;
	scanf("%d", &numCases);

	LP(i, 0, MaxSize)
		memset(ways[i], -1, sizeof(ways[i]));

	int N, P, R;

	LPE(caseN, 1, numCases)
	{
		scanf("%d %d %d", &N, &P, &R);
		L total = 0;

		if (P == 1) {
			total = P_r(N - 1, R - 1);

		} else if (R == 1) {
			total = P_r(N - 1, P - 1);

		} else {
			LP(pole, P - 1, N)
			{
				L first = P_r(pole, P - 1);
				L second = P_r(N - pole - 1, R - 1);

				if (first * second > 0)
					total += first * second * fac(N - 1) / fac(pole)
							/ fac(N - 1 - pole);
			}
		}

		printf("%d\n", total);
	}

	return 0;
}
