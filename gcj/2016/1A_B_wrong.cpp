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
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-9

/*
 consider only 2 row case, i.e., with 3 lists

 top left is smallest => so we can find the first row and first col, doesnt matter which is which => it is transpose anyway
 find 2nd row =>
 suppose none are missing
 find the smallest 2nd element, fill in the blank, if there is only 1 list that is smallest, we know which one is missing
 => always fill row first, col second

 LP(pivot, 0, N){
 //look for smallest pivot
 //keep the first 2 pivot position

 use the first one to fill row

 if(second one exists)
 use the second one to fill col
 else
 mark second one as missing assert(only 1 can be missing)
 }

 print missing one





 */

int N;
int const MaxN = 100;
int input[MaxN][MaxN];
int res[MaxN][MaxN];
bool used[MaxN];

bool canPopRow(int pivot, int firstI) {
	LP(i, 0, pivot){
		if(res[pivot][i] == -1)
			continue;//free var

		if(res[pivot][i] != input[firstI][i])
			return false;
	}

	return true;
}

void p() {
	int missingI = -1;
	bool isRowMissing = true;

	int lN = 2 * N - 1;

	LP(pivot, 0, N)
	{
		int curMin = INF;
		int firstI = -1;
		int secondI = -1;

		LP(i, 0, lN)
		{
			if (used[i])
				continue;

			int pV = input[i][pivot];
			//printf("%d\n", pV);
			if (pV < curMin) {
				firstI = i;
				secondI = -1;
				curMin = pV;
			} else if (pV == curMin) {
				secondI = i;
			}
		}

	//	printf("%d %d %d %d\n", pivot, curMin, firstI, secondI);
		used[firstI] = true;

		bool canFirstToRow = canPopRow(pivot, firstI);

		LP(i, 0, N)
		{
			if (canFirstToRow)
				res[pivot][i] = input[firstI][i];
			else{
				//assert(-1 == res[i][pivot]
				//					|| res[i][pivot] == input[firstI][i]);
				res[i][pivot] = input[firstI][i];
			}
		}

		if (secondI < 0) {
			assert(missingI < 0);
			missingI = pivot;
			isRowMissing = !canFirstToRow;
		} else {
			used[secondI] = true;

			LP(i, 0, N)
			{
				if (canFirstToRow) {
					//assert(-1 == res[i][pivot]
					//				|| res[i][pivot] == input[secondI][i]);
					res[i][pivot] = input[secondI][i];
				} else {
					//assert(-1 == res[pivot][i]
					//				|| res[pivot][i] == input[secondI][i]);
					res[pivot][i] = input[secondI][i];
				}
			}
		}

		/*
		LP(i, 0, N)
		{
			 LP(j, 0, N){
			 printf(" %d", res[i][j]);
			 }
			 printf("\n");
		}

		 printf("\n");
		 */
	}

	assert(missingI >= 0);

	LP(i, 0, N)
	{


		if (isRowMissing) {
			printf(" %d", res[missingI][i]);
		} else {
			printf(" %d", res[i][missingI]);
		}
	}

	printf("\n");
}

int main() {
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/B-small-attempt0.in", "r", stdin);
	freopen("/Users/georgeli/B_small.out", "w", stdout);

	int T;

	scanf("%d", &T);

	//cout << T << endl;

	LPE(cn, 1, T)
	{
		scanf("%d", &N);

		memset(used, false, sizeof(used));

		LP(i, 0, (2 * N - 1))
		{
			memset(input[i], -1, sizeof(input[i]));
			memset(res[i], -1, sizeof(res[i]));

			LP(j, 0, N)
			{
				scanf("%d", &input[i][j]);
			//	printf("%d ", input[i][j]);
			}

		//	printf("\n");
		}

		printf("Case #%d:", cn);
		p();
	}

	return 0;
}
