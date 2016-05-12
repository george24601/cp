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
 if s length > 26: impossible -1
 if s length <= 26: find # of distinct numbers
 change to s length - current # of distincts


 */

int const MaxSize = 50;

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-large.in", "r", stdin);
	//freopen("/Users/georgeli/B_large.out", "w", stdout);

	int n;

	scanf("%d", &n);

	if(n > 26){
		printf("-1\n");
		return 0;
	}

	char word [MaxSize];

	scanf("%s", word);

	set<char> uniques;

	LP(i, 0, n)
		uniques.insert(word[i]);

	printf("%d\n", n - uniques.size());

	return 0;
}
