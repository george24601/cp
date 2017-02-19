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

//#define INF 2000000000
#define INF 1e9
/*
 we visit, either at the time of a arrival
 or time of another arrivial - 1, to ensure that most has been drained, at we can cut in front of the line

 toprocess = -1

 next available time =

 nextT = 0;

 tryArrival
 updateNexT;
 arrivial = curT

 if nextT < latestpossible, just use that
 */

int const MaxSize = 1e6 + 1;

/*
 either 2 cuts within the same subtree or different one
 calculate rootSum

 bool canCut2()
 canCutOne
 total is 2
 or canCut 2

 */
SAL g;
int t[MaxSize], rs[MaxSize], single[MaxSize], n;
int target, root;

int rootSum(int id) {
	if (rs[id] != INF)
		return rs[id];

	int ans = t[id];

	LP(i, 0, g.at(id).size())
	{
		int child = g.at(id)[i];

		ans += rootSum(child);
	}

	//cout << "rs:" << id << " " << ans << endl;

	return rs[id] = ans;
}

int cut(int id) {
	if (single[id] != INF)
		return single[id];

	if (target == rootSum(id))
		return id;

	int ans = -1;

	LP(i, 0, g.at(id).size())
	{
		int child = g.at(id)[i];

		int single = cut(child);

		if (single > 0) {
			ans = single;
			break;
		}
	}

	return single[id] = ans;
}

PII cut2(int id) {

	//cout << "cut2 " <<  id << endl;

	vector<int> ans;

	LP(i, 0, g.at(id).size())
	{
		int child = g.at(id)[i];

		PII both = cut2(child);

		if (both.second > 0) {
			return both;
		}

		int single = cut(child);

		if (single > 0) {
			ans.push_back(single);
		}
	}

	if (ans.size() >= 2)
		return PII(ans[0], ans[1]);
	else if (ans.size() == 1 && rootSum(id) == 2 * target && id != root) {
		return PII(ans[0], id);
	} else
		return PII(-1, -1);

}

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);
	cin >> n;

	g = SAL(n + 1);

	LPE(id, 1, n)
	{
		int ai, ti;
		cin >> ai >> ti;

		if(ai == 0)
			root = id;
		else
			g.at(ai).push_back(id); //other dir?

		t[id] = ti;
		target += ti;
		rs[id] = INF;
		single[id] = INF;
	}

	if (target % 3) {
		cout << -1 << endl;
		return 0;
	} else {
		target /= 3;
	}

	PII ans = cut2(root);

	if (ans.first == -1) {
		cout << -1 << endl;
	} else {
		cout << ans.first << " " << ans.second << endl;
	}

	return 0;
}
