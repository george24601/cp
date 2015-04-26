#include <iostream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

//UVa 280 Vertex
//Graph - DFS

typedef unsigned long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
#define Min(a ,b ) a < b ? a : b
#define Max(a ,b ) a > b ? a : b
typedef vector<vector<int> > AL;

const int MaxSize = 100;
bool visited[MaxSize];

int n;
AL edges;
int unvisited;

void DFS(int u, bool first) {
	if (!first) {
		visited[u] = true;
		unvisited--;
	}

	LP(i, 0, edges[u].size())
	{
		int otherNode = edges[u][i];
		if (visited[otherNode]) {
			continue;
		} else {
			DFS(otherNode, false);
		}
	}
}

void Process(int startNode) {
	unvisited = n;

	LPE(i, 1, n)
		visited[i] = false;

	DFS(startNode, true);

	printf("%d", unvisited);

	LPE(i, 1, n)
	{
		if (!visited[i])
			printf(" %d", i);
	}

	printf("\n");
}

int main(int argc, const char * argv[]) {

	//freopen("C:\\Test\\Test.txt", "r", stdin);

	while (true) {
		scanf("%d", &n);

		if (n == 0)
			break;
		AL adjList(n + 1);

		while (true) {
			int i;
			scanf("%d", &i);

			if (i == 0)
				break;

			while (true) {
				int j;
				scanf("%d", &j);

				if (j == 0)
					break;

				adjList[i].push_back(j);
			}
		}

		edges = adjList;

		int numCase;
		scanf("%d", &numCase);
		LP(i, 0 , numCase)
		{
			int startNode;
			scanf("%d", &startNode);
			Process(startNode);
		}
	}

	return 0;
}
