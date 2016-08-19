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

int const MaxSize = 200010;
int n, m, a[MaxSize], b[MaxSize];

int aS, bS, bestA, bestB;

void tryUpdate() {
	//cout << aS << " " << bS << endl;

	if (aS - bS > bestA - bestB) {
		bestA = aS;
		bestB = bS;
	} else if (aS - bS < bestA - bestB) {

	} else if (aS > bestA) {
		bestA = aS;
		bestB = bS;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	vector<int> ds;
	ds.push_back(0);

	scanf("%d", &n);

	LP(i, 0, n){
		scanf("%d", &a[i]);
		ds.push_back(a[i]);
	}

	sort(a, a + n);

	scanf("%d", &m);

	LP(i, 0, m){
		scanf("%d", &b[i]);
		ds.push_back(b[i]);
	}

	sort(b, b + m);
	sort(ds.begin(), ds.end());

	aS = bestA = 3 * n;
	bS = bestB = 3 * m;

	int aI = 0;
	int bI = 0;

	LP(dI, 0, ds.size()){

		int d = ds[dI];

		while(aI < n && a[aI] <= d){
			aS--;
			aI++;
		}

		while(bI < m && b[bI] <= d){
			bS--;
			bI++;
		}

		tryUpdate();
	}


	printf("%d:%d\n", bestA, bestB);

	return 0;
}

