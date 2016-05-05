#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 10465 Homer Simpson
//c++ test
typedef long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

#define LPE(i, a, b) \
	for (int i = int(a); i <= int(b); i++)

//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

const int MaxVal = 10000;

int total[MaxVal + 1];
int m, n, t;

int Max(int a, int b) {
	return a > b ? a : b;
}

void Process() {
	total[0] = 0;

	LPE(i, 1, t)
	{
		if (i >= m && total[i - m] >= 0)
			total[i] = max(total[i], total[i - m] + 1);

		if (i >= n && total[i - n] >= 0)
			total[i] = max(total[i], total[i - n] + 1);
	}

	if (total[t] >= 0) {
		printf("%d\n", total[t]);
	} else {
		for (int i = t; i >= 0; i--) {
			if (total[i] >= 0) {
				printf("%d %d\n", total[i], t - i);
				break;
			}

		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Users\\George\\c1\\test\\src\\t.txt", "r", stdin);

	while (scanf("%d %d %d", &m, &n, &t) == 3) {
		LPE(i, 0, t)
			total[i] = -1;

		Process();

	}

	return 0;
}
