#include <iostream>
#include <sstream>
#include <stdio.h>
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
#include <string>
using namespace std;

typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 2001;

int states[MaxN][MaxN];

vector<PII> starts;
vector<PII> nexts;

void TryAdd(int x, int y)
{
	if(x < 0 || x >=MaxN || y < 0 || y >= MaxN)
		return;

	if(1 == states[x][y] || 3 == states[x][y])
		return;

	if(0 == states[x][y])
		states[x][y] = 3;

	nexts.push_back(PII(x,y));
}

int main() {
	//freopen("C:\\Test\\B.1.dat", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		int p1;
		scanf("%d", &p1);

		if (p1 == 0)
			break;
		else {
			starts.clear();
			nexts.clear();
			LP(i, 0, MaxN)
				memset(states[i], 0, sizeof(states[i]));
		}

		LP(i,0,p1)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			states[x][y] = 1;

			starts.push_back(PII(x, y));
		}

		int p2;
		scanf("%d", &p2);

		LP(i,0,p2)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			states[x][y] = 2;
		}

		LP(dist, 0, MaxN)
		{
			LP(i, 0, starts.size())
			{
				int x = starts[i].first;
				int y = starts[i].second;

				if (2 == states[x][y]) {
					printf("%d\n", dist);
					goto Next;
				}

				TryAdd(x - 1, y);
				TryAdd(x + 1, y);
				TryAdd(x, y - 1);
				TryAdd(x, y + 1);
			}

			starts.clear();

			LP(i, 0, nexts.size())
				starts.push_back(nexts[i]);

			nexts.clear();
		}

		Next: continue;
	}

	return 0;
}
