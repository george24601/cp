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

//UVa 694 The Collatz Sequence
//mathematics
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int c;
L l;

void P_r(L cur) {
	c++;

	if (cur == 1)
		return;

	if (cur % 2 == 0)
		P_r(cur / 2);
	else {
		L nextVal = (3 * cur + 1);

		if (nextVal <= l)
			P_r(nextVal);
	}

}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {
		int A, limit;
		scanf("%d %d", &A, &limit);

		if (A < 0 && limit < 0)
			break;
		l = limit;

		caseNum++;

		c = 0;

		P_r(A);

		printf("Case %d: A = %d, limit = %d, number of terms = %d\n", caseNum,
				A, limit, c);

	}

	return 0;
}

