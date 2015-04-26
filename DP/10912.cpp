#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 10912 Simple Minded Hashing
//c++ test
typedef long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

#define LPE(i, a, b) \
	for (int i = int(a); i <= int(b); i++)

//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

const int NumAlpha = 26;
const int MaxVal = 351;

int total[NumAlpha + 1][NumAlpha + 1][MaxVal + 1];

void Process() {
	LPE(i, 0, NumAlpha)
	{
		LPE(j, 0, NumAlpha)
		{
			LPE(k, 0, MaxVal)
				total[i][j][k] = 0;
		}
	}

	LPE(j, 0, NumAlpha)
	{
		total[0][j][0] = 1;
	}

	LPE(i, 1, NumAlpha)
	{
		LPE(j, 1, NumAlpha)
		{
			LPE(k, 1, MaxVal)
				total[i][j][k] = total[i][j - 1][k] + (k >= j ? total[i - 1][j - 1][k - j] : 0);
		}
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Users\\George\\c1\\test\\src\\t.txt", "r", stdin);

	Process();
	int L, S;
	int caseNum = 0;
	while (true) {
		scanf("%d %d", &L, &S);

		if (L == 0 && S == 0)
			break;

		caseNum++;

		int totalNum = 0;

		if (L <= NumAlpha && S <= MaxVal) {
			totalNum += total[L][NumAlpha][S];
		}

		printf("Case %d: %d\n", caseNum, totalNum);
	}

	return 0;
}
