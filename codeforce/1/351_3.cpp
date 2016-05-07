#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
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
#define Ep 1e-9

/*
int numWinner

LP(i, 0, n)
	int resultArr
	int currentMax

	LP(j, i, n)
		result[c[j]]++;
		if (result[c[j]] > currentMax){
			update currentMax
			numWinner[c[j]]++;
		}


 */

int n, m;
int const MaxSize = 5001;

int main() {
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-small-attempt1.in", "r", stdin);
	//freopen("/Users/georgeli/B_1.out", "w", stdout);

	scanf("%d", &n);

	int colors[MaxSize];

	LP(i, 0, n)
		scanf("%d", &colors[i]);

	int numWins[MaxSize];
	memset(numWins, 0, sizeof(numWins));

	LP(i, 0, n){
		int counts [MaxSize];
		memset(counts, 0, sizeof(counts));

		int curMax = 0;
		int curWinner = colors[i] - 1;

		LP(j, i, n){
			int c = colors[j] - 1;

			counts[c]++;

			if(counts[c] > curMax || (counts[c] == curMax && curWinner > c)){
				curMax = counts[c];
				numWins[c]++;
				curWinner = c;
			}else{
				numWins[curWinner]++;
			}

			//printf("%d %d %d\n", i, j, curWinner);
		}
	}

	printf("%d", numWins[0]);

	LP(i, 1, n)
		printf(" %d", numWins[i]);

	printf("\n");

	return 0;
}
