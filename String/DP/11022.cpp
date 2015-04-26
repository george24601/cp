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

//UVa 11022 String Factoring
//edit distance variant - string dp
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int MaxSize = 80;
const int INF = 2000000000;

char f[MaxSize];

char repCount[MaxSize][MaxSize];
string state[MaxSize][MaxSize];
int dist[MaxSize][MaxSize];

void Process() {
	int fLen = strlen(f);

	//len 1
	LP(i,0, fLen)
	{
		dist[i][i] = 1;
		state[i][i] = f[i];
		repCount[i][i] = 1;
	}

	//len 2
	LP(i, 0, fLen -1)
	{
		string A;
		if (f[i] == f[i + 1]) {
			dist[i][i + 1] = 1;
			state[i][i + 1] = A + f[i];
			repCount[i][i + 1] = 2;
		} else {
			dist[i][i + 1] = 2;
			state[i][i + 1] = A + f[i] + f[i + 1];
			repCount[i][i + 1] = 1;
		}
	}

	LPE(len, 3, fLen)
	{
		for (int start = 0; start + len <= fLen; start++) {
			int end = start + len - 1;

			int curMin = INF;
			string minState;
			int minCount = 0;

			LP(cutOff, start, end)
			{
				int leftCost = dist[start][cutOff];
				int rightCost = dist[cutOff + 1][end];

				bool same = state[start][cutOff] == state[cutOff + 1][end];

				if (same) {
					int newCost = leftCost;

					if (curMin <= newCost)
						continue;

					curMin = newCost;
					minState = state[start][cutOff];
					minCount = repCount[start][cutOff] + repCount[cutOff + 1][end];

				} else {
					int newCost = leftCost + rightCost;

					if (curMin <= newCost)
						continue;

					curMin = newCost;
					minState = "(" + state[start][cutOff] + ")" + repCount[start][cutOff]
							+ "(" + state[cutOff + 1][end] + ")"
							+ repCount[cutOff + 1][end];
					minCount = 1;
				}
			}

			dist[start][end] = curMin;
			state[start][end] = minState;
			repCount[start][end] = minCount;

		}
	}

	printf("%d\n", dist[0][fLen - 1]);
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		gets(f);

		if (strlen(f) == 1 && f[0] == '*')
			break;

		Process();
	}

	return 0;
}
