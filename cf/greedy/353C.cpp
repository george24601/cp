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

if there is no 0 in cycle
n-1
if there is 0 in cycle
n - longest dist between 0s

find first p, s.t., b[p] = 0
start = p
end = p -1 (or n)

while(p < start)
	if(b[p] == 0)
		curLen++;
		p++
	else
		update maxCurLen
		while(p < start && b[p] != 0)

//case all 0
//case no 0
//case n = 1 or 2

while(p < start)
	int curLen = 0;

	while(b[p] == 0 && p < start)
		curLen++;
		p = (p+1) % n;

	update maxcurLen

	while(b[p] != 0 && p < start)
		p = (p+1) % n;

 */

int const MaxSize = 100010;

int n;
int a[MaxSize];

int findStart(){
	if(0 == a[0]){
		for(int i = n-1; i >= 0; i--){
			if(a[i] != 0)
				return (i+1) % n;
		}
	}else{
		LP(i, 0, n){
			if(0 == a[i])
				return i;
		}
	}

	return -1;
}

int main() {
	freopen("/Users/georgeli/A_1.in", "r", stdin);
	scanf("%d", &n);

	LP(i, 0, n)
		scanf("%d", &a[i]);

	int numZ = 0;
	LP(i, 0, n){
		if(a[i] == 0)
			numZ++;
	}

	if(0 == numZ) {//no zero
		printf("%d\n", n-1);
		return 0;
	}
	else if(n == numZ){
		printf("%d\n", 0);
		return 0; //all zero
	}

	int start = findStart();

	assert(start >= 0);

	int p = start;
	int curMax = 0;

	//cout << "start:" << start << endl;

	while(true){
		int curLen = 0;

		while(a[p] == 0){
				curLen++;
				p = (p+1) % n;
		}

		curMax = max(curMax, curLen);

		while(a[p] != 0){
				p = (p+1) % n;
		}

		if(p == start)
			break;
	}

	printf("%d\n", n - curMax - 1);


	return 0;
}
