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

const int MaxSize = 30010;

int winner[MaxSize];

void Precompute() {
	int lastIndex = 1;
	winner[1] = 1;

	LPE(size, 2, 30000)
	{
		int kill = 2;
		int greater = kill + lastIndex;

		if (greater <= size)
			lastIndex = greater;
		else
			lastIndex = greater - size;

		winner[size] = lastIndex;
	}
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	Precompute();
	int numCase;
	scanf("%d", &numCase);
	LPE(caseNum, 1, numCase)
	{
		int n;
		scanf("%d", &n);

		int curSize = n;

		int numRep = 0;
		while (winner[curSize] != curSize) {
			curSize = winner[curSize];
			numRep++;
		}

		printf("Case %d: %d %d\n", caseNum, numRep, curSize);
	}

	return 0;
}
