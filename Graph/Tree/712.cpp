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

const int MaxN = 10;

int n;
int orders[MaxN];
char values[MaxN];
char leaves[1024];

void t_r(int index, int start, int end) {
	if (start == end) {
		printf("%c", leaves[start]);
		return;
	}

	bool isT = values[orders[index]] == '1';

	if (isT)
		t_r(index + 1, (start + end) / 2 + 1, end);
	else
		t_r(index + 1, start, (start + end) / 2);
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);
	int caseNum = 0;
	while (true) {
		scanf("%d", &n);

		if (n == 0)
			break;
		caseNum++;

		LP(i, 0, n)
		{
			char buff[10];
			scanf("%s", buff);
			int id = buff[1] - '0' - 1;
			orders[i] = id;
		}

		scanf("%s", leaves);

		int runs;
		scanf("%d", &runs);

		printf("S-Tree #%d:\n", caseNum);

		LP(i, 0, runs)
		{
			scanf("%s", values);
			t_r(0, 0, pow(2, n) - 1);
		}

		printf("\n\n");

	}

	return 0;
}
