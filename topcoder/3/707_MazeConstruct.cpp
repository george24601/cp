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
#define Ep 1e-7

#define INF 2000000000
//#define INF 1e18
/*
 solution always exists:

 so if k < 100, just give a completely empty whiteboard, n as big as possible, remaining m = k - n - 1

 what is the max k to construct?

 claim: extra detour <=(?) number of x
 1 * 1 = 1

 2 *2 = 2

 3 * 3 =

 minLength(i, j, length), min length from(i, j) to n-1, m - 1 with length k
 nextDir, i, j, length


 */

class MazeConstruct {
	vector<string> base(int nr, int nc) {
		string r = string(nc, '.');

		return vector<string>(nr, r);
	}

public:
	vector<string> construct(int k) {

		if (k <= 49) {
			return base(1, k + 1);
		} else if (k <= 98) {
			return base(k - 48, 50);
		} else {
			int nr = k % 2 ? 49 : 50;
			int nc = 50;
			vector<string> ans = base(nr, nc);
			int baseK = nr + 48;

			for (int i = 1; i < nr; i += 4) {
				LP(j, 0, nc- 1){
					ans[i][j] = '#';
				}
			}

			for (int i = 3; i < nr; i += 4) {
				for (int j = nc - 1; j >= 1 && baseK < k; j--) {
					ans[i][j] = '#';
					baseK += 2;
				}
			}

			return ans;
		}

	}
};

/*
int main() {

	MazeConstruct test;
	vector<string> res = test.construct(1000);

	LP(i, 0, res.size())
		cout << res[i] << endl;

	return 0;
}
*/
