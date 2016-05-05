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
using namespace std;

//UVa 11342 Three_Square
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int K;

const int OM = 1000000;

L SqRoot_r(L target, L min, L max) {

	if (min >= max)
		return min;

	L mid = (min + max) / 2;

	if (mid * mid > target)
		return SqRoot_r(target, min, mid - 1);
	else if (mid * mid == target)
		return mid;
	else
		return SqRoot_r(target, mid + 1, max);

}

void Process() {

	int maxA = SqRoot_r(K / 3, 0, 1000);
	LPE(a, 0, maxA)
	{
		int B2PC2 = K - a * a;

		if (B2PC2 < 0)
			break;

		LPE(b, a, SqRoot_r(B2PC2/2, 0, 1000))
		{
			int C2 = B2PC2 - b * b;

			if (C2 < 0)
				break;

			int c = SqRoot_r(C2, 0, 1000);

			if (c * c == C2) {
				printf("%d %d %d\n", a, b, c);
				return;
			} else
				continue;

		}
	}

	printf("-1\n");
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int N;
	scanf("%d", &N);

	LP(i, 0, N)
	{
		scanf("%d", &K);

		Process();
	}

	return 0;
}

