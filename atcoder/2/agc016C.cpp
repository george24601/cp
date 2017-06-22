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
#define Ep 1e-13

#define INF 1e9
int const MaxSize = 1e5 + 10;
int H, W, h, w;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);

	cin >> H >> W >> h >> w;

	if (H % h || W % w) {
		cout << "Yes" << endl;

		int numSq = (H / h) * (W / w);

		int padding = H * W - numSq * h * w;

		int pv = (numSq / padding) + 1;

		LP(i, 0, H)
		{
			LP(j, 0, W)
			{

				if (i % h == h - 1 && j % w == w - 1)
					cout << -pv * (h * w - 1) - 1;
				else
					cout << pv;

				if (j < W - 1)
					cout << " ";
			}

			cout << endl;
		}

	} else {
		cout << "No";

	}

	return 0;
}
