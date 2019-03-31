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
typedef long double LD;
#define LP(i, a, b) for (LL i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (LL i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

LL const MaxSize = 2000 + 5;
LL const MOD = 1e9 + 7;
LL const BASE = 256;

/*


 */

LL n;
vector<pair<int, PII> > edges;
int parent[MaxSize], dist[MaxSize][MaxSize];
SAL tree;

int Find(int a) {
	//assumption: parent[a] is set a itself on init
	if (parent[a] != a)
		parent[a] = Find(parent[a]);

	return parent[a];
}

void Union(int a, int b) {

	int aP = Find(a);
	int bP = Find(b);

	if (aP == bP)
		return;

	parent[max(aP, bP)] = min(aP, bP);
}

int verify(int v, int p, int tv, int curD) {

	if (dist[tv][v] != curD)
		return -1;

	int reach = 1;
	LP(i, 0, tree[v].size())
	{

		int u = tree[v][i];
		if (u == p)
			continue;

		int res = verify(u, v, tv, curD + dist[u][v]);

		if (res < 0)
			return -1;
		else
			reach += res;
	}

	return reach;

}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	scanf("%d", &n);
	tree = SAL(n + 1);
	LPE(i, 1, n)
	{
		parent[i] = i;
		LPE(j, 1, n)
		{
			int d;
			scanf("%d", &d);

			if (i != j) {
				if (d) {
					edges.push_back(pair<int, PII>(d, PII(j, i)));

				} else {
					cout << "NO";
					return 0;
				}

			}

			dist[i][j] = d;
			dist[j][i] = d;
		}
	}

	sort(edges.begin(), edges.end());

	LP(i, 0, edges.size())
	{
		int f = edges[i].second.first;
		int s = edges[i].second.second;

		if (Find(f) == Find(s)) {

		} else {
			Union(f, s);
			tree[f].push_back(s);
			tree[s].push_back(f);
			//	cout << f << " " << s << " " << d << endl;
		}
	}

	LPE(v, 1, n)
	{
		int reached = verify(v, -1, v, 0);

		if (reached != n) {
			cout << "NO";
			return 0;
		}

	}

	cout << "YES";

	return 0;
}
