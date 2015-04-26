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

//UVa 10505 Montesco vs Capuleto
//graph - DFS
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

SAL adj;
const int MaxSize = 200;

int visited[MaxSize];

bool P_r(int curNode, int curOddComp) {

	LP(i, 0, adj[curNode].size())
	{
		int toNode = adj[curNode][i];

		if (visited[toNode] == 0) {
			int curNodePar = visited[curNode];

			visited[toNode] = curNodePar % 2 == 0 ? curOddComp : curOddComp - 1;

			bool bicolorable = P_r(toNode, curOddComp);
			if (!bicolorable)
				return false;
		} else if (visited[toNode] == visited[curNode])
			return false;

	}

	return true;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int t;
	scanf("%d", &t);

	LP(caseNum, 0, t)
	{
		int v, e;
		scanf("%d %d", &v, &e);

		memset(visited, 0, sizeof(visited));

		adj = SAL(v);

		LP(i, 0, e)
		{
			int from, to;
			scanf("%d %d", &from, &to);

			adj[from].push_back(to);
			adj[to].push_back(from);
		}

		int curComp = 3;
		bool valid = true;
		LP(p, 0, v)
		{
			if (visited[p] != 0)
				continue;

			visited[p] = curComp;
			valid = P_r(p, curComp);

			if (!valid) {
				printf("-1\n");
				break;
			}

			curComp += 2;

		}

		if (!valid)
			continue;

		map<int, int> parToSize;

		LP(i, 0, v)
			parToSize[visited[i]] += 1;

		int total = 0;

		int compToCheck = 3;
		while (compToCheck < curComp) {
			int evenCount = parToSize[compToCheck - 1];
			int oddCount = parToSize[compToCheck];

			//case of single junction
			total += evenCount == 0 ? oddCount : Min(evenCount, oddCount);

			compToCheck += 2;
		}

		printf("%d\n", total);

	}

	return 0;
}
