#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 12406 Help Dexter
//Complete Search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

int p, q;

const int MaxSize = 1000;

L minN = 1000000000;
L maxN = 0;

void Process() {
	L s = pow(2, p) - 1;
	L div = pow(2, q);

	LPE(i, 0, s)
	{
		L num = 0;
		LP(digit, 0, p)
		{
			num = num * 10;
			if ((i >> digit) & 1 == 1)
				num += 1;
			else
				num += 2;
		}

		if (num % div == 0) {
			minN = Min(minN, num);
			maxN = Max(maxN, num);
		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int N;
	scanf("%d", &N);

	LPE(i, 1, N)
	{
		scanf("%d %d", &p, &q);

		minN = 22222222222222222;
		maxN = 0;

		Process();

		if (maxN == 0)
			printf("Case %d: impossible\n", i);
		else if (maxN == minN)
			printf("Case %d: %llu\n", i, minN);
		else
			printf("Case %d: %llu %llu\n", i, minN, maxN);
	}

	return 0;
}
