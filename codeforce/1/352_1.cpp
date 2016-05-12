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
 n <= 1000

 int prev = 0;
 LP(num, 1, n) {
 	 numToString
 	 if (prev + numToString.length >= n)
 	 	 return
 	else
 		prev +=

 }


 */


int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-large.in", "r", stdin);
	//freopen("/Users/georgeli/B_large.out", "w", stdout);

	int n;

	scanf("%d", &n);

	int prev = 0;

	LPE(i, 1, n){
		string s = to_string(i);

		if(prev + s.length() >= n){
			printf("%c\n", s[n - prev - 1]);
			return 0;
		}else
			prev += s.length();
	}

	return 0;
}
