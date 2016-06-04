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
 total(depth, totalWeight, hasOneD){

 	 int res = (totalWeight == 0) && hasOneD ? 1 : 0

 	 if(depth == 0){
 	 	 return res;
 	 }


 	 if(hasOneD){

 	 	 LPE(i, 1, k)
 	 	 	 res += total(depth -1, totaWeight - i, hasOneD || i >= D);
 	 }else{

 	 }
 }

 */
int const MaxSize = 101;
int n, k, d;

LL c[MaxSize][2];

int const MOD = 1000000007;

LL total(LL totalWeight, int hasD){
	if(totalWeight < 0)
		return 0;

	if(c[totalWeight][hasD] >= 0)
		return c[totalWeight][hasD];

	LL res = 0;

	LPE(i, 1, k){
		res += total(totalWeight - i, (hasD || i >= d)? 1: 0);
		res %= MOD;
	}

	return c[totalWeight][hasD] = res;
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d %d", &n, &k, &d);

	LP(i, 0, n)
		memset(c, -1, sizeof(c));

	c[0][1] = 1;
	c[0][0] = 0;

	cout << total(n, 0) << endl;

	return 0;
}
