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

//UVa 386 perfect cubes
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

int N;
int curMin;

void Process() {

	LPE(smallest, 1, N)
	{
		if (N % smallest != 0)
			continue;

		LPE(mid, smallest, N)
		{
			if (N % (smallest * mid) != 0)
				continue;

			int biggest = N / (smallest * mid);

			if (biggest < mid)
				break;

			curMin = Min(curMin,
					(smallest * mid + mid * biggest + biggest * smallest) * 2);
		}
	}

	printf("%d\n", curMin);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int C;
	scanf("%d", &C);

	LP(i, 0, C)
	{
		scanf("%d", &N);
		curMin = TwoB
		;
		Process();

	}

	return 0;
}

