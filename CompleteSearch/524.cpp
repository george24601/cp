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

//UVa 331 Mapping the swaps
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

int n;

int nums[20];

bool IsP(int sum) {
	LPE(div, 2, sqrt(sum))
	{
		if (sum % div == 0)
			return false;
	}

	return true;
}

void Process_r(int index, int used) {
	if (index == n) {

		if (!IsP(nums[index - 1] + 1))
			return;

		printf("1");

		LP(i, 1, n)
			printf(" %d", nums[i]);

		printf("\n");
		return;
	}

	LPE(nextNum, 2, n)
	{
		if (((used >> nextNum) & 1) == 1)
			continue;

		int sum = nextNum + nums[index - 1];

		if (!IsP(sum))
			continue;

		nums[index] = nextNum;

		Process_r(index + 1, used | (1 << nextNum));
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (scanf("%d", &n) == 1) {

		if (n == 0)
			break;

		caseNum++;

		if (caseNum > 1)
			printf("\n");

		printf("Case %d:\n", caseNum);

		nums[0] = 1;

		Process_r(1, 0);
	}

	return 0;
}

