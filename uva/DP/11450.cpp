#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 11450 Wedding Shopping
//DP
typedef unsigned long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

#define LPE(i, a, b) \
	for (int i = int(a); i <= int(b); i++)

#define Min(a ,b ) a < b ? a : b

const int MaxVal = 65;

int Ks[20];
int prices[20][20];
bool possible[21][201];

L total[MaxVal + 1][MaxVal + 1];

int M, C;

void Process() {

	possible[0][0] = true;

	LPE(numItem, 1, C)
	{
		LPE(amount, 1, M)
		{
			LP(k, 0, Ks[numItem - 1])
			{
				int p = prices[numItem - 1][k];

				if (p > amount)
					continue;

				if (possible[numItem - 1][amount - p])
					possible[numItem][amount] = true;
			}

		}
	}

	for (int p = M; p >= 0; p--) {
		if (possible[C][p]) {
			cout << p << endl;
			return;
		}
	}

	cout << "no solution" << endl;
}

int main(int argc, const char * argv[]) {

//	freopen("C:\\Test\\Test.txt", "r", stdin);
	int N;
	scanf("%d", &N);

	LP(caseNum, 0, N)
	{
		scanf("%d %d", &M, &C);
		LP(itemNum, 0, C)
		{
			int K;
			scanf("%d", &K);

			Ks[itemNum] = K;

			LP(option, 0, K)
			{
				int p;
				scanf("%d", &p);
				prices[itemNum][option] = p;

			}
		}

		LPE(i, 0, C)
		{
			LPE(j, 0, M)
				possible[i][j] = false;
		}

		Process();
	}

	return 0;
}
