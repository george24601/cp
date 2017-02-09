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
#define Ep 1e-7

#define INF 2000000000
//#define INF 1e18
/*
 ways : check current char

 ways[l] = sum of way[l - subL], while l - subL is a valid string
 nS[l] = nS[l - subL] + 1, keep updating subL at each step

 int curL =

 need to keep track of hates

 if love, make sure they are not hate
 if hate, make sure they are not love => i.e., not in the same union

 */

int const MaxSize = 100010;
int parent[MaxSize];

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

int n, m, q;
map<string, int> sToID;
int op[MaxSize];

bool isOp(int x, int y) {
	if (x < 0 || y < 0)
		return false;

	return op[Find(x)] == Find(y);
}

bool isEq(int x, int y) {
	if (x < 0 || y < 0)
		return false;

	return Find(x) == Find(y);
}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> m >> q;

	LP(i, 0, n)
	{
		string s;
		cin >> s;
		sToID[s] = i;
		parent[i] = i;
		op[i] = -1;
	}

	LP(i, 0, m)
	{
		int t;
		string x, y;

		cin >> t >> x >> y;
		int xID = sToID[x];
		int xParent = Find(xID);
		int xPOP = op[xParent];

		int yID = sToID[y];
		int yParent = Find(yID);
		int yPOP = op[yParent];

		if (1 == t) {
			if (isOp(xParent, yParent) || isOp(xPOP, yPOP)
					|| isEq(xParent, yPOP) || isEq(yParent, xPOP))
				cout << "NO" << endl;
			else {
				cout << "YES" << endl;
				Union(xID, yID);

				int newParent = Find(xParent);
				int newOP = -1;

				if (xPOP >= 0 && yPOP >= 0) {
					Union(xPOP, yPOP);

					newOP = Find(xPOP);

				} else if (xPOP >= 0) {
					newOP = xPOP;
				} else if (yPOP >= 0) {
					newOP = yPOP;
				}

				if (newOP >= 0) {
					op[newParent] = newOP;
					op[newOP] = newParent;
				}
			}
		} else {
			if (isEq(xParent, yParent) || isEq(xPOP, yPOP)
					|| isOp(xParent, yPOP) || isOp(yParent, xPOP))
				cout << "NO" << endl;
			else {

				cout << "YES" << endl;
				if (yPOP >= 0)
					Union(xParent, yPOP);

				if (xPOP >= 0)
					Union(yParent, xPOP);

				int newParent = Find(xParent);
				int newOP = Find(yParent);

				op[newParent] = newOP;
				op[newOP] = newParent;
			}
		}
	}

	LP(i, 0, q)
	{
		string x, y;
		cin >> x >> y;

		int xID = sToID[x];
		int yID = sToID[y];

		if (isEq(xID, yID))
			cout << 1 << endl;
		else if (isOp(xID, yID))
			cout << 2 << endl;
		else
			cout << 3 << endl;
	}

	return 0;
}
