#include <iostream>
#include <sstream>
#include <stdio.h>
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
#include <string>
using namespace std;

typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 10000;

int nums[MaxN];
int size;

void Swap(int ia, int ib) {
	int temp = nums[ia];
	nums[ia] = nums[ib];
	nums[ib] = temp;
}

void Pivot() {
	int curIndex = size - 1;

	while (curIndex > 0) {
		if (nums[curIndex] >= nums[curIndex - 1])
			break;

		Swap(curIndex, curIndex - 1);
		curIndex--;
	}

}

int main() {
	//freopen("C:\\Test\\test.txt", "r", stdin);

	int x;
	size = 0;

	while (scanf("%d", &x) == 1) {
		nums[size] = x;
		size++;

		Pivot();

		if ((size % 2) == 0)
			printf("%d\n", (nums[size / 2] + nums[size / 2 - 1]) / 2);
		else
			printf("%d\n", nums[size / 2]);

	}

	return 0;
}
