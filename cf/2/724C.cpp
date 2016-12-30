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

 */

int n, m, k;
int const MaxSize = 100010;

PII p[MaxSize];
LL ans[MaxSize];
map<PII, LL> reachT;

bool isEnd(PII p) {
	return (n == p.first || 0 == p.first) && (p.second == 0 || p.second == m);
}

PII calcP1(PII p, bool right) {
	int x = p.first;
	int y = p.second;

	if (right) {
		int dist = min(n - x, m - y);
		return PII(x + dist, y + dist);
	} else {
		int dist = min(x, y);
		return PII(x - dist, y - dist);

	}
}

PII calcN1(PII p, bool right) {

	int x = p.first;
	int y = p.second;

	if (right) {
		int dist = min(n - x, y);
		return PII(x + dist, y - dist);
	} else {
		int dist = min(x, m - y);
		return PII(x - dist, y + dist);
	}
}

LL travelTime(PII from, PII to) {

	return (abs(from.first - to.first) + abs(from.second - to.second)) / 2;
}

void updateTime(PII p, LL t) {
	reachT[p] = t;
}

LL getT(PII p) {
	if (reachT.count(p))
		return reachT[p];
	else
		return INF;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> m >> k;
	memset(ans, -1, sizeof(ans));

	LP(i, 0, k)
	{
		int px, py;
		cin >> px >> py;

		p[i] = PII(px, py);
	}

	PII curP = PII(0, 0);
	LL curTime = 0;
	bool p1 = true;

	do {

		updateTime(curP, curTime);

		PII nextP;

		if (p1) {
			nextP = calcP1(curP, curP.first == 0 || curP.second == 0);
		} else {
			nextP = calcN1(curP, curP.first == 0 || curP.second == m);
		}

		curTime += travelTime(curP, nextP);

		curP = nextP;
		p1 = !p1;
	} while (!isEnd(curP));

	LP(i, 0, k)
	{
		PII s = p[i];

		PII fromP;
		LL minTime = INF;

		vector<PII> from;

		from.push_back(calcP1(s, true));
		from.push_back(calcP1(s, false));
		from.push_back(calcN1(s, true));
		from.push_back(calcN1(s, false));

		LP(j, 0, 4)
		{
			LL fromT = getT(from[j]);
			if (fromT < minTime) {
				fromP = from[j];
				minTime = fromT;
			}
		}

		if (minTime < INF) {
			ans[i] = minTime + travelTime(fromP, s);
		}
	}

	LP(i, 0, k)
		cout << ans[i] << endl;

	return 0;
}
