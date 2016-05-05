#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 10943 How do you add?
//DP
typedef long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

#define LPE(i, a, b) \
	for (int i = int(a); i <= int(b); i++)

//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

const int MaxVal = 100;
const int Mod = 1000000;

int total[MaxVal + 1][MaxVal + 1];
int N, K;

void Process() {

	LPE(i, 0, K)
	{
		LPE(j, 0, N)
		{
			total[i][j] = 0;
		}
	}

	LPE(i, 0, K)
		total[i][0] = 1;

	LPE(i, 1, K)
	{
		LPE(j, 1, N)
		{
			LPE(k, 0, j)
			{
				total[i][j] = (total[i][j] + total[i - 1][j - k]) % Mod;

			}
		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Users\\George\\c1\\test\\src\\t.txt", "r", stdin);

	while (true) {
		scanf("%d %d", &N, &K);

		if (N == 0 && K == 0)
			break;

		Process();

		int totalNum = total[K][N];

		printf("%d\n", totalNum);
	}

	return 0;
}
