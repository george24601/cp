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
#define MOD 1000000007

//DP,graph, complete search
/*
 given n, k
 n to n+1,
 k1 from 1 to n, only if k1 >= k or k % k1 < 0
 ways(index + 1, num) = ways(index, n1) n1 < num  or n1 % num != 0
 check all on ways(N, n), add them all
 */
class DoubleWeights{
	int tw [21][21][180];
	int n;


public :
	int minimalCost(vector<string> weight1, vector<string> weight2){
		n = weight1.size();

		int minW = INF;

		LP(i, 0, n){
			LP(j, 0, n){
				memset(tw[i][j], -1, sizeof(tw[i][j]));
			}
		}

		tw[0][0][0] = 0;

		LPE(pathLen, 1, n){
			LP(from, 0, n){
				LP(to, 0, n){
					if (weight1[from][to] == '.')
						continue; //no path

					int el1 = weight1[from][to]  - '0';
					int el2 = weight2[from][to]  - '0';

					LP(fromW1, 0, n * 9){
						if (tw[pathLen - 1][from][fromW1] < 0)
							continue;

						int newToW2 = tw[pathLen - 1][from][fromW1] + el2;

						int oldToW2 = tw[pathLen - 1][to][fromW1 + el1];

						if(oldToW2 < 0 || oldToW2 > newToW2)
							tw[pathLen][to][fromW1 + el1] = newToW2;
						else
							tw[pathLen][to][fromW1 + el1] = oldToW2;
					}
				}
			}
		}


		LPE(w1, 1, (n -1) * 9){
			if (tw[n][1][w1] <= 0)
				continue;

			minW = min(minW, tw[n][1][w1] * w1);
		}

		return INF == minW ? -1 : minW;
	}
};

int main() {
	return 0;
}
