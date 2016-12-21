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

/*

 */

int n;
string s;
queue<int> rt;
queue<int> dt;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> s;

	LP(i, 0, n)
	{
		if ('R' == s[i])
			rt.push(i);
		else
			dt.push(i);
	}

	while (rt.size() > 0 && dt.size() > 0) {

		int nextRVote = rt.front();
		rt.pop();

		int nextDVote = dt.front();
		dt.pop();

		//cout << nextRVote << " " << nextDVote << endl;

		if (nextRVote > nextDVote)
			dt.push(nextDVote + n); // +n  means next round
		else
			rt.push(nextRVote + n);
	}

	//cout << rt.size() << " " << dt.size() << endl;

	if (rt.size())
		cout << "R" << endl;
	else
		cout << "D" << endl;

	return 0;
}
