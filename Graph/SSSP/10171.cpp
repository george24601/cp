#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

//UVa 341  Non-Stop Travel
//Bellman-Ford
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
typedef pair<int, PII> WPII;
#define Ep 1e-9

const int INF = 1000000000;
const int MaxSize = 26;

void Process(int start, map<int, int>& dist, int n, WAL adj) {

	LP(v, 0 , n)
		dist[v] = INF;

	dist[start] = 0;

	LPE(pathLeng, 1, n - 1)
	{
		LP(v, 0 , n)
		{
			if (dist[v] == INF) //not connected yet
				continue;

			LP(i, 0, adj[v].size())
			{
				int u = adj[v][i].first;

				int uv = adj[v][i].second;
				int newDist = dist[v] + uv;

				if (newDist < dist[u])
					dist[u] = newDist;
			}

		}
	}
}

int GetID(map<char, int>& charToID, char to) {
	if (charToID.count(to) == 0) {
		int newID = charToID.size();
		charToID[to] = newID;
	}

	return charToID[to];
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		int N;
		scanf("%d", &N);

		if (N == 0)
			break;

		map<char, int> charToID;

		WAL yAdj(MaxSize);
		map<int, int> yDist;
		WAL mAdj(MaxSize);
		map<int, int> mDist;

		LP(line,0, N)
		{
			char y, u, from, to;
			int cost;
			scanf("%c", &y); //newline

			scanf("%c %c %c %c %d", &y, &u, &from, &to, &cost);

			if (y == 'Y') {
				yAdj[GetID(charToID, from)].push_back(
						PII(GetID(charToID, to), cost));

				if (u == 'B')
					yAdj[GetID(charToID, to)].push_back(
							PII(GetID(charToID, from), cost));

			} else {
				mAdj[GetID(charToID, from)].push_back(
						PII(GetID(charToID, to), cost));

				if (u == 'B')
					mAdj[GetID(charToID, to)].push_back(
							PII(GetID(charToID, from), cost));
			}
		}

		char yStart, mStart;
		scanf("%c", &yStart); //newline
		scanf("%c %c", &yStart, &mStart);

		int yStartID = GetID(charToID, yStart);
		int mStartID = GetID(charToID, mStart);

		Process(yStartID, yDist, charToID.size(), yAdj);
		Process(mStartID, mDist, charToID.size(), mAdj);

		int best = INF;
		vector<char> ans;
		LP(diff, 0, MaxSize)
		{
			char c = 'A' + diff;

			if (charToID.count(c) == 0)
				continue; //no such node

			int id = charToID[c];

			if (yDist[id] == INF || mDist[id] == INF)
				continue;

			int total = yDist[id] + mDist[id];

			if (total < best) {
				best = total;
				ans.clear();
				ans.push_back(c);
			} else if (total == best) {
				ans.push_back(c);
			}
		}

		if (ans.size() == 0) {
			printf("You will never meet.\n");
			continue;
		}

		printf("%d", best);

		LP(i, 0, ans.size())
			printf(" %c", ans[i]);

		printf("\n");
	}

	return 0;
}
