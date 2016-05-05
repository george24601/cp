#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 11489 integer game
//game theory

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 1000;

bool Process_r(int Z, int O, int T) {

	if (Z + O + T == 1)
		return true;

	if (O == T)
		return Z % 2 == 1;

	if (O > T) {
		int diff = O - T;

		if (diff % 3 == 0) {
			return Z % 2 == 1;

		} else if (diff % 3 == 1) {

			return O > 0 && !Process_r(Z, O - 1, T);
		} else {
			return T > 0 && !Process_r(Z, O, T - 1);
		}

	} else {
		int diff = T - O;

		if (diff % 3 == 0) {
			return Z % 2 == 1;

		} else if (diff % 3 == 2) {

			return O > 0 && !Process_r(Z, O - 1, T);
		} else {
			return T > 0 && !Process_r(Z, O, T - 1);
		}
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	char s[2000];
	LPE(caseN, 1, t)
	{
		scanf("%s", &s);
		int Z = 0, O = 0, T = 0;

		int length = strlen(s);

		LP(i, 0, length)
		{
			int mod = (s[i] - '0') % 3;

			if (mod == 0)
				Z++;
			else if (mod == 1)
				O++;
			else
				T++;
		}

		bool result = Process_r(Z, O, T);

		if (result)
			printf("Case %d: S\n", caseN);
		else
			printf("Case %d: T\n", caseN);
	}

	return 0;
}
