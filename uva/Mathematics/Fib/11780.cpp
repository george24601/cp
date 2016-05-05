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

//UVa 11780 Miles 2KM
//DP
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

const int MaxSize = 1001;
int B[MaxSize];
int E[MaxSize];

void PopB() {
	int first = 0;
	int second = 1;

	while (true) {
		int next = first + second;

		for (int i = second; i < next && i < MaxSize; i++)
			B[i] = next;

		if (next > MaxSize) {
			break;
		} else {
			first = second;
			second = next;
		}
	}
}

void PreProcess() {
	memset(B, 0, sizeof(B));
	memset(E, 0, sizeof(E));

	PopB();

	E[0] = 0;
	E[1] = B[1];

	LP(mile, 2, MaxSize)
	{
		double minDiff = -1;
		LP(firstPart, 0, mile)
		{
			int newEst = E[firstPart] + B[mile - firstPart];

			double diff = abs((mile * 1.6) - newEst);

			if (minDiff < 0 || diff < minDiff) {
				minDiff = diff;
				E[mile] = newEst;
			}
		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	PreProcess();

	while (true) {
		int num;
		scanf("%d", &num);

		if (num == 0)
			break;

		double diff = abs((double) E[num] - num * 1.6);

		printf("%.2lf\n", diff);

	}

	return 0;
}
