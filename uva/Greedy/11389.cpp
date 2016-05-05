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
int from[MaxSize];
int to[MaxSize];

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
//	freopen("C:\\Test\\out.txt", "w", stdout);

	int n, d, r;

	while (scanf("%d %d %d", &n, &d, &r) == 3) {

		if (n == 0 && d == 0 && r == 0)
			break;

		LP(i, 0, n)
			scanf("%d", &from[i]);

		LP(i, 0, n)
			scanf("%d", &to[i]);

		LP(i, 0, n)
			from[i] = d - from[i];

		sort(from, from + n);
		sort(to, to + n);

		int total = 0;
		LP(i, 0, n)
		{
			int cur = to[i] - from[i];

			if (cur >= 0)
				total += cur;
		}

		printf("%d\n", total * r);
	}

	return 0;
}
