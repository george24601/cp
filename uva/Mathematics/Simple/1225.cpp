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
using namespace std;

//UVa 1226 Digit Counting
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

const int MaxSize = 2000000;

int counts[10];
int N;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LP(i, 0, numCase)
	{
		memset(counts, 0, sizeof(counts));
		scanf("%d", &N);

		LPE(num,1, N)
		{
			int curNum = num;
			while (curNum > 0) {
				counts[curNum % 10]++;

				curNum = curNum / 10;
			}
		}

		LP(i, 0, 9)
			printf("%d ", counts[i]);

		printf("%d\n", counts[9]);
	}

	return 0;
}

