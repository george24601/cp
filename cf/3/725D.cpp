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

//#define INF 2000000000
#define INF 1e18

/*
 notice,

 */

int n;
int const MaxSize = 300000;

pair<LL, LL> team[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	LL pt, pw;
	cin >> n >> pt >> pw;

	LP(i, 0, n-1)
	{
		LL ti, w;
		cin >> ti >> w;

		team[i] = pair<LL, LL>(-ti, w);
	}

	sort(team, team + n - 1);

	priority_queue<LL> balance;

	int i = 0;

	while (i < n - 1 && -team[i].first > pt) {
		balance.push(-team[i].second - team[i].first - 1);
		i++;
	}

	int numBefore = balance.size();

	while (balance.size() && -balance.top() <= pt) {

		pt += balance.top();
		balance.pop();

		while (i < n - 1 && -team[i].first > pt) {
			balance.push(-team[i].second - team[i].first - 1);
			i++;
		}

		if (balance.size() < numBefore)
			numBefore = balance.size();
	}

	if (balance.size() < numBefore)
		numBefore = balance.size();

	cout << numBefore + 1 << endl;

	return 0;
}
