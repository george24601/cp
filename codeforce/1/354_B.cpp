#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-8

/*
 10^2 * 10^6, so brute force would do

 1 << 10

 for each level
 spill to both left and right
 0
 01
 012
 0123

 */

int const MaxSize = 10010;

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	int n, t;

	scanf("%d %d", &n, &t);

	SAL bottles;

	LPE(level, 0, n)
	{
		//vector<int> bl(level, 0);
		vector<int> bl;

		LP(i, 0, level)
			bl.push_back(0);

		bottles.push_back(bl);
	}

	int full = 1 << (n + 1);

	LPE(sec, 1, t)
	{
		bottles[1][0] += full;

		LPE(level, 1, n)
		{
			LP(i, 0, level)
			{
				if (bottles[level][i] > full) {
					int diff = bottles[level][i] - full;
					bottles[level][i] = full;

					if (level < n) {
						bottles[level + 1][i] += diff / 2;
						bottles[level + 1][i + 1] += diff / 2;
					}
				}
			}
		}
	}

	int totalFull = 0;

	LPE(level, 1, n)
	{
		LP(i, 0, level)
		{
			/*
			if(bottles[level][i] > full){
				cout <<"problem:" << level << " " << i << endl;
			}
			*/

			if (bottles[level][i] == full)
				totalFull++;
		}
	}

	cout << totalFull << endl;

	return 0;
}
