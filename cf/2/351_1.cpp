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
 find the first gap >= 15
 return start of gap + 15

 */

int const MaxSize = 100;
int goods [MaxSize];
int n;

int main() {
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-small-attempt1.in", "r", stdin);
	//freopen("/Users/georgeli/B_1.out", "w", stdout);

	scanf("%d", &n);


	LP(i, 0, n)
		scanf("%d", &goods[i]);

	int ans = 0;
	if(goods[0] > 15){
		ans = 15;
	}else{
		int lastSeg = goods[n-1] + 15;
		ans = lastSeg >= 90 ? 90 : lastSeg;

		LP(i, 0, n - 1){
			if (goods[i + 1] - goods[i] > 15){
				ans = goods[i] + 15;
				break;
			}
		}
	}

	printf("%d\n", ans);

	return 0;

}
