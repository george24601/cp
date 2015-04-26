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

int const MaxSize = 10000;

L ans[MaxSize + 1];

int Full(int n) {
	L ans, toDelete;
	ans = toDelete = 1 << 16;

	while (toDelete > 0) {
		L deleted = ans - toDelete;
		if (deleted > 0 && (deleted * deleted) >= n)
			ans = deleted;

		toDelete /= 2;
	}

	return ans - 1;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);

	int n;

	while (scanf("%d", &n) == 1) {
		if (n == 0)
			break;

		int x, y;
		int lastComplete = Full(n);

		int remaining = n - lastComplete * lastComplete;

		remaining -= 1;

		if(remaining <= lastComplete)
		{
			x = remaining + 1;
			y = lastComplete + 1;
			goto Print;
		}

		remaining  -= lastComplete;

		x = lastComplete + 1;
		y = lastComplete + 1 - remaining;


		Print: if (lastComplete % 2)
			printf("%d %d\n", x, y);
		else
			printf("%d %d\n", y, x);
	}

	return 0;
}
