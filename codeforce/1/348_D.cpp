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
 so read all inputs
 for each commands,
 apply to both 1 and 2

 for final input, populate 1, 3, 5...n-1
 and 2,4...,n




 */

int const MaxSize = 1000010;

int n, q;

int shift(int i, int move){
	int res = i + move;

	if(res > n)
		return res - n;
	else if(res <= 0)
		return res + n;
	else
		return res;
}

int swap(int i){
	if (i % 2)
		return shift(i,1);
	else
		return shift(i,-1);
}


int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	scanf("%d %d", &n, &q);

	int p1 = 1;
	int p2 = 2;

	LP(i, 0, q){
		int type;
		scanf("%d", &type);

		if(1 ==type){
			int amt;
			scanf("%d", &amt);

			p1 = shift(p1, amt);
			p2 = shift(p2, amt);
		}else{
			p1 = swap(p1);
			p2 = swap(p2);
		}
	}

	int ans[MaxSize];

	ans[1] = p1;
	ans[2] = p2;

	LPE(i, 3, n)
		ans[i] = shift(ans[i-2], 2);


	int toShow[MaxSize];

	LPE(i, 1, n)
		toShow[ans[i]] = i;

	printf("%d", toShow[1]);

	LPE(i, 2, n)
		printf(" %d", toShow[i]);

	printf("\n");

	return 0;
}
