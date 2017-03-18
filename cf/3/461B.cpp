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
//typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-7

#define INF 1e9

/*
 if root subtree is part of the tree
 ways(v, 0) *= ways(u, 0)
 ways(v, 1) = ways(v, 1) * ways(u, 0) + ways(v, 0) * ways(u, 1)

 if root subtree is not part of the tree
 ways(v, 0) *= ways(u, 1)
 ways(v, 1) *=  ways(u, 1)

 */

int const MaxSize = 1e5;

int n, isB[MaxSize + 1];
LL ways[MaxSize + 1][2];
SAL g;

LL const MOD = 1e9 + 7;

void calc(int v, int from) {

	ways[v][0] = 1 - isB[v];
	ways[v][1] = isB[v];

	LP(i, 0, g.at(v).size())
	{
		int child = g.at(v)[i];

		if (child == from)
			continue;

		calc(child, v);

		LL oldV0 = ways[v][0];
		LL oldV1 = ways[v][1];

		//cout << v <<" before:" << from << " " << ways[v][0] << " " << ways[v][1] << endl;
		//if child is part of the root cut
		ways[v][0] = (oldV0 * ways[child][0]);
		ways[v][0] %= MOD;
		ways[v][1] = (oldV1 * ways[child][0]) % MOD
				+ (oldV0 * ways[child][1]) % MOD;
		ways[v][1] %= MOD;

		//cout << v <<" part from:" << from << " " << ways[v][0] << " " << ways[v][1] << endl;
		//if child is not part of the root cut
		ways[v][0] += oldV0 * ways[child][1]; //we have the constraint all other cuts are valid
		ways[v][0] %= MOD;
		ways[v][1] += oldV1 * ways[child][1]; //we have the constraint all other cuts are valid
		ways[v][1] %= MOD;

		//cout << v <<" not part from:" << from << " " << ways[v][0] << " " << ways[v][1] << endl;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);
	cin >> n;

	g = SAL(n + 1);

	LP(i, 0, n - 1)
	{
		int pi;
		cin >> pi;
		g.at(pi).push_back(i + 1);
		g.at(i + 1).push_back(pi);
	}

	LP(i, 0, n)
		cin >> isB[i];

	calc(0, -1);

	/*
	LP(i, 0, n){
		cout << i << " " <<  ways[i][0] << " " << ways[i][1] << endl;
	}
	*/

	cout << ways[0][1];

	return 0;
}
