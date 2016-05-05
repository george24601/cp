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
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

const int MaxSize = 1000000;

int m, n;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%d %d", &n, &m) == 2) {
		SAL aL(MaxSize + 1);

		LPE(i, 1, n)
		{
			int num = 0;

			scanf("%d", &num);

			aL[num].push_back(i);
		}

		LP(i, 0, m)
		{
			int q = 0;
			int occurence = 0;

			scanf("%d %d", &occurence, &q);

			int totalOcc = aL[q].size();

			if (totalOcc < occurence)
				printf("0\n");
			else
				printf("%d\n", aL[q][occurence - 1]);
		}

	}

	return 0;
}
