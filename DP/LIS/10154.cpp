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

int const MaxSize = 6000;

PII ts[MaxSize];
int best[MaxSize];

int size;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);

	int w, s;
	size = 0;

	while (scanf("%d %d", &w, &s) == 2) {
		ts[size] = PII(s, w);
		size++;
	}

	sort(ts, ts + size);

	LP(i, 0, size)
		best[i] = INF;

	int curMax = 0;
	best[0] = 0;

	LP(i, 0, size)
	{
		for(int j = curMax; j >= 0; j--)
		{
			int tryW = best[j] + ts[i].second;

			if (tryW <= ts[i].first && tryW <= best[j + 1]) {
				best[j + 1] = tryW;
				curMax = max(curMax, j + 1);
			}
		}

	}

	printf("%d\n", curMax);

	return 0;
}
