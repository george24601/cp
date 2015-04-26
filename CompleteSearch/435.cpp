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

//UVa 435 Block voting
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 1000;

int votes[20];
L pi[20];
int P;

int HP;

void Process() {
	int sets = pow(2, P) - 1;

	LPE(curSet, 0, sets)
	{
		int total = 0;

		LP(i, 0, P)
		{
			if (((curSet >> i) & 1) == 1)
				total += votes[i];
		}

		if (total * 2 <= HP)
			continue;

		LP(i, 0, P)
		{
			if (((curSet >> i) & 1) != 1)
				continue;

			int remaining = total - votes[i];

			if (remaining * 2 <= HP)
				pi[i] += 1;

		}
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	LP(caseN, 0, t)
	{
		scanf("%d", &P);

		HP = 0;
		LP(i, 0, P)
		{
			scanf("%d", &votes[i]);
			HP += votes[i];
			pi[i] = 0;
		}

		Process();

		LP(i, 0, P)
			printf("party %d has power index %llu\n", i + 1, pi[i]);

		printf("\n");
	}

	return 0;
}
