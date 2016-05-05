#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
using namespace std;

//UVa 10731 Test
//SCC
typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef pair<int, int> DW;
typedef vector<vector<DW> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-9

int n;
int postN;

const int MaxSize = 27;

bool adj[MaxSize][MaxSize];
bool rAdj[MaxSize][MaxSize];

int nIDToPN[MaxSize];
int postNToNID[MaxSize];
bool visited[MaxSize];
bool rVisited[MaxSize];

int sccSize;
int sccMs[MaxSize];

map<char, int> nameToNID;
char nIDToName[MaxSize];

vector<string> result;

int ToI(char name) {

	if (nameToNID[name] == 0) {
		n++;
		nameToNID[name] = n;
		nIDToName[n] = name;
	}

	return nameToNID[name];
}

void DFS_r(int node) {
	if (visited[node])
		return;
	else
		visited[node] = true;

	LPE(i, 1, n)
	{
		if (adj[node][i])
			DFS_r(i);
	}

	postN++;
	nIDToPN[node] = postN;
	postNToNID[postN] = node;
}

void rDFS_r(int node) {
	if (rVisited[node])
		return;
	else
		rVisited[node] = true;

	LPE(i, 1, n)
	{
		if (rAdj[node][i])
			rDFS_r(i);
	}

	sccMs[sccSize] = node;
	sccSize++;
}

void SCC() {

	LPE(i, 1, n)
	{
		if (nIDToPN[i] == 0)
			DFS_r(i);
	}

	for (int pn = n; pn >= 1; pn--) {
		if (rVisited[postNToNID[pn]])
			continue;

		sccSize = 0;
		memset(sccMs, 0, sizeof(sccMs));
		rDFS_r(postNToNID[pn]);

		char buff[MaxSize];
		memset(buff, 0, sizeof(buff));

		LP(i, 0, sccSize)
			buff[i] = nIDToName[sccMs[i]];

		sort(buff, buff + sccSize);

		result.push_back(string(buff));
	}
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);
	int caseNum = 0;
	while (true) {
		int m;

		cin >> m;

		if (m == 0)
			break;

		caseNum++;

		n = 0;
		postN = 0;
		memset(nIDToPN, 0, sizeof(nIDToPN));
		memset(postNToNID, 0, sizeof(postNToNID));
		memset(visited, false, sizeof(visited));
		memset(rVisited, false, sizeof(rVisited));
		nameToNID.clear();

		LP(i, 0, MaxSize)
		{
			memset(adj[i], false, sizeof(adj[i]));
			memset(rAdj[i], false, sizeof(rAdj[i]));
		}

		result.clear();

		string buff[6];
		LP(line, 0, m)
		{
			LP(j, 0, 6)
				cin >> buff[j];

			char from = buff[5][0];
			int fI = ToI(from);

			LP(j, 0, 5)
			{
				char to = buff[j][0];
				int sI = ToI(to);

				if(sI == fI)
					continue;

				adj[fI][sI] = true;
				rAdj[sI][fI] = true;
			}
		}

		if (caseNum > 1)
			printf("\n");

		SCC();

		sort(result.begin(), result.end());

		LP(i, 0, result.size())
		{
			string line = result[i];

			printf("%c", line[0]);

			LP(j, 1, line.size())
				printf(" %c", line[j]);

			printf("\n");
		}

	}

	return 0;
}
