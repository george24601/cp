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

//UVa 11151 longest palindrome
//edit distance variant - string dp
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

const int MaxSize = 1001;
const int INF = 2000000000;

char f[MaxSize];

int dist[MaxSize][MaxSize];

int GetPadL(int start, int end) {

	int fLen = end - start + 1;
	int padLength = 0;

	while (fLen >= 2 * (padLength + 1)) {
		if (f[start + padLength] == f[end - padLength])
			padLength++;
		else
			break;
	}

	return padLength;
}

void Process() {
	int fLen = strlen(f);

	//len 1
	LP(i,0, fLen)
		dist[i][i] = 1;

	//len 2
	LP(i, 0, fLen -1)
	{
		if (f[i] == f[i + 1])
			dist[i][i + 1] = 2;
		else
			dist[i][i + 1] = 1;
	}

	LPE(len, 3, fLen)
	{
		for (int start = 0; start + len <= fLen; start++) {
			int end = start + len - 1;

			int left = dist[start + 1][end];
			int right = dist[start][end - 1];

			int both = dist[start + 1][end - 1];

			if (f[start] == f[end])
				both += 2;

			int candidate = Max(left, right);
			candidate = Max(candidate, both);

			dist[start][end] = candidate;

		}
	}

	printf("%d\n", dist[0][fLen - 1]);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int numCase = 0;
	scanf("%d", &numCase);

	gets(f); //newline

	LPE(caseNum, 1, numCase)
	{
		gets(f);

		if (strlen(f) == 0) {
			printf("0\n");
			continue;
		}

		Process();
	}

	return 0;
}
