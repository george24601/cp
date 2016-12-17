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
int const MaxSize = 100010;

int inv[MaxSize];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	LPE(i, 1, n){
		int num;
		scanf("%d", &num);
		inv[num] = i;
	}

	int best = 0;
	int curLen = 1;

	LPE(v, 2, n){
		if(inv[v - 1] < inv[v]){
			curLen++;
		}else{
			best = max(best, curLen);
			curLen = 1;
		}
	}

	best = max(best, curLen);

	cout << n - best << endl;

	return 0;
}

