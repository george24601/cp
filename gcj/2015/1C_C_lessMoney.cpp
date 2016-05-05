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
 consider the first # unable to form with exisitng ones v1

 if new deno d  < v1

 c1 * (v1 - delta) + v' (v' < v1) = c1v1 + v' - c1 * delta

 v' < v1, i.e, if we introduce d, we might as well introduce v1!

curV
newCount
int dI

while(curV < V){

	if (curV >= deno[dI])
		curV += C * deno[dI]
		dI++
	else
		curV = C * (curV + 1)//new deno
		newCount++;
}



 */

int C, D;
UL V;
int deno[110];

int process(){
	UL curV = C;
	int newCount = deno[0] == 1 ? 0 : 1;
	int dI = deno[0] == 1 ? 1 : 0;

	while(curV < V){
		if (dI < D && curV >= deno[dI] - 1){ //can form next one
			curV = curV + C * (UL)deno[dI];
			assert(curV >= 0);
			dI++;
		}else{
			//printf("%d\n", curV);

			curV += C * (curV + 1); //new deno
			assert(curV >= 0);
			newCount++;
		}
	}

	return newCount;
}

int main() {
	//freopen("/Users/georgeli/C_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/C-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/C_large.out", "w", stdout);

	int T;

	scanf("%d", &T);
	//printf("%d\n", T);

	LPE(cn, 1, T)
	{
		scanf("%d %d %ld", &C, &D, &V);
		//printf("%d %d %d\n", C, D, V);

		LP(i, 0, D)
			scanf("%lld", &deno[i]);

		UL result = process();

		printf("Case #%d: %d\n", cn, result);

	}

	return 0;
}
