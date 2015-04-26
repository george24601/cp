#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

//UVa 11258 String Partition
//MCM => general D&C DP
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int MaxSize = 201;
const int INF = 2000000000;

char f[MaxSize];

int num[MaxSize][11];
L dist[MaxSize][MaxSize];
const L MaxInt = 2147483647;

void Process() {
	int fLen = strlen(f);

	//len 1
	LP(i,0, fLen)
		dist[i][i] = num[i][0];

	LPE(len, 2, fLen)
	{
		for (int start = 0; start + len <= fLen; start++) {
			int end = start + len - 1;

			L curMax = 0;

			//partition
			LP(cutOff, start, end)
			{
				L leftCost = dist[start][cutOff];
				L rightCost = dist[cutOff + 1][end];

				L newCost = leftCost + rightCost;

				curMax = Max(curMax, newCost);

			}

			//no partition
			if (len <= 10) {
				int noPart = num[start][len - 1];

				if (noPart >= 0)
				{
					L noPartVal = noPart;
					curMax = Max(curMax, noPartVal);
				}
			}

			dist[start][end] = curMax;
		}
	}

	printf("%llu\n", dist[0][fLen - 1]);
}

void Preprocess() {
	int fLen = strlen(f);

	//len 1
	LP(i,0, fLen)
	{
		int val = (f[i] - '0');
		num[i][0] = val;
	}

	//len 2
	LP(i,0, fLen - 1)
	{
		if(num[i][0] == 0)
			num[i][1] = -1;
		else
			num[i][1] = (num[i][0] * 10) + (num[i + 1][0]);
	}

	//len 3
	LPE(len, 3, 10)
	{
		for (int start = 0; start + len <= fLen; start++) {
			int end = start + len -1;

			int lastNum = num[start][len - 2];

			if(lastNum < 0)
			{
				num[start][len - 1] = -1;
			}else
			{
				L newNum =  lastNum;
				newNum = newNum * 10 + num[end][0];

				if(newNum > MaxInt)
					num[start][len - 1] = -1;
				else
					num[start][len - 1] = newNum;
			}

		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase = 0;
	scanf("%d", &numCase);

	LPE(caseNum, 1, numCase)
	{
		scanf("%s", f);

		Preprocess();
		Process();
	}

	return 0;
}
