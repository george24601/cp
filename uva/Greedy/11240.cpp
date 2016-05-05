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

typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> FT;
#define Ep 1e-9

int const MaxSize = 30010;
int n;
int ind[MaxSize];

int W_l(int s, int e, int curMin) {
	if (s == e)
		return 1;

	int localMin = curMin;
	int minIndex = ind[localMin];

	while (minIndex < s || minIndex > e) {
		localMin++;
		minIndex = ind[localMin];
	}

	if (minIndex == s) {
		return W_l(s + 1, e, localMin + 1);

	} else if (minIndex == e) {
		return W_l(s, e - 1, localMin + 1);

	} else {
		return W_l(s, minIndex - 1, localMin + 1) + 1
				+ W_l(minIndex + 1, e, localMin + 1);
	}
}

int RU_l(int s, int e, int curMin) {
	if (s == e)
		return 1;

	int localMin = curMin;
	int minIndex = ind[localMin];

	while (minIndex < s || minIndex > e) {
		localMin++;
		minIndex = ind[localMin];
	}

	if (minIndex == s) {
		return RU_l(s + 1, e, localMin + 1);

	} else if (minIndex == e) {
		return W_l(s, e - 1, localMin + 1) + 1;

	} else {
		return W_l(s, minIndex - 1, localMin + 1) + 1
				+ RU_l(minIndex + 1, e, localMin + 1);
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\B.1.dat", "r", stdin);
	//freopen("C:\\Test\\out", "w", stdout);

	int nC;
	scanf("%d", &nC);

	LPE(cn, 1, nC)
	{
		scanf("%d", &n);

		LPE(i, 1, n)
		{
			int num;
			scanf("%d", &num);
			ind[num] = i;
		}

		int result = RU_l(1, n, 1);
		printf("%d\n", result);
	}

	return 0;
}
