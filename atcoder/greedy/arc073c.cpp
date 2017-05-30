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

#define INF 1e16
const int MaxSize = 200000 + 10;
const LL MOD = 1e9 + 7;

int N;
PII bag[MaxSize];

int main() {

	ios_base::sync_with_stdio(false);
	//freopen("/Users/george/A_1.in", "r", stdin);
	cin >> N;

	LL bMin = 1e9;
	LL bMax = 0;
	LL gMax = 0;
	LP(i, 0 , N)
	{
		LL x, y;
		cin >> x >> y;
		LL blue = max(x, y);
		bag[i] = PII(min(x, y), blue);

		bMin = min(bMin, blue);
		bMax = max(bMax, blue);
		gMax = max(gMax, blue);
	}

	sort(bag, bag + N);

	int rMin = bag[0].first;
	int rMax = bag[N - 1].first;
	LL ans = (LL) (rMax - rMin) * (LL) (bMax - bMin);

	//cout << rMax << " " << rMin << " " << bMax << " " << bMin << endl;

	bMax = gMax;
	bMin = bag[0].first;

	LP(i, 0, N - 1)
	{
		if(rMin == bag[i].first){
			rMin = min(bag[i].second, bag[i + 1].first);
		}

		rMax = max(rMax, bag[i].second);

		LL newAns = (LL) (rMax - rMin) * (LL) (bMax - bMin);

	//	cout << rMax << " " << rMin << " " << bMax << " " << bMin << endl;

		ans = min(ans, newAns);
	}

	cout << ans << endl;

	return 0;
}
