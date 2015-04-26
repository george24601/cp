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

int const MaxSize = 100010;

int nums[MaxSize];
int n, m;

bool possible(int dist)
{
	int segCount = 0;

	int startIndex = 0;

	while(segCount < m && startIndex < n)
	{
		int endDist = nums[startIndex] + dist;

		int nextStart = startIndex;

		while(nextStart < n && nums[nextStart] <= endDist)
			nextStart++;

		startIndex = nextStart;
		segCount++;
	}

	return startIndex == n;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\B.1.dat", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%d %d", &m, &n);

		LP(i, 0, n)
			scanf("%d", &nums[i]);

		sort(nums, nums + n);

		int ans = 1 << 20;
		int curDigit = 1 << 20;

		while(curDigit > 0)
		{
			if(possible(ans-curDigit))
				ans -= curDigit;

			curDigit = curDigit/2;
		}

		printf("%.1lf\n", ans/ 2.0);
	}

	return 0;
}
