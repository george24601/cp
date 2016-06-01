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

class Sunnygraphs2 {

	bool visited[60];
	int curCompSize;

	SAL udGraph;

	void DFS(int v) {
		if (visited[v])
			return;
		else
			visited[v] = true;

		curCompSize++;

		LP(i, 0, udGraph[v].size())
			DFS(udGraph[v][i]);
	}

public:
	long long count(vector<int> a) {
		int N = a.size();
		memset(visited, false, sizeof(visited));
		int componentCount = 0;

		udGraph = SAL(N);

		LP(i, 0, N)
		{
			udGraph[i].push_back(a[i]);
			udGraph[a[i]].push_back(i);
		}

		LL ans = 1;

		//cout << "start!" << endl;
		LP(i, 0, N)
		{
			if (visited[i])
				continue;

			componentCount++;
			curCompSize = 0;
			DFS(i);

			int cycleCounter = 0;

			map<int, int> clock;
			int next = i;

			int cycleSize;

			while (true) {
				if (clock.count(next)) {
					cycleSize = cycleCounter - clock[next] + 1;
					break;
				} else {
					cycleCounter++;
					clock[next] = cycleCounter;
					next = a[next];
				}
			}

			ans *= (1L << curCompSize) - (1L << (curCompSize - cycleSize));
		}

		if (1 == componentCount)
			ans++;

		return ans;
	}
};

/*
int main() {

//	static const int arr[] = { 1, 0, 0 };
	//static const int arr[] = {2,3,0,1};
	static const int arr[] = {2,3,0,1,0};
	vector<int> vA(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Sunnygraphs2 test;
	cout << test.count(vA) << endl;

	return 0;
}
*/
