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
 suppose there is no forbidding row

 min possible => tree with depth 1, i.e, every one to root
 */

int const MaxSize = 310;

int const MOD = 1000000007;

int n;

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int n, m;

	set<int> bads;

	scanf("%d %d" , &n, &m);

	LP(i, 0, m){
		int first, second;
		scanf("%d %d", &first, &second);
		bads.insert(first);
		bads.insert(second);
	}

	int center = 1;

	while(center <= n){
		if(!bads.count(center))
			break;
		else
			center++;
	}


	printf("%d\n", n -1);

	LPE(node, 1, n){

		if(node == center)
			continue;
		else
			printf("%d %d\n",center, node);
	}




	return 0;
}
