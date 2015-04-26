#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 11742: social constraints
//complete search

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

int n, m;
int first[20];
int second[20];
int dist[20];
int arr[8];

L total;

void Process(int curIndex, int used) {

	if (curIndex >= n) {
		total++;
		return;
	}

	LP(toUse, 0, n)
	{
		if ((used >> toUse) & 1 == 1)
			continue;

		LP(rule, 0, m)
		{
			int target = -1;

			if (first[rule] == toUse)
				target = second[rule];
			else if (second[rule] == toUse)
				target = first[rule];
			else
				continue;

			if ((used >> target) & 1 != 1)
				continue;

			int checkDis = dist[rule];

			LPE(pos, 0, curIndex - 1)
			{
				if (arr[pos] != target)
					continue;

				if (checkDis > 0 && abs(pos - curIndex) > checkDis)
					goto Bad;

				if (checkDis < 0 && abs(pos - curIndex) < -1 * checkDis)
					goto Bad;
			}

		}

		arr[curIndex] = toUse;

		Process(curIndex + 1, used | (1 << toUse));

		Bad: continue;
	}
}

int main(int argc, const char * argv[]) {

	///freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d %d", &n, &m);

		if (n == 0 && m == 0)
			break;

		LP(i, 0, m)
			scanf("%d %d %d", &first[i], &second[i], &dist[i]);

		total = 0;
		Process(0, 0);

		printf("%llu\n", total);
	}

	return 0;
}
