#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//UVa 11628: Another lottery
//Probability

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 10000;
L top[MaxSize];

int n, m;
L bottom;

L Gcd(L big, L small) {
	if (big % small == 0)
		return small;

	return Gcd(small, big % small);
}

void Process() {
	LP(i, 0, n)
	{
		if (top[i] == 0) {
			printf("0 / 1\n");
		} else {
			L topN = top[i];

			L gcd = Gcd(bottom, topN);
			printf("%llu / %llu\n", topN / gcd, bottom / gcd);
		}
	}
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d %d", &n, &m);

		if (n == 0 && m == 0)
			break;

		bottom = 0;

		LP(i, 0, n)
		{
			LP(j, 0, m)
			{
				int num;
				scanf("%d", &num);

				if (j == m - 1) {
					top[i] = num;
					bottom += num;
				}
			}
		}

		Process();
	}
	return 0;
}
