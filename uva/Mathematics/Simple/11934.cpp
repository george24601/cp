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

//UVa 11934 Magic Formula
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

int a, b, c, d, l;

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &l);

		if (a == 0 && b == 0 && c == 0 && d == 0 && l == 0)
			break;

		int count = 0;

		LPE(i, 0, l)
		{
			int total = a * i * i + b * i + c;

			if (total % d == 0)
				count++;
		}

		printf("%d\n", count);
	}

	return 0;
}

