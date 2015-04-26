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
#include <stack>
#include <queue>
using namespace std;

//UVa 10931 Parity
//Mathematics - base number
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define Ep 1e-9

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	L num;

	while (true) {
		scanf("%llu", &num);

		if (num == 0)
			break;

		bool IsOne[100];
		memset(IsOne, false, sizeof(IsOne));
		int total = 0;

		int curIndex = 0;

		while (num != 0) {
			if ((num & 1) == 1) {
				total++;
				IsOne[curIndex] = true;
			}

			curIndex++;
			num = (num >> 1);
		}

		printf("The parity of ");

		for (int i = curIndex - 1; i >= 0; i--) {
			if (IsOne[i])
				printf("1");
			else
				printf("0");
		}

		printf(" is %d (mod 2).\n", total);
	}

	return 0;
}
