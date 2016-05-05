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
using namespace std;

typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define Ep 1e-9

int const MaxSize = 2000;

int nums[MaxSize];
int n;

int lis[MaxSize]; //LIS ending at index
int lds[MaxSize];

void CLIS() {

	for (int i = n - 1; i >= 0; i--) {
		lds[i] = 1;
		lis[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (nums[j] > nums[i])
				lds[i] = max(lds[i], lds[j] + 1);

			if (nums[j] < nums[i])
				lis[i] = max(lis[i], lis[j] + 1);
		}
	}

}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\A.4.dat", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%d", &n);

		LP(i, 0, n)
			scanf("%d", &nums[i]);

		CLIS();
		int curMax = 0;
		LP(i, 0, n)
			curMax = max(curMax, lds[i] + lis[i] - 1);	//remove dup

		printf("%d\n", curMax);
	}

	return 0;
}
