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
#define Ep 1e-13

#define INF 1e9
int const MaxSize = 1e4 + 10;
int n, m, k, dist[MaxSize];
vector<PII> vs;
map<PII, int> vToID;
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
priority_queue<PII> toVisit;
int litRow[MaxSize], litCol[MaxSize];
SAL rToIDs, cToIDs;

void tryPopRow(int r, int newD) {
	if (r >= 1 && r <= n) {
		LP(i, 0, rToIDs.at(r).size())
		{
			int nextID = rToIDs.at(r)[i];

			toVisit.push(PII(-newD, nextID));
		}
	}
}

void tryRow(int lightRow, int newD) {

	if (lightRow >= 1 && lightRow <= n && !litRow[lightRow]) {
		litRow[lightRow] = newD;

		tryPopRow(lightRow - 1, newD);
		tryPopRow(lightRow, newD);
		tryPopRow(lightRow + 1, newD);
	}
}

void tryPopCol(int c, int newD) {
	if (c >= 1 && c <= m) {
		LP(i, 0, cToIDs.at(c).size())
		{
			int nextID = cToIDs.at(c)[i];

			toVisit.push(PII(-newD, nextID));
		}
	}
}

void tryCol(int lightCol, int newD) {

	//cout << "paint col " << lightCol << " " << newD << endl;

	if (lightCol >= 1 && lightCol <= m && !litCol[lightCol]) {
		litCol[lightCol] = newD;

		tryPopCol(lightCol - 1, newD);
		tryPopCol(lightCol, newD);
		tryPopCol(lightCol + 1, newD);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> n >> m >> k;

	rToIDs = SAL(n + 1);
	cToIDs = SAL(m + 1);

	LP(vID, 0, k)
	{
		int r, c;
		cin >> r >> c;
		PII v = PII(r, c);
		vs.push_back(v);
		vToID[v] = vID;
		rToIDs.at(r).push_back(vID);
		cToIDs.at(c).push_back(vID);
	}

	LP(id, 0, vs.size())
		dist[id] = INF;

	int rootID = vToID[PII(1, 1)];
	toVisit.push(PII(0, rootID));

	while (toVisit.size()) {
		PII distToID = toVisit.top();
		toVisit.pop();
		int vID = distToID.second;
		int curD = -distToID.first;

		if (dist[vID] <= curD)
			continue;
		else
			dist[vID] = curD;

		int cr = vs[vID].first;
		int cc = vs[vID].second;

		//cout << cr << " " << cc << " " << curD << endl;

		LP(i, 0, 4)
		{
			int nr = dr[i] + cr;
			int nc = dc[i] + cc;

			PII nextV = PII(nr, nc);

			if (vToID.count(nextV)) {
				toVisit.push(PII(-curD, vToID[nextV]));
			}
		}

		tryRow(cr + 1, curD + 1);
		tryRow(cr - 1, curD + 1);

		tryCol(cc + 1, curD + 1);
		tryCol(cc - 1, curD + 1);
	}

	PII target = PII(n, m);

	int ans = INF;
	if (vToID.count(target)) {
		ans = min(ans, dist[vToID[target]]);
	} else {
		LPE(fromRow, n-1, n)
		{
			LP(i, 0, rToIDs.at(fromRow).size())
			{
				int nextID = rToIDs.at(fromRow)[i];

				if (dist[nextID] < INF)
					ans = min(ans, dist[nextID] + 1);
			}
		}

		LPE(fromCol, m-1, m)
		{
			LP(i, 0, cToIDs.at(fromCol).size())
			{
				int nextID = cToIDs.at(fromCol)[i];

				if (dist[nextID] < INF)
					ans = min(ans, dist[nextID] + 1);
			}
		}
	}

	if (ans < INF)
		cout << ans;
	else
		cout << -1;
}
