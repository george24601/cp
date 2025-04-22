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
 if bottom is +s, ignore
 if bottom is -s, we must flip the whole once
 WLOG, assume only 1 +s and -s, since bottom -s are the bad parts anyway, and top is +
 min # of flip = 2 * - under +s + 1 if top is -

 proof: induciton
 - => obvious 1
 +- => obvious 2
 (+-)* => no matter which seg we pick, # of inverse reduced by 1, but with top -, same as induciton

 scan through

 if s[i] is -
 	 total++;
 	 while(s[i] == -)
 	 i++

 while(i < len)
 	 while(i < len and s[i] is +)
 	 i++

 	 if(i < len)
 	 	 total +=2;

 	 while(i < len and s[i] is -)
 	 	 i++
 */


int main() {
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/B-large.in", "r", stdin);
	freopen("/Users/georgeli/B_large.out", "w", stdout);

	int T;

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		string s;
		cin >> s;

		int total = 0;

		int i = 0;
		int n = s.length();
		if ('-' == s[0]){
			total++;

			while(i < n && '-' == s[i])
				i++;
		}

		while(i < n){

			while(i < n && '+' == s[i])
				i++;

			if(i < n)
				total += 2; //pair found!

			while(i < n && '-' == s[i])
				i++;
		}

		printf("Case #%d: %d\n", cn, total);
	}

	return 0;
}
