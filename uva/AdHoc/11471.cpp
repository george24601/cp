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
using namespace std;

//UVa 11470 Square Sums
//ad hoc
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

int n;
int maxStart;

const int MaxSize = 10;

int pixel[MaxSize][MaxSize];

void P_r(int start) {

	if (start > maxStart)
		return;
	else if (start == maxStart && (n % 2 == 1)) {
		printf(" %d", pixel[start][start]);
		return;
	}

	int sum = 0;

	LP(i, start, n - start)
	{
		sum += pixel[start][i];
		sum += pixel[i][start];
		sum += pixel[n - start - 1][i];
		sum += pixel[i][n - start - 1];
	}

	sum -= pixel[start][start];
	sum -= pixel[start][n - start - 1];
	sum -= pixel[n - start - 1][start];
	sum -= pixel[n - start - 1][n - start - 1];

	printf(" %d", sum);

	P_r(start + 1);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {
		scanf("%d", &n);

		if (n == 0)
			break;

		caseNum++;

		LP(row, 0, n)
		{
			LP(col, 0, n)
				scanf("%d", &pixel[row][col]);
		}

		printf("Case %d:", caseNum);

		maxStart = n % 2 == 0 ? ((n / 2) - 1) : ((n - 1) / 2);
		P_r(0);

		printf("\n");
	}

	return 0;
}

