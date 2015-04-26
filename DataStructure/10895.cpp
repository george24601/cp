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
using namespace std;

//UVa 11550 DEMANDING DILEMMA
//graph structure

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > AL;

const int MaxSize = 1000;

int m, n;
int rowIndices[100];
int weight[100];

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d", &m, &n) == 2) {
		AL aL(n + 1);

		LPE(newCol, 1, m)
		{
			int r;
			scanf("%d", &r);

			LP(i, 0, r)
				scanf("%d", &rowIndices[i]);

			LP(i, 0, r)
				scanf("%d", &weight[i]);

			LP(i, 0, r)
				aL[rowIndices[i]].push_back(DW(newCol, weight[i]));
		}

		printf("%d %d\n", n, m);

		LPE(row, 1, n )
		{
			int numEntries = aL[row].size();
			printf("%d", numEntries);

			LP(i, 0, numEntries)
				printf(" %d", aL[row][i].first);

			printf("\n");

			if (numEntries > 0) {

				printf("%d", aL[row][0].second);

				LP(i, 1, numEntries)
					printf(" %d", aL[row][i].second);
			}

			printf("\n");
		}

	}

	return 0;
}
