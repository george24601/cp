#include <iostream>
#include <sstream>
#include <stdio.h>
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
#define Ep 1e-8

/*
if root is cat

sum of child, total(m)
if root is cat

total(i, j)
	if (j < 0)
		return 0;
	if is leave
		return 1;

	if i is cat
		sum of total(i, j -1 )
	if i is not cat
		sum of total(i, m)


 */
int const MaxSize = 100000;

SAL graph;
int hasCat[MaxSize];
bool visited[MaxSize];
int n, m;

int total(int i, int remaining){
	if(remaining < 0)
		return 0;
	else if(visited[i])
		return 0;
	else
		visited[i] = true;


	if(graph[i].size() == 1 && visited[graph[i][0]]){
		if (remaining == 0 && hasCat[i])
			return 0;
		else
			return 1;
	}

	//cout << i << endl;

	int nextAllowed = hasCat[i]? (remaining - 1): m;

	int res = 0;

	LP(j,0, graph[i].size())
		res += total(graph[i][j], nextAllowed);

	return res;
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &m);

	graph = SAL(n);

	LP(i, 0, n)
		scanf("%d", &hasCat[i]);

	LP(i, 0, n-1){
		int first, second;
		scanf("%d %d", &first, &second);
		first --;
		second --;
		graph[first].push_back(second);
		graph[second].push_back(first);

	}

	memset(visited, false, sizeof(visited));

	cout << total(0, m) << endl;

	return 0;
}
