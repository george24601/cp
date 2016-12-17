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
 10^2 * 10^6, so brute force would do

 1 << 10

 for each level
 spill to both left and right
 0
 01
 012
 0123

 */

int const MaxSize = 100010;
char s[MaxSize];
int n, k;

int best(char toChange){
	int res = 0;

	int curStart = 0;
	int nextStart = 0;
	int remainingChange = k;

	while(nextStart < n){

		if(toChange == s[nextStart]){

			if(remainingChange == 0){

				while(s[curStart] != toChange)
					curStart++;

				curStart++; //move 1 past

			}else{
				remainingChange--;
			}
		}else{
			//move onto next
		}

		nextStart++;
		res = max(res, nextStart - curStart);
	}

	return res;
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &k);

	scanf("%s", s);

	cout << max(best('a'), best('b'));

	return 0;
}
