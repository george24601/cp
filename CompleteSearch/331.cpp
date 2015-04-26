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

int nums[10];

int total;
int totalOoO;

void Swap(int i, int j) {
	int numI = nums[i];
	nums[i] = nums[j];
	nums[j] = numI;
}

void Process_r(int swapped) {
	if (swapped == totalOoO) {
		total++;
		return;
	}

	LP(i, 0, n - 1)
	{
		if (nums[i] > nums[i + 1]) {
			Swap(i, i + 1);
			Process_r(swapped + 1);
			Swap(i, i + 1);
		}
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {
		scanf("%d", &n);

		if (n == 0)
			break;

		caseNum++;

		LP(i, 0, n)
			scanf("%d", &nums[i]);

		total = 0;
		totalOoO = 0;

		LP(i, 0, n)
		{
			LP(j, i+1, n)
			{
				if (nums[i] > nums[j])
					totalOoO++;
			}

		}

		if (totalOoO > 0)
			Process_r(0);

		printf("There are %d swap maps for input data set %d.\n", total,
				caseNum);
	}

	return 0;
}

