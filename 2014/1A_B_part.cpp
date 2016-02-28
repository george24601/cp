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
#define INF 2000000000
#define Ep 1e-9

/*
 Given a tree with N nodes N < 1000, form a binary tree  by deleting nodes

 so N^2 is possible

 suppose we fix the node n
 leaf node: 1 neighbor
 costK(node) = costD(node's parent)
 2 neighbor
 either delete both or keep both
 delete both: costD(c1) + costD(c2) + 2
 keep both:
 costK(c1) + costK(c2) + 2

 more than 2 neighbors
 delete all or keep 2

 1 node: do nothing
 2 node: delete 1
 3 nodes: do nothing, pick one
 4 nodes: delete 1

 1 neighbor: potential leaf
 2 : potential root, or 1
 3 : potential interal node, or 2, 1
 4+: must do somehting about it!

 note graph is undirected, but tree has direction!
 note if root is good, we can just remove from the graph, it wouldn't affect fullness

 also node the final thing has to be connected

 if only 1 child, everything related!

 Note in a full binary tree, # nodes = 1, 3, 5, 7....

 pick a node as root

 cost(from, node)
 if node has 1 neighbor?
 return 0;
 if node has 2 neighbor
 return size(node, the other neighbor other than from)
 else if node has 3 neighbor
 return cost(siz, LN) + cost(RN)
 else if node has 3+ neighbor
 pick 2 smallest cost to save
 where cost = save cost  + deletionCost

 size(from, node)
 this is obvious, need to cache this


 how do we know which 2 branches to pick?
 i.e, if we keep n2 instead of n1, the overall cost change is
 -costK(n1) + costD(n1) - costD(n2) + costK(n2)

 i.e., we can keep replacing until we have n such that costD(n2) - costK(n2) is max
 obvious costD(n2) = size(n2) > costK(n2), thus reduce the cost

 So costK(from, node)
 assert(# neighbor >=1)

 if (# neighbor =1 )
 return 0;
 else if (# neighbor = 2)
 return size(node, the other neighbor);
 else if (# neighbor = 3)
 return costK(node, the other 1) + cost(node, the other 2);
 else
 for each neighbor other node other than from, calculate costD(n2) - costK(n2)
 keep the max 2

 size (from, node)
 for each neighbor other that from
 total += size(node, neighb0r)

 return total;

 overall cost = costK(from == -1)
 */

int N;
SAL tree;

int const MaxN = 1010;

int size[MaxN][MaxN];
int cost[MaxN][MaxN];

int sizeT(int from, int root) {
	assert(from >= 1);
	if (size[from][root] >= 0)
		return size[from][root];

	int total = 1;
	vector<int> neighbors = tree.at(root);
	int numNeighbor = neighbors.size();
	LP(i, 0, numNeighbor)
	{
		if (neighbors.at(i) == from)
			continue;

		total += sizeT(root, neighbors.at(i));
	}

	return size[from][root] = total;
}

int costK(int from, int root) {
	if (from >= 1 && cost[from][root] >= 0)
		return cost[from][root];

	vector<int> neighbors = tree.at(root);
	int numNeighbor = neighbors.size();

	if (from >= 1 && 1 == numNeighbor)
		return 0;
	else if ((-1 == from && 1 == numNeighbor)
			|| (from >= 1 && 2 == numNeighbor)) {

		LP(i, 0, numNeighbor)
		{
			if (neighbors[i] == from)
				continue;

			return cost[from][root] = sizeT(root, neighbors.at(i));

		}

	} else {

		PII scores[MaxN];
		int j = 0;

		LP(i, 0, numNeighbor)
		{
			int neighbor = neighbors[i];
			if (neighbor == from)
				continue;

			int score = -sizeT(root, neighbor) + costK(root, neighbor);

			printf("%d %d %d %d\n", root, neighbor, sizeT(root, neighbor), costK(root, neighbor));

			scores[j] = PII(score, neighbor);
			j++;
		}

		sort(scores, scores + j);

		int overall = 0;
		overall += scores[0].first + sizeT(root, scores[0].second);
		overall += scores[1].first + sizeT(root, scores[1].second);

		LP(k, 2, j)
		{
			overall = -scores[k].first + costK(root, scores[k].second);
		}

		printf("%d %d %d\n", from, root, overall);

		if (from >= 1)
			return cost[from][root] = overall;
		else
			return overall;
	}

	assert(false);

	return cost[from][root];
}

int main() {
	freopen("/Users/georgeli/B_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/A-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/A_large.out", "w", stdout);

	int T;

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%d", &N);
		//printf("%d %d\n", N, Len);

		tree.clear();

		tree = SAL(N + 1);

		LPE(i, 1,N)
		{
			memset(cost[i], -1, sizeof(cost[i]));
			memset(size[i], -1, sizeof(size[i]));
		}

		LP(i, 1 , N)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			tree.at(from).push_back(to);
			tree.at(to).push_back(from);
		}

		int minCost = INF;

		LPE(root, 1, N)
		{
			minCost = min(minCost, costK(-1, root));
		}

		printf("Case #%d: %d\n", cn, minCost);
	}

	return 0;
}
