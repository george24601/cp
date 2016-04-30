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
 each cross road has 4 corners, so last 2 bit to represent which corner

 so total 4 * N * M nodes

 at each node, look at the current time, try to make a move to neighbors node


 */
int N, M;
int const MaxSize = 20;
int S[MaxSize][MaxSize];
int W[MaxSize][MaxSize];
int T[MaxSize][MaxSize];
int NN;

int dist [MaxSize * MaxSize * 4];

int toIndex(int r, int col, int corner){
	return (((r * M) + col) << 2) + corner;
}

void tryUpdate(int r, int col, int corner, int newCost){
	dist[toIndex(r, col, corner)] = min(dist[toIndex(r, col, corner)], newCost);
}

int cycleTime(int r, int c, int curTime){
	int cl = S[r][c] + W[r][c];
	int T0 = T[r][c];

	if(curTime < T0)
		curTime += (((T0 -curTime) / cl) + 1) * cl;

	return (curTime - T0) % cl;
}

int HC(int r, int c, int curTime){
	int ct = cycleTime(r,c, curTime);
	int cl = S[r][c] + W[r][c];

	int wait = 0;
	if (ct >= cl - 1 || ct < S[r][c])
		wait = (cl - ct - 1) + cl + S[r][c];

	return wait +1;
}

int VC(int r, int c, int curTime){
	int ct = cycleTime(r,c, curTime);
	int cl = S[r][c] + W[r][c];

	int wait = 0;
	if (ct >= S[r][c] - 1)
		wait = (S[r][c]- ct - 1) + W[r][c] + cl;

	return wait + 1;
}


void relax(int r, int col, int corner){
	int curCost = dist[toIndex(r, col, corner)];

	if(corner == 0){
		tryUpdate(r, col, 1, HC(r, col, curCost));
		tryUpdate(r, col, 2, VC(r, col, curCost));

		if(col > 0)
			tryUpdate(r, col - 1, 1, curCost + 2);

		if(r > 0)
			tryUpdate(r - 1, col, 2, curCost + 2);
	}else if (corner == 1){
		if(col < M - 1)
			tryUpdate(r, col + 1, 0, curCost + 2);

		tryUpdate(r, col, 3, VC(r, col, curCost));

		tryUpdate(r, col, 0, HC(r, col, curCost));

		if(r > 0)
			tryUpdate(r - 1, col, 3, curCost + 2);

	}else if (corner == 2){
		tryUpdate(r, col, 3, HC(r, col, curCost));

		if(r < N - 1)
			tryUpdate(r + 1, col, 0, curCost + 2);

		if(col > 0)
			tryUpdate(r, col - 0 , 3, curCost + 2);

		tryUpdate(r, col, 0, VC(r, col, curCost));

	}else{
		assert(corner == 3);

		if(col < M - 1)
			tryUpdate(r, col + 1, 2, curCost + 2);

		if(r < N - 1)
			tryUpdate(r + 1, col, 1, curCost + 2);

		tryUpdate(r, col, 2, HC(r, col, curCost));
		tryUpdate(r, col, 1, VC(r, col, curCost));
	}
}

int main() {
	freopen("/Users/georgeli/Downloads/A-small-practice.in", "r", stdin);
	//freopen("/Users/georgeli/C_1.in", "r", stdin);
	//freopen("/Users/georgeli/C_large.out", "w", stdout);

	int TN;
	scanf("%d", &TN);

	LPE(cn, 1, TN){
		scanf("%d %d", &N, &M);

		NN = 4 * N * M;

		LP(i, 0, N){
			LP(j,0, M){
				scanf("%d %d %d", &S[i][j], &W[i][j], &T[i][j]);

				LP(k, 0, 4)
					dist[toIndex(i, j, k)] = INF;
			}
		}

		dist[toIndex(0, 0, 0)] = 0; //TL

		LP(pathLen, 1, NN){
			LP(r, 0, N){
				LP(col, 0, M){
					LP(corner, 0, 4){
						if(dist[toIndex(r, col, corner)] == INF)
							continue; //not reached yet

						relax(r, col, corner);
					}
				}
			}
		}

		printf("Case #%d: %d\n", cn, dist[toIndex(N-1, M-1, 4)]);
	}

	return 0;
}
