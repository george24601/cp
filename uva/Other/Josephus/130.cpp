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
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxSize = 110;

int state[MaxSize][MaxSize];

int size, k;

int Round(int i, int n) {
	return (i - 1 + n) % n + 1;
}

int C(int from, int diff, int n, int black) {

	int to = from + diff;

	if (Round(to, n) == black)
		return Round(black + 1, n);

	if (to <= n) {
		if (from < black && black < to)
			return Round(to + 1, n);
		else
			return Round(to, n);
	} else {
		if (from > black && black > Round(to, n))
			return Round(to, n);
		else
			return Round(to + 1, n);
	}
}

int Dist(int one, int to, int n, int black) {
	if (one == to)
		return 0;

	if (one < to) {
		int toR = to - one;

		if (one < black && black < to)
			toR -= 1;

		return toR;
	} else {
		int toR = to - one + n;

		if (to < black && black < one)
			return toR;
		else
			return toR - 1;
	}
}

int T(int p, int n, int firstStop) {

	int secondStop = C(Round(firstStop + 1, n), (k - 1) % (n - 1), n,
			firstStop);

	int newOneFrom = Round(firstStop + 1, n);

	if(newOneFrom == secondStop)
		newOneFrom = Round(newOneFrom + 1, n);

	if (p == secondStop) {
		if (firstStop > newOneFrom) {
			if (newOneFrom < secondStop && secondStop < firstStop)
				return firstStop - newOneFrom;
			else
				return firstStop - newOneFrom + 1;
		} else {
			if (firstStop < secondStop && secondStop < newOneFrom)
				return firstStop - newOneFrom + n + 1;
			else
				return firstStop - newOneFrom + n;
		}
	} else
		return Dist(newOneFrom, p, n, secondStop) + 1;

}

int DP_r(int p, int n) {
	if (state[p][n] != 0)
		return state[p][n];

	int firstStop = Round(k, n);
	if (n == 1) {
		state[1][1] = 2;
	} else if (n == 2) {
		state[1][2] = k % 2 == 0 ? 2 : 1;
		state[2][2] = k % 2 == 0 ? 1 : 2;
	} else if (p == firstStop) {
		state[p][n] = 1;
	} else {
		int smallerIndex = T(p, n, firstStop);
		state[p][n] = DP_r(smallerIndex, n - 1);
	}

	return state[p][n];
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d %d", &size, &k);

		if (size == 0 && k == 0)
			break;

		LPE(i, 1, size)
			memset(state[i], 0, sizeof(state[i]));

		if (size == 1) {
			printf("%d\n", 1);
			continue;
		}

		LPE(p, 1, size)
		{
			int result = DP_r(p, size);

			if (result != 2)
				continue;

			int start = Round(2 - p, size);

			printf("%d\n", start);
			break;
		}

	}

	return 0;
}
