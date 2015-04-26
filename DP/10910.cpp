#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 12372
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

int N, T, P;
unsigned int total[71][71];

void Process() {

	total[0][0] = 1;

	LPE(i, P, T)
		total[1][i] = 1;

	LPE(i, 2, N)
	{
		LPE(j, 0, T)
		{
			for(int k = P; k <= j; k++)
			{
				total[i][j] += total[i - 1][j - k];
			}
		}
	}

}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Users\\George\\c1\\test\\src\\t.txt", "r", stdin);

	int K;
	scanf("%d", &K);

	LP(i, 0, K)
	{
		scanf("%d %d %d", &N, &T, &P);

		LPE(j, 0, N)
		{
			LPE(k, 0, T)
				total[j][k] = 0;
		}

		Process();

		cout << total[N][T] << endl;
	}

	return 0;
}
