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
int const MaxSize = 100010;
PII stars [MaxSize];
int n;
map<PII, int> inverse;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	LP(i, 0, n){
		int x, y;
		scanf("%d %d", &x, &y);
		stars[i] = PII(x, y);
		inverse[PII(x, y)] = i + 1;
	}

	sort(stars, stars + n);

	printf("%d %d ", inverse[stars[0]], inverse[stars[1]]);

	LP(i, 2, n){
		if(stars[i].first != stars[0].first){
			printf("%d\n", inverse[stars[i]]);
			break;
		}
	}


	return 0;
}
