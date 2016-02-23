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

read string

find smallest suffix that forms i
finds smallest suffix that forms j

compare that with total sum


 */

int T, L;
LL X;

int const MaxL = 10010;
char seg [MaxL];

int prodTable [5][5] = {
		{0,0,0,0,0},
		 {0,1,2,3,4},
		 {0,2,-1,4, -3 },
		 {0, 3,-4,-1, 2 },
		 {0, 4,3,-2, -1 },
		 };

int multiply(int first, int second){
	bool inverse = false;

	if (first < 0){
		inverse = !inverse;
		first *= -1;
	}

	if (second < 0)
	{
		inverse = !inverse;
		second *= -1;
	}

	assert(first != 0 && second != 0);

	return prodTable[first][second] * (inverse ? -1 : 1);
}

int findPrefix(int startI, int target, int maxLimit){
	int curProduct = 1;

//	printf("%d %d\n", iIndex, jIndex);

	LP(i, startI, maxLimit){
		int curChar = seg[i % L] - 'i' + 2;
		//printf("%d newChar: %d\n", curProduct, curChar);

		curProduct = multiply(curProduct, curChar);

		//printf("newProd: %d\n", curProduct);

		if (curProduct == target)
			return i;
	}

	return -1;
}

int power_r(int segProd, LL times){
	if(times == 1) return segProd;

	int half = power_r(segProd, times/2);
	int result = multiply(half, half);

	if (times % 2)
		result = multiply(result, segProd);

	return result;
}

int calcTotal(){
	int segProd = 1;

	LP(i, 0, L)
		segProd = multiply(segProd, seg[i] - 'i' + 2);

	return power_r(segProd, X);
}

int main() {

	//freopen("/Users/georgeli/C_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/C-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/C_large.out", "w", stdout);

	scanf("%d", &T);
	//printf("%d\n", T);

	LPE(cn, 1, T)
	{
		scanf("%d %lld", &L, &X);

//		printf("%d %d\n", L, X);
		scanf("%s", seg);

//		printf("%s\n", seg);

		LL four = 4;
		int iIndex = findPrefix(0, 2, min(X, four) *L);
		//printf("iIndex: %d\n", iIndex);
		int jIndex = iIndex >= 0 ? findPrefix(iIndex + 1, 3, min(X,2 * four) *L) : -1;


		int overall = calcTotal();

		if(iIndex >= 0 && jIndex >= 0 && overall == -1)
			printf("Case #%d: YES\n", cn);
		else
			printf("Case #%d: NO\n", cn);

	}


	return 0;
}
