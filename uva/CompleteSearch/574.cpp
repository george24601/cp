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

//UVa 574 Sum it up
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

int t, n;

int nums[20];
int solution[20];
bool hasSol;

bool Desc(int i, int j) {
	return i > j;
}

void P_r(int curIndex, int target, int solSize) {
	if (curIndex >= n)
		return;

	int curNum = nums[curIndex];

	int numSame = 1;

	while (curIndex + numSame < n && nums[curIndex + numSame] == curNum)
		numSame++;

	//LPE(batchSize, 1, numSame){
	for (int batchSize = numSame; batchSize >= 1; batchSize--) {
		int remaining = target - batchSize * curNum;

		int newSolSize = solSize + batchSize;
		LP(solIndex, solSize, newSolSize)
			solution[solIndex] = curNum;

		if (remaining == 0) {
			hasSol = true;

			printf("%d", solution[0]);

			LP(i, 1, newSolSize)
				printf("+%d", solution[i]);

			printf("\n");

		} else if (remaining > 0) {
			P_r(curIndex + numSame, remaining, newSolSize);
		}

	}

	P_r(curIndex + numSame, target, solSize);
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d", &t, &n)) {

		if (n == 0)
			break;

		LP(i, 0 , n)
			scanf("%d", &nums[i]);

		printf("Sums of %d:\n", t);

		sort(nums, nums + n, Desc);
		hasSol = false;

		P_r(0, t, 0);

		if (hasSol)
			hasSol = false;
		else
			printf("NONE\n");

	}

	return 0;
}

