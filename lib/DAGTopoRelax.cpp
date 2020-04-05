
const int INF = 2147483640;

const int MaxSize = 40;

int n;

int dist[MaxSize];
int prev[MaxSize];
int order[MaxSize];
bool visited[MaxSize];

SAL adj;

int orderNum;

void TopoRelax() {

	for (int orderN = n - 1; orderN >= 0; orderN--) {
		int node = order[orderN];

		int newDist = dist[node] + 1;
		LP(i, 0, adj[node].size())
		{
			int neighbor = adj[node][i];

			if (dist[neighbor] < newDist) {
				dist[neighbor] = newDist;
				prev[neighbor] = node;
			}
		}
	}
}

void DFS_r(int node) {
	visited[node] = true;

	LP(i, 0, adj[node].size())
	{
		int nbr = adj[node][i];

		if (!visited[nbr]) //not visited yet
			DFS_r(nbr);
	}

	order[orderNum] = node;
	orderNum++;
}

void TopoSort() {
	orderNum = 0;
	LP(i, 0,n)
	{
		if (visited[i])
			continue;

		DFS_r(i);
	}
}
