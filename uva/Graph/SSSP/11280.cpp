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

//UVa 10557 XYZZY
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

const int MaxSize = 110;

int n;
WAL adj;
int dist[MaxSize][MaxSize];
map<string, int> nameToID;

void Process() {

	LPE(pathLeng, 0, n - 1)
	{
		dist[0][pathLeng] = 0;

		LP(v, 1 , n)
		{
			dist[v][pathLeng] = INF;
		}
	}

	LPE(pathLeng, 1, n - 1)
	{
		LP(v, 0 , n)
		{
			int lastDistV = dist[v][pathLeng - 1];
			if (lastDistV == INF) //not connected yet
				continue;

			LP(i, 0, adj[v].size())
			{
				int u = adj[v][i].first;

				int uv = adj[v][i].second;

				int newDist = lastDistV + uv;
				int oldDist = dist[u][pathLeng - 1];

				dist[u][pathLeng] = Min(dist[u][pathLeng], newDist);
				dist[u][pathLeng] = Min(dist[u][pathLeng], oldDist);
			}

		}
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);
	int numCase;

	cin >> numCase;

	LPE(caseNum, 1, numCase)
	{
		cin >> n;

		nameToID.clear();
		LP(i, 0, n)
		{
			string name;
			cin >> name;
			nameToID[name] = i;
		}

		adj = WAL(n);

		int e;
		cin >> e;

		LP(i, 0, e)
		{
			string from, to;
			int cost;

			cin >> from >> to >> cost;

			adj[nameToID[from]].push_back(make_pair(nameToID[to], cost));

		}

		Process();

		int Q;
		cin >> Q;

		if (caseNum > 1)
			printf("\n");

		printf("Scenario #%d\n", caseNum);
		LP(i, 0, Q)
		{
			int stopOver;
			cin >> stopOver;

			if (stopOver < 0)
				stopOver = 0;

			if (stopOver > n - 2)
				stopOver = n - 2;

			int cost = dist[n - 1][stopOver + 1];

			if (cost == INF) {
				printf("No satisfactory flights\n");
			} else {
				printf("Total cost of flight(s) is $%d\n", cost);
			}

		}

	}

	return 0;
}
