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

//UVa 636 Sqaures
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

char s[1000];
int length;

int GetDec(int base) {
	int curBase = 1;
	int total = 0;

	for (int i = length - 1; i >= 0; i--) {
		int curDigit = curBase * (s[i] - '0');
		total += curDigit;

		curBase *= base;
	}

	return total;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%s", s);
		length = strlen(s);

		if (length == 1 && s[0] == '0')
			break;
		int startBase = 2;

		LP(i, 0, length)
			startBase = Max(startBase, (s[i] - '0') + 1);

		LP(base, startBase, 100)
		{
			int dec = GetDec(base);

			int root = (int) sqrt(dec);

			if (root * root == dec) {
				printf("%d\n", base);
				goto Next;
			}
		}

		Next: continue;

	}

	return 0;
}
