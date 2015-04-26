#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 11420 Chest of drawers
//DP
typedef unsigned long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

#define LPE(i, a, b) \
	for (int i = int(a); i <= int(b); i++)

#define Min(a ,b ) a < b ? a : b

const int MaxVal = 65;

L total[MaxVal + 1][MaxVal + 1];

void Process() {
	LPE(n, 0, MaxVal)
	{
		LPE(s, 0, n)
			total[n][s] = 0;
	}

	total[0][0] = 1;
	total[1][0] = 0;
	total[1][1] = 1;

	LPE(n, 2, MaxVal)
	{
		LP(lastClosed, 0, n-1)
			total[n][0] += total[lastClosed][0];
	}

	LPE(n, 2, MaxVal)
	{
		LPE(s, 1, n)
		{
			total[n][s] = total[n - 1][s - 1];

			LP(lastClosed, 1, n-1)
				total[n][s] += total[lastClosed][s];
		}
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	Process();
	while (true) {
		int n, s;
		scanf("%d %d", &n, &s);

		if (n < 0 && s < 0)
			break;

		L num = 0;
		LPE(i, 0, n)
			num += total[i][s];

		printf("%llu\n", num);
	}

	return 0;
}
