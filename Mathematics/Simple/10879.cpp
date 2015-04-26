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

//UVa 10879 Code Refactoring
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

int K;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LP(i, 0, numCase)
	{
		scanf("%d", &K);

		int first = 2;
		for (; first < K; first++) {
			if (K % first == 0)
				break;
		}

		int second = first + 1;

		for (; second < K; second++) {
			if (K % second == 0)
				break;
		}

		printf("Case #%d: %d = %d * %d = %d * %d\n", i + 1, K, first, K / first,
				second, K / second);
	}

	return 0;
}

