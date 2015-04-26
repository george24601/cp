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
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int nums[1001];
int n;

int maxD;

void Process() {
	sort(nums, nums + n);

	for (int dI = n - 1; dI >= 0; dI--) {
		LP(aI, 0, n)
		{
			if (aI == dI)
				continue;

			LP(bI, aI + 1, n)
			{
				if (bI == dI)
					continue;

				LP(cI, bI+1, n)
				{
					if (cI == dI)
						continue;

					if (nums[dI] == nums[aI] + nums[bI] + nums[cI]) {
						maxD = nums[dI];
						return;
					}
				}
			}
		}

	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d", &n)) {
		if (n == 0)
			break;

		maxD = -2000000000;
		LP(i, 0, n)
			scanf("%d", &nums[i]);

		Process();

		if (maxD < -636870912)
			printf("no solution\n");
		else
			printf("%d\n", maxD);
	}

	return 0;
}

