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

/*
 given n, k
 n to n+1,
 k1 from 1 to n, only if k1 >= k or k % k1 < 0
 ways(index + 1, num) = ways(index, n1) n1 < num  or n1 % num != 0
 check all on ways(N, n), add them all

 l(path-1, from, w1) + el2 = l(path, to, w1 + el1)

 for path in [1,n)
 for all v
 for all w1
 if dis[v][w1] = INF
 continue;
 for all u in neighbor(v)
 try updating dis[u][w1 + W1(u, v)] with dis[v][w1] + W2(u, v)

 */
class DoubleWeights {

public:
	int minimalCost(vector<string> weight1, vector<string> weight2) {
		int N = weight1.size();
		int MaxW = (N -1) * 9;
		int dist[20][MaxW + 1];

		LP(i, 0, N)
			LPE(j, 0, MaxW)
				dist[i][j] = INF; //memset doesn't work!

		dist[0][0] = 0;

		LP(pathLen, 1, N)
		{
			LP(from, 0, N)
			{
				LPE(w1, 0, MaxW)
				{
					if (INF == dist[from][w1])
						continue; //not reached yet

					LP(to, 0, N)
					{
						if (weight1[from][to] == '.')
							continue; //no edge

						//	cout <<dist[u][w1 + w1uv] <<endl;

						int nk = w1 + (weight1[from][to] - '0');

						if (nk <= MaxW) {
							dist[to][nk] = min(dist[to][nk],
									dist[from][w1] + (weight2[from][to] - '0'));
						}else{

							printf("%d %d %d %d\n", from, to, w1, nk);
						}
					}
				}
			}
		}

		int minW = INF;

		LPE(w1, 0, MaxW)
		{
			if (INF == dist[1][w1])
				continue; //unreachable

			minW = min(minW, dist[1][w1] * w1);
		}

		return INF == minW ? -1 : minW;
	}
};

int main() {
	DoubleWeights test;
	static const string arr[] = { "..14", "..94", "19..", "44.." };
	vector<string> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	static const string w2[] = { "..94", "..14", "91..", "44.." };
	vector<string> w2V(w2, w2 + sizeof(w2) / sizeof(w2[0]));

	cout << test.minimalCost(vec, w2V) << endl;
	return 0;
}
