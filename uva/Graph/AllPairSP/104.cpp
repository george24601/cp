#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
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
using namespace std;

//UVa 10354 avoiding your boss
//SSSP
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;

const int INF = 2147483647;

const int MaxSize = 21;

int n;
double yield[MaxSize][MaxSize][MaxSize];
int prev[MaxSize][MaxSize][MaxSize];

void P_r(int from, int to, int numInter) {
	if (numInter < 0)
		return;

	int prevN = prev[from][to][numInter];

	P_r(from, prevN, numInter - 1);

	printf("%d ", prevN + 1);
}

void Print() {

	LP(numInter, 1, n)
	{
		LP(i, 0 , n)
		{
			if (yield[i][i][numInter] <= 1.01)
				continue;

			P_r(i, i, numInter);
			printf("%d\n", i + 1);

			return;
		}
	}

	cout << "no arbitrage sequence exists\n";
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (cin >> n) {
		memset(yield, 0, sizeof(double) * MaxSize * MaxSize * MaxSize);
		LP(i, 0, n)
		{
			LP(j, 0 , n)
			{
				prev[i][j][0] = i;
				if (i == j)
					yield[i][j][0] = 1.0;
				else
					cin >> yield[i][j][0];
			}
		}

		LP (numsInter,1, n)
		{
			LP(k, 0, n)
			{
				LP(i, 0, n)
				{
					LP(j, 0 , n)
					{
						double newYield = yield[i][k][numsInter - 1]
								* yield[k][j][0];

						if (yield[i][j][numsInter] < newYield) {
							yield[i][j][numsInter] = newYield;
							prev[i][j][numsInter] = k;
						}
					}
				}
			}
		}

		Print();

	}
	return 0;
}
