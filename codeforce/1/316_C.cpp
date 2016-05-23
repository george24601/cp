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
 total num = total size - # of segs

if . -> l
	++ if both are .
	-- if both are l
if l -> .
	-- if boht are .
	++ if both are l


 */

int const MaxSize = 300010;

int n, m;
char s [MaxSize];
bool isP[MaxSize];

int main() {
	freopen("/Users/georgeli/A_1.in", "r", stdin);
	scanf("%d", &n, &m);

	scanf("%s", s);

	int numSeg = 0;
	int length = 0;

	LP(i, 0, n){
		isP[i + 1] = '.' == s[i];
		if(isP[i + 1]){
			length++;

			if(i == 0 || '.' != s[i-1])
				numSeg++;
		}
	}

	isP[0] = true; //assume both ends always 0
	isP[n + 1] = true;

	LP(qi, 0, m){
		int i;
		char c;
		scanf("%d %c", &i, &c);

		bool addP = '.' == c;

		if (addP == isP[i])
			continue;

		addP ? length++ : length--;

		bool same = i == 1 || i == n ||  isP[i - 1] ==  isP[i + 1];

		if(!same)
			numSeg--;












		printf("%d\n", numSeg - length);
	}

	return 0;
}
