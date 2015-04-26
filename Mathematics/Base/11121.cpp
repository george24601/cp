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

int digits [100];
int size;

void ToB1(int dec) {

	if (dec == 0) {
		digits[size] = 0;
		size++;
		return;
	}

	int num = dec;
	int curUnit = 1;

	while (num != 0) {

		int digit = 0;

		int absNum = abs(num);
		int absUnit = abs(curUnit);

		if ((absNum & absUnit) == absUnit)
			digit = 1;

		num = num - (digit * curUnit);

		digits[size] = digit;

		size++;
		curUnit *= -2;
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;

	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		int num;
		scanf("%d", &num);

		size = 0;

		ToB1(num);

		printf("Case #%d: ", caseNum);

		for (int i = size - 1; i >= 0; i--)
			printf("%d", digits[i]);

		printf("\n");
	}

	return 0;
}
