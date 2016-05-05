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

const int INF = 2147483640;

const int MaxSize = 51;

map<string, int> nameToID;
vector<string> names;
int n;
int dist[MaxSize][MaxSize];

void Process() {
	LP(k, 0 , n)
	{
		LP(i, 0, n)
		{
			LP(j, 0, n)
			{
				int old = dist[i][j];
				int firstNew = dist[i][k];
				int secondNew = dist[k][j];

				if (firstNew == INF || secondNew == INF)
					continue;

				dist[i][j] = min(old, firstNew + secondNew);
			}
		}
	}
}

int GetID(string c) {
	if (nameToID.count(c) == 0) {
		int id = nameToID.size();
		nameToID[c] = id;
		names.push_back(c);
	}

	return nameToID[c];
}

int main() {
	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;
	while (true) {
		nameToID.clear();
		names.clear();
		int P, R;
		cin >> P >> R;

		if (P == 0 && R == 0)
			break;

		LP(i, 0, P)
		{
			LP(j, 0, P)
				dist[i][j] = INF;

			dist[i][i] = 0;
		}

		caseNum++;
		LP(i, 0, R)
		{
			string first, second;
			cin >> first >> second;
			int firstID = GetID(first);
			int secondID = GetID(second);
			dist[firstID][secondID] = 1;
			dist[secondID][firstID] = 1;
		}

		n = P;
		Process();

		int maxVal = 0;
		LP(i, 0, P)
		{
			LP(j, i+1, P )
				maxVal = max(maxVal, dist[i][j]);
		}

		if (maxVal == INF)
			printf("Network %d: DISCONNECTED\n\n", caseNum);
		else
			printf("Network %d: %d\n\n", caseNum, maxVal);

	}

	return 0;
}
