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
 max dis = min(0, n - 1 - a);

 for

 */

int const MaxSize = 110;
int n, a;
int t[MaxSize];

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &a);

	a--;

	LP(i, 0, n)
		scanf("%d", &t[i]);

	int dist, startOut, endOut;

	if(a < n/2){
		dist = a;
		startOut = a + dist + 1;
		endOut = n -1;
	}else{
		dist = n - 1 - a;
		startOut = 0;
		endOut = a - dist - 1;
	}

	int res = 0;
	if(t[a])
		res++;

	LPE(d, 1, dist){
		if(t[a-d] && t[a + d])
			res += 2;
	}

	LPE(i, startOut, endOut){
		if(t[i])
			res++;
	}

	cout << res << endl;

	return 0;
}
