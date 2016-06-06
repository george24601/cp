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

suppose n < k and n > k/2, k even

option 1, reduce to

delta + 1

option 2,
1 + 2 * delta , so never move over

if k odd, the last opt must be a sub => done


 */

int const MaxSize = 50010;

int const MOD = 1000000007;

int n,k;

int step(int cur, int target){
	if(cur == target)
		return 0;
	else if(cur > target)
		return cur - target;

	if(target % 2)
		return 1 + step(cur, target + 1);

	if(cur >=  target/2){
		return cur - target/2 + 1;
	}else{
		return 1 + step(cur, target/2);
	}
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &k);

	cout << step(n, k) << endl;
	return 0;
}
