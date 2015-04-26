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

//UVa 11461 square numbers
//mathematics
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int a, b;
	while (scanf("%d %d", &a, &b) == 2) {

		if(a == 0 && b == 0)
			break;

		int lteA = sqrt(a);
		int lteB = sqrt(b);

		if (lteA * lteA == a)
			printf("%d\n", lteB - lteA + 1);
		else
			printf("%d\n", lteB - lteA);
	}

	return 0;
}

