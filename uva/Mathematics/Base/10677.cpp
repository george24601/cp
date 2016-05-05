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

int B1, B2, r1, r2;

int ToB2(vector<int> b1Digits) {
	int total = 0;
	int baseD = 1;

	LP(i, 0, b1Digits.size())
	{
		total += baseD * b1Digits[i];

		baseD *= B2;
	}

	return total;
}

void ToB1(int dec, vector<int>& digits) {
	int num = dec;

	while (num != 0) {
		digits.push_back(num % B1);
		num = num / B1;
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;

	scanf("%d", &numCase);

	LP(caseNum, 0, numCase)
	{
		scanf("%d %d %d %d", &B1, &B2, &r1, &r2);

		for (int num = r2 - 1; num > r1; num--) {
			vector<int> b1Digits;

			ToB1(num, b1Digits);

			L b2Value = ToB2(b1Digits);

			if (b2Value % num == 0) {
				printf("%d\n", num);
				goto Next;
			}

		}

		printf("Non-existent.\n");
		Next: continue;
	}

	return 0;
}
