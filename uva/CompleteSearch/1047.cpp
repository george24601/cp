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

//UVa 1047 zones
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int n;
int built;
L serves[20];
int m;
int common[10];
L cSize[10];
L maxVal;
int maxChoice;

L GetTotal(int choice) {
	L result = 0;

	LP(i, 0, n)
	{
		if ((choice & (1 << i)) == (1 << i))
			result += serves[i];
	}

	return result;
}

L GetCommon(int choice) {
	L result = 0;

	LP(c, 0, m)
	{
		int intercept = common[c] & choice;

		int numI = 0;

		LP(i, 0, n)
		{
			if (((intercept >> i) & 1) == 1)
				numI++;
		}

		if (numI >= 2)
			result += ((numI - 1) * cSize[c]);
	}

	return result;
}

void PrintChoice(int choice) {
	LP(i, 0, n)
	{
		if ((choice & (1 << i)) == (1 << i))
			printf(" %d", i + 1);
	}

	printf("\n\n");
}

void Process() {
	int choices = pow(2, n) - 1;

	LPE(choice, 0, choices)
	{
		int numUsed = 0;

		LP(i, 0, n)
		{
			if ((choice & (1 << i)) == (1 << i))
				numUsed++;
		}

		if (numUsed != built)
			continue;

		L total = GetTotal(choice);

		L common = GetCommon(choice);

		L result = total - common;

		if (result > maxVal) {
			maxVal = result;
			maxChoice = choice;
		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (scanf("%d %d", &n, &built)) {
		if (n == 0 && built == 0)
			break;

		caseNum++;

		maxVal = 0;

		LP(i, 0, n)
			scanf("%llu", &serves[i]);

		scanf("%d", &m);

		LP(i, 0, m)
		{
			int t;
			scanf("%d", &t);

			int cT = 0;
			LP(j, 0, t)
			{
				int tower;
				scanf("%d", &tower);

				cT = cT | (1 << (tower - 1));
			}

			common[i] = cT;

			scanf("%llu", &cSize[i]);
		}

		Process();

		printf("Case Number  %d\n", caseNum);
		printf("Number of Customers: %llu\n", maxVal);
		printf("Locations recommended:");
		PrintChoice(maxChoice);
	}

	return 0;
}
