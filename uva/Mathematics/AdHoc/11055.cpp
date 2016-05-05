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

const int MaxN = 1010;

int n;
int a[MaxN][MaxN];

int main() {
	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\homogeneous.in", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		cin >> n;

		if (n == 0)
			break;

		LP(i, 0, n)
			LP(j, 0, n)
				scanf("%d", &a[i][j]);

		int diff[n];
		memset(diff, 0, sizeof(diff[n]));

		diff[0] = 0;

		LP(i, 1, n)
			diff[i] = a[0][i] - a[0][i - 1];

		LP(i, 1, n)
		{
			LP(j, 1, n)
			{

				if (a[i][j] - a[i][j - 1] != diff[j])
					goto Bad;

			}

		}

		printf("homogeneous\n");
		continue;
		Bad: printf("not homogeneous\n");
	}

	return 0;
}
