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

const int MaxN = 100010;

int n;
int a[MaxN];

int main() {
//	freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\gergovia.in", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		cin >> n;

		if (n == 0)
			break;

		LP(i, 0, n)
			scanf("%d", &a[i]);

		L totalCost = 0;
		L balance = a[0];

		LP(i, 1 , n)
		{
			totalCost += abs(balance);

			balance = balance + a[i];
		}

		printf("%lld\n", totalCost);
	}

	return 0;
}
