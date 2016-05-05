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

int const MaxSize = 20;

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\A.1.dat", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);


	bool isFirst = true;
	while (true) {
		int n;
		scanf("%d", &n);
		if (0 == n)
			break;

		if(isFirst)
			isFirst = false;
		else
			printf("\n");

		int nums[10010];
		LP(i, 0, n)
			scanf("%d", &nums[i]);

		sort(nums, nums + n);

		int maxBand = 0;

		for (int i = 0; i < n;) {
			int currentBand = 1;

			for (int j = i + 1; j < n; j++) {
				if (nums[i] == nums[j])
					currentBand++;
				else
					break;
			}

			maxBand = max(maxBand, currentBand);

			i += currentBand;
		}

		printf("%d\n", maxBand);
		for (int i = 0; i < maxBand; i++) {
			printf("%d", nums[i]);

			for (int j = i + maxBand; j < n; j += maxBand)
				printf(" %d", nums[j]);

			printf("\n");
		}
	}

	return 0;
}
