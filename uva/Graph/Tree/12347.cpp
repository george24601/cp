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

const int MaxN = 10010;

int nums[MaxN];
int leftC[MaxN];
int rightC[MaxN];
int n;

int Read_r(int index, int minV, int maxV) {

	int leftLength = 0;
	int leftRootIndex = index + 1;
	if (leftRootIndex < n && nums[leftRootIndex] < nums[index]
			&& nums[leftRootIndex] < maxV && nums[leftRootIndex] > minV) {
		leftLength = Read_r(leftRootIndex, minV, nums[index]);
		leftC[index] = leftRootIndex;
	} else {
		leftC[index] = index;
	}

	int rightRootIndex = index + 1 + leftLength;
	int rightLength = 0;
	if (rightRootIndex < n && nums[rightRootIndex] > nums[index]
			&& nums[rightRootIndex] < maxV && nums[rightRootIndex] > minV) {
		rightLength = Read_r(index + 1 + leftLength, nums[index], maxV);
		rightC[index] = rightRootIndex;
	} else {
		rightC[index] = index;
	}

	return 1 + leftLength + rightLength;
}

void Print_r(int index) {

	if (leftC[index] != index)
		Print_r(leftC[index]);

	if (rightC[index] != index)
		Print_r(rightC[index]);

	printf("%d\n", nums[index]);
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int num;

	n = 0;
	while (scanf("%d", &num) == 1) {
		nums[n] = num;
		n++;
	}

	Read_r(0, -INF, INF);
	Print_r(0);

	return 0;
}
