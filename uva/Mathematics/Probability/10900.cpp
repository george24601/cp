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

int const MaxSize = 15;
int n;
double t;

double E(int r) {
	if (r == n + 1)
		return pow(2, n);

	double r1 = E(r + 1);
	double goExpected = (1 + t) * r1 /2;

	double pg = pow(2, r - 1) / r1;

	if (pg < t) {
		return goExpected;
	} else {
		double go = (1 - pg) / (1 - t);

		return go * (1 + pg) * r1 /2 + (1 - go) * pow(2, r - 1);
	}

}
int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\A.2.dat", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {

		scanf("%d %lf", &n, &t);

		if (n == 0 && t == 0)
			break;

		double result = E(1);
		printf("%.3lf\n", result);

	}

	return 0;
}
