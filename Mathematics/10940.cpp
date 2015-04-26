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

//UVa 10940 Throwing cards aways II
//mathematics

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int n;
int discarded[100];
int remaining[100];

int main(int argc, const char * argv[]) {

	freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {

		scanf("%d", &n);
		if (n == 0)
			break;

		if (n == 1) {
			printf("1\n");
			continue;
		}

		int counter = 1;

		int pastSum = 1;
		while (pow(2, counter + 1) < n) {

			counter++;
			pastSum = pow(2, counter);
		}

		int result = (n - pastSum) * 2;
		printf("%d\n", result);
	}

	return 0;
}

