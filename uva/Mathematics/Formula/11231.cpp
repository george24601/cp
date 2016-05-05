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

int n, m, c;

int main() {
	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\black.in", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		scanf("%d %d %d", &n, &m, &c);

		if (n == 0 && m == 0 && c == 0)
			break;

		L total = 0;

		if (n < 8 || m < 8) {

		} else {
			L c8 = 0;
			L c9 = 0;
			if (n == 8) {
				c8 = c == 0 ? 0 : 1;
				c9 = (m >= 9 && c == 0) ? 1 : 0;
			} else {
				c8 = (n - 8 - (c == 0 ? 1 : 0)) / 2 + 1;

				if (m >= 9)
					c9 = (n - 8 - (c == 0 ? 0 : 1)) / 2 + 1;
			}

			total = (((m - 8) / 2) + 1) * c8 + (((m - 9) / 2) + 1) * c9;
		}

		printf("%lld\n", total);
	}

	return 0;
}
