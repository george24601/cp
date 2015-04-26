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
using namespace std;

//UVa 10515 Power et all
//cycle finding
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

char nBuff[200];
int nLength;
int mDigit;

int modCache[10][11];

int P_r(int lastDigit, int nIndex) {
	if (nIndex >= nLength)
		return lastDigit;

	int nDigit = nBuff[nIndex] - '0';

	int updated = (modCache[lastDigit][10] * modCache[mDigit][nDigit]) % 10;

	return P_r(updated, nIndex + 1);
}

void PopCache() {
	LPE(pow, 0, 10)
		modCache[0][pow] = 0;

	LPE(digit, 1, 9)
		modCache[digit][0] = 1;

	LPE(digit, 1, 9)
	{
		LPE(p, 1, 10)
			modCache[digit][p] = (modCache[digit][p - 1] * digit) % 10;
	}
}

int main(int argc, const char * argv[]) {

//freopen("C:\\Test\\Test.txt", "r", stdin);

	PopCache();
	while (true) {

		char mBuff[200];
		scanf("%s %s", mBuff, nBuff);

		nLength = strlen(nBuff);
		int mLength = strlen(mBuff);

		int firstDinN = nBuff[0] - '0';
		mDigit = mBuff[mLength - 1] - '0';

		if (nLength == 1 && mLength == 1 && mDigit == 0 && firstDinN == 0)
			break;

		int digit;

		if(nLength == 1 && firstDinN == 0)
		{
			digit = 1;

		}else
		{
			digit= P_r(modCache[mDigit][firstDinN], 1);
		}

		printf("%d\n", digit);

	}

	return 0;
}
