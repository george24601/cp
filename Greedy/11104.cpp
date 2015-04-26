#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 110;

int main() {
	//freopen("C:\\Test\\E.1.dat", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		char first[MaxN];
		scanf("%s", first);

		int fl = strlen(first);

		char second[MaxN];
		scanf("%s", second);
		int sl = strlen(second);

		if (fl == 1 && sl == 1 && first[0] == '0' && second[0] == '0')
			break;

		int longest[MaxN][MaxN];

		LP(i, 0, fl)
			memset(longest[i], 0, sizeof(longest[i]));

		longest[0][0] = first[0] == second[0] ? 1 : 0;

		LP(i, 1, fl)
		{
			if (first[i] == second[0])
				longest[i][0] = 1;

			longest[i][0] = max(longest[i][0], longest[i - 1][0]);
		}

		LP(i, 1, sl)
		{
			if (first[0] == second[i])
				longest[0][i] = 1;

			longest[0][i] = max(longest[0][i], longest[0][i - 1]);
		}

		LP(i, 1, fl)
		{
			LP(j, 1, sl)
			{
				if (first[i] == second[j])
					longest[i][j] = max(longest[i - 1][j - 1] + 1,
							longest[i][j]);

				longest[i][j] = max(longest[i][j - 1], longest[i][j]);
				longest[i][j] = max(longest[i - 1][j], longest[i][j]);
			}
		}

		int common = longest[fl - 1][sl - 1];

		int toRemove = fl - common;
		int toAdd = sl - common;
		int curFirstLength = fl;

		if (sl > fl) {
			toRemove = sl - common;
			toAdd = fl - common;
			curFirstLength = sl;
		}

		for (int degree = 1;; degree++) {
			int removedThisRound = min(toRemove, curFirstLength / 2);
			int maxAddThisRound = curFirstLength - removedThisRound;

			int addedThisRound = min(toAdd, maxAddThisRound);

			curFirstLength = curFirstLength - removedThisRound + addedThisRound;

			toRemove -= removedThisRound;
			toAdd -= addedThisRound;

			if (toRemove + toAdd == 0) {
				printf("%d\n", degree);
				break;
			}
		}

	}

	return 0;
}
