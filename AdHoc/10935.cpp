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

//UVa 10935 Throwing cards aways I
//ad hoc

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

void P_r(int size) {
	if (size == 1)
		return;

	int cp[100];

	LP(i, 0, size)
		cp[i] = remaining[i];

	int curDiscardIndex = n - size;
	for (int i = 0; i < size; i += 2) {
		discarded[curDiscardIndex] = remaining[i];
		curDiscardIndex++;
	}

	int startIndex = 0;
	if (size % 2 == 1) {
		remaining[0] = cp[size - 1];
		startIndex = 1;
	}

	for (int i = 1; i < size; i += 2) {
		remaining[startIndex] = cp[i];
		startIndex++;
	}

	P_r((size + 1) / 2);
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {

		scanf("%d", &n);
		if (n == 0)
			break;

		LP(i, 0, n)
			remaining[i] = i + 1;

		P_r(n);

		if (n == 1)
			printf("Discarded cards:");
		else
			printf("Discarded cards: %d", discarded[0]);

		LP(i, 1, n - 1)
			printf(", %d", discarded[i]);

		printf("\n");

		printf("Remaining card: %d\n", remaining[0]);
	}

	return 0;
}

