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

int main() {
	//freopen("C:\\Test\\test.txt", "r", stdin);

	int H, M;
	while(true)
	{
		scanf("%d:%d", &H, &M);

		if(H == 0 && M ==0)
			break;

		double hDegree = H *30 + (M/2.0);
		double mDegree = M * 6;

		double diff = max(hDegree, mDegree) - min(hDegree, mDegree);
		if(diff > 180)
			diff = 360 - diff;

		printf("%.3lf\n", diff);
	}

	return 0;
}
