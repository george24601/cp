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

const int MaxN = 100000;

int c, n;
int mods[MaxN];
bool printed;

void Print(int start, int end) {

	if(printed)
		return;
	else
		printed = true;

	printf("%d", start + 1);

	LPE(i, start + 1, end)
		printf(" %d", i + 1);

	printf("\n");
}

int main() {
	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\halloween.in", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		scanf("%d %d", &c, &n);

		if (c == 0 && n == 0)
			break;

		memset(mods, -1, sizeof(mods));
		printed = false;

		L total = 0;
		LP(i, 0, n)
		{
			int curNum;
			scanf("%d", &curNum);

			total += curNum;

			int curMode = total % c;

			if(curMode == 0)
			{
				Print(0, i);
			}else if(mods[curMode] >= 0)
			{
				Print(mods[curMode] + 1, i);
			}else
			{
				mods[curMode] = i;
			}
		}
	}

	return 0;
}
