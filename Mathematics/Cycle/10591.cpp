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

//UVa 10591 Happy number
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
int num;

const int MaxSize = 10000;

bool encountered[MaxSize];

int Calc(int curNum) {
	if (curNum < 10)
		return curNum * curNum;
	else {
		int lastDigit = curNum % 10;

		return lastDigit * lastDigit + Calc(curNum / 10);
	}
}

bool P_r(int curNum) {

	if (curNum == 1)
		return true;
	else if (encountered[curNum])
		return false;
	else
		encountered[curNum] = true;

	return P_r(Calc(curNum));
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%d", &num);

		memset(encountered, false, sizeof(encountered));

		if (P_r(Calc(num)))
			printf("Case #%d: %d is a Happy number.\n", caseNum, num);
		else
			printf("Case #%d: %d is an Unhappy number.\n", caseNum, num);
	}

	return 0;
}
