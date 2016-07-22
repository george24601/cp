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
 */


int n;
int const MaxSize = 1000000;

int s[MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	LP(i, 0, n)
		scanf("%d", &s[i]);

	sort(s, s + n);

	int smallI = 0;

	int res = 0;

	int bigStart = n/2;

	LP(bigI, bigStart, n){

		if(smallI >= bigStart)
			break;

		if(s[bigI] >= s[smallI] * 2){
			res++;
			smallI++;
		}
	}

	cout << n - res << endl;


	return 0;
}

