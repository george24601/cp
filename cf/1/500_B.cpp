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

suppose n < k and n > k/2, k even

option 1, reduce to

delta + 1

option 2,
1 + 2 * delta , so never move over

if k odd, the last opt must be a sub => done


 */

int const MaxSize = 310;

int const MOD = 1000000007;

int n;

int perm[MaxSize];

vector<string> adj;

bool visited[MaxSize];

vector<int> is;
vector<int> vs;

void dfs(int node){
	if(visited[node])
		return;
	else
		visited[node] = true;

	is.push_back(node);
	vs.push_back(perm[node]);

	LP(i, 0, n){
		if (adj[node][i] - '0')
			dfs(i);
	}
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n;

	adj = vector<string>(n);

	LP(i, 0, n)
		cin >> perm[i];

	LP(i, 0, n)
		cin >> adj[i];

	memset(visited, false, sizeof(visited));

	LP(i, 0, n){
		if(visited[i])
			continue;
		is.clear();
		vs.clear();

		dfs(i);

		sort(is.begin(), is.end());
		sort(vs.begin(), vs.end());

		LP(j, 0, is.size())
			perm[is[j]] = vs[j];
	}

	LP(i,0, n){
		printf("%d", perm[i]);

		if(i < n-1)
			printf(" ");
	}



	return 0;
}
