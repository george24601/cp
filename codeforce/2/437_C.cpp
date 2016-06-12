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
init priority queue with costs,
dequeue

if(visited)
	ignore
get all its neighbors, reduce their cost, by adding to the queue

}

 */

int const MaxSize = 1010;

int const MOD = 1000000007;

int n, m;
SAL graph;
int visited[MaxSize];
int vs[MaxSize];
int cost[MaxSize];

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d" , &n, &m);

	LPE(i, 1, n)
		scanf("%d", &vs[i]);

	int ans = 0;
	LP(i, 0, m){
		int fir, sec;
		scanf("%d %d", &fir, &sec);

		ans += min(vs[fir], vs[sec]);
	}

	cout << ans << endl;



	return 0;
}
