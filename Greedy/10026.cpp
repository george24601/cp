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
#define INF 2000000000
#define Ep 1e-9

int const MaxSize = 1001;
int t[MaxSize];
int s[MaxSize];
int n;
int order[MaxSize];

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	int caseNum;

	scanf("%d", &caseNum);

	LPE(cn, 1, caseNum)
	{
		if (cn > 1)
			printf("\n");

		scanf("%d", &n);

		LP(i, 0, n)
		{
			scanf("%d %d", &t[i], &s[i]);
			order[i] = i;
		}

		LP(i, 1, n)
		{
			int curItem = order[i];
			int curIndex = i;

			while (curIndex > 0) {
				int prevItem = order[curIndex - 1];

				int prevVal = t[prevItem] * s[curItem];
				int curVal = t[curItem] * s[prevItem];

				if (prevVal < curVal
						|| (prevVal == curVal && prevItem < curItem))
					break;
				else {
					order[curIndex - 1] = curItem;
					order[curIndex] = prevItem;
					curIndex = curIndex - 1;
				}
			}
		}

		printf("%d", order[0] + 1);

		LP(i, 1, n)
			printf(" %d", order[i] + 1);

		printf("\n");

	}

	return 0;
}
