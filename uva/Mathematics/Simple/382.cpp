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

const int MaxN = 25;

int n;
vector<int> blocks[MaxN];

int Calc(int num) {
	if(num == 1)
		return 0;

	int total = 1;

	int maxDiv = sqrt(num);

	LPE(div, 2, maxDiv)
	{
		if(num % div != 0)
			continue;

		int c = num/div;

		if(c == 1)
			continue;

		if(c == div)
		{
			total += div;
			break;
		}else
		{
			total += div;
			total += c;
		}
	}

	return total;
}

int main() {
	//freopen("C:\\Test\\test.txt", "r", stdin);

	int num;

	printf("PERFECTION OUTPUT\n");

	while (true) {
		scanf("%d", &num);

		if (num == 0)
			break;

		int result = Calc(num);

		if (num < 10000)
			printf(" ");
		if (num < 1000)
			printf(" ");
		if (num < 100)
			printf(" ");
		if (num < 10)
			printf(" ");

		printf("%d  ", num);

		if (num > result)
			printf("DEFICIENT\n");
		else if (num < result)
			printf("ABUNDANT\n");
		else
			printf("PERFECT\n");
	}

	printf("END OF OUTPUT\n");

	return 0;
}
