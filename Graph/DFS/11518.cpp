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
using namespace std;

//UVa 11470 Square Sums
//ad hoc
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

int n, m, l;

const int MaxSize = 11000;

SAL adj;

bool visited[MaxSize];

int V_r(int piece)
{
	if(visited[piece])
		return 0;
	else
		visited[piece] = true;

	int toReturn = 1;

	LP(i, 0, adj[piece].size())
		toReturn += V_r(adj[piece][i]);

	return toReturn;
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	int caseNum = 0;

	scanf("%d", &caseNum);

	LP (nC, 0, caseNum) {
		scanf("%d %d %d", &n , &m, &l);

		adj.clear();
		memset(visited, false, sizeof(visited));

		adj = SAL(n + 1);

		LP(nEdge, 0, m)
		{
			int start, end;

			scanf("%d %d", &start, &end);

			adj[start].push_back(end);
		}

		int count = 0;
		LP(nL, 0, l)
		{
			int knocked;

			scanf("%d", &knocked);

			if(!visited[knocked])
				count += V_r(knocked);
		}

		printf("%d\n", count);
	}

	return 0;
}

