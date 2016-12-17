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


 */

int const MaxSize = 1010;
int n, m;
int w[MaxSize], b[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &m);

	//cout << n << m << endl;

	LPE(i, 1, n)
		scanf("%d", &w[i]);

	LPE(i, 0, m)
		scanf("%d", &b[i]);

	LL ans = 0;

	LP(i, 0, m){
		bool toMove[MaxSize];

		memset(toMove, false, sizeof(toMove));

		for (int j = i-1; j >= 0; j--){
			if(b[j] == b[i])
				break; //processed everything already

			if(toMove[b[j]])
				continue; //moved already, no need to double count

			toMove[b[j]] = true;
			ans += w[b[j]];
		}
	}

	cout << ans << endl;
}

