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

int T;
char c[100];
int numC;
map<char, int> cToDigit;

int main() {

	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/A-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/A_large.out", "w", stdout);

	scanf("%d", &T);

	LPE(cn, 1, T)
	{
		scanf("%s", c);
		numC = strlen(c);

		cToDigit.clear();
		cToDigit[c[0]] = 1;

		LP(i, 1, numC){
			char curC = c[i];

			if (cToDigit.count(curC))
				continue;

			if (cToDigit.size()== 1){
				cToDigit[curC] = 0;
			}else{
				cToDigit[curC] = cToDigit.size();
			}
		}

		LL base = cToDigit.size();

		if (base == 1)
			base++; //base at least 2!

		//printf("%d %d\n", base, cToDigit[c[1]]);

		LL result = 0;

		LL curBase =  1;
		for(int i = numC-1; i >= 0; i--){
			result += cToDigit[c[i]] * curBase;
			curBase *= base;
		}

		printf("Case #%d: %lld\n", cn, result);
	}

	return 0;
}
