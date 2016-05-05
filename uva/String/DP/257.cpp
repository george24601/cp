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

//UVa 257 String to Palindrome
//idea: if such pattern exists => we can reduct that to 3 or 4 palidndrome
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

const int MaxSize = 260;
const int INF = 2000000000;

char f[MaxSize];

int longest[MaxSize];
bool dist[MaxSize][MaxSize];

void Process() {
	int fLen = strlen(f);

	//len 1
	LP(i,0, fLen)
	{
		dist[i][i] = true;
		longest[i] = 1;

	}

	//len 2
	LP(i, 0, fLen -1)
	{
		if (f[i] == f[i + 1]) {
			dist[i][i + 1] = true;
			longest[i] = 2;
		} else {
			dist[i][i + 1] = false;
		}
	}

	LPE(len, 3, fLen)
	{
		if (len > 4)
			break;

		for (int start = 0; start + len <= fLen; start++) {
			int end = start + len - 1;

			bool both = dist[start + 1][end - 1];
			if (f[start] == f[end] && both) {
				dist[start][end] = true;
				longest[start] = len;
			} else {
				dist[start][end] = false;
			}

		}
	}

	LP(i, 0, fLen)
	{
		if (longest[i] < 3)
			continue;

		LP(j, i+1, fLen)
		{
			if (longest[j] < 3)
				continue;

			bool valid = false;

			LP(index,0, Min(longest[j],longest[i]))
			{
				if (f[i + index] != f[j + index]) {
					valid = true;
					break;
				}

			}

			if (valid) {
				printf("%s\n", f);
				return;
			}
		}

	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (scanf("%s", f) == 1) {
		Process();

	}

	return 0;
}
