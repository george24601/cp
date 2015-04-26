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
using namespace std;

//UVa 10503 The dominoes solitaire
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
#define TwoB 2000000000;
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;

int n, m;
int endLeft;

int v1[20];
int v2[20];

bool P_r(int curIndex, int rv, int used) {
	if (curIndex == n)
		return rv == endLeft;

	LP(i, 0, m)
	{
		if (((used >> i) & 1) == 1)
			continue;

		if (v1[i] == rv) {
			bool result = P_r(curIndex + 1, v2[i], used | (1 << i));
			if (result)
				return true;
		} else if (v2[i] == rv) {
			bool result = P_r(curIndex + 1, v1[i], used | (1 << i));
			if (result)
				return true;
		} else {
			continue;
		}
	}

	return false;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;

		scanf("%d", &m);

		int temp;
		int startRight;
		scanf("%d %d", &temp, &startRight);
		scanf("%d %d", &endLeft, &temp);

		LP(i, 0, m)
			scanf("%d %d", &v1[i], &v2[i]);

		if (P_r(0, startRight, 0))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

