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

//UVa 10354 avoiding your boss
//SSSP
typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 53;

char pre[MaxN], in[MaxN];
int leftC[MaxN];
int rightC[MaxN];
int n;

int Read_r(int ps, int length, int is) {
	if (1 == length)
		return ps;

	int rootIndex = ps;

	int inRootIndex = is;
	int leftLeng = 0;

	while (in[inRootIndex] != pre[rootIndex]) {
		inRootIndex++;
		leftLeng++;
	}

	if (0 < leftLeng)
		leftC[rootIndex] = Read_r(ps + 1, leftLeng, is);

	int rightLeng = length - leftLeng - 1;

	if (0 < rightLeng)
		rightC[rootIndex] = Read_r(ps + leftLeng + 1, rightLeng,
				is + 1 + leftLeng);

	return ps;
}

void Print_r(int index) {

	if (leftC[index] != index)
		Print_r(leftC[index]);

	if (rightC[index] != index)
		Print_r(rightC[index]);

	printf("%c", pre[index]);
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%s %s", pre, in) == 2) {

		n = strlen(pre);
		LP(i,0, n)
		{
			leftC[i] = i;
			rightC[i] = i;
		}

		Read_r(0, n, 0);

		Print_r(0);
		printf("\n");
	}

	return 0;
}
