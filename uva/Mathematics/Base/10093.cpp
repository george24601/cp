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

int Digit(char c) {
	if ('0' <= c && c <= '9')
		return c - '0';

	if ('A' <= c && c <= 'Z')
		return c - 'A' + 10;

	if ('a' <= c && c <= 'z')
		return c - 'a' + 36;

	return -1;
}

//N based number R is divisible by N-1 iff sum of digits is divisible by N - 1

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%s", s) == 1) {
		length = strlen(s);

		int startBase = 2;

		int total = 0;
		LP(i, 0, length)
		{
			int digitVal = Digit(s[i]);

			if (digitVal < 0)
				continue;

			startBase = Max(startBase, digitVal + 1);
			total += digitVal;
		}

		LPE(base, startBase, 62)
		{
			if (total % (base - 1) == 0) {
				printf("%d\n", base);
				goto Next;
			}
		}

		printf("such number is impossible!\n");

		Next: continue;

	}

	return 0;
}
