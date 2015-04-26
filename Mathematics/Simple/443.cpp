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

//UVa 443 Humble Numbers
//mathematics
//formula (n+1) * a1 = (n) a0 + an-1 - SUM(2, n, SUM(1, j, Cj)) - C1
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

L S, D;

const int Size = 5842;
L nums[Size];

void PreProcess() {
	L TwoB = 2000000000;
	int curIndex = 0;

	L M2 = 1;

	LP(num2, 0, TwoB)
	{
		L curMult = M2;
		if (curMult > TwoB)
			break;

		L M3 = 1;

		LP(num3, 0, TwoB)
		{
			curMult = M2 * M3;
			if (curMult > TwoB)
				break;

			L M5 = 1;
			LP (num5, 0, TwoB)
			{
				curMult = M2 * M3 * M5;
				if (curMult > TwoB)
					break;

				L M7 = 1;
				LP (num7, 0, TwoB)
				{
					curMult = M2 * M3 * M5 * M7;
					if (curMult > TwoB)
						break;

					nums[curIndex] = curMult;
					curIndex++;

					if (curIndex >= Size)
						return;

					M7 *= 7;
				}

				M5 *= 5;
			}

			M3 *= 3;

		}

		M2 *= 2;
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	PreProcess();

	sort(nums, nums + sizeof nums / sizeof nums[0]);

	while (true) {
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		if (n % 10 == 1 && n % 100 != 11)
			printf("The %dst humble number is %llu.\n", n, nums[n - 1]);
		else if (n % 10 == 2 && n % 100 != 12)
			printf("The %dnd humble number is %llu.\n", n, nums[n - 1]);
		else if (n % 10 == 3 && n % 100 != 13)
			printf("The %drd humble number is %llu.\n", n, nums[n - 1]);
		else
			printf("The %dth humble number is %llu.\n", n, nums[n - 1]);

	}

	return 0;
}

