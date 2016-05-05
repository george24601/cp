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

//UVa 10354 avoiding your boss
//SSSP
typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483647;

const int MaxSize = 60;

int n;
double dist[MaxSize][MaxSize];
map<string, int> nameToID;

void Process() {
	LP(k, 0 , n)
	{
		LP(i, 0, n)
		{
			LP(j, 0, n)
			{
				double old = dist[i][j];
				double firstNew = dist[i][k];
				double secondNew = dist[k][j];

				double newCost = firstNew * secondNew;

				if (newCost > old + Ep)
					dist[i][j] = newCost;
			}
		}
	}

	LP(i, 0, n)
	{
		if (dist[i][i] > 1.0 + Ep) {
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	while (true) {
		nameToID.clear();

		cin >> n;

		if (n == 0)
			break;

		caseNum++;
		printf("Case %d: ", caseNum);

		LP(i, 0, n)
		{
			memset(dist[i], 0, sizeof(dist[i]));
			dist[i][i] = 1;

			string name;
			cin >> name;

			int id = nameToID.size();
			nameToID[name] = id;
		}

		int m;
		cin >> m;

		LP(i, 0, m)
		{
			string from, to;
			double rate;
			cin >> from >> rate >> to;
			int fromID = nameToID[from];
			int toID = nameToID[to];

			dist[fromID][toID] = rate;
		}

		Process();

	}

	return 0;
}
