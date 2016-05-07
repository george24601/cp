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
consider the sequence a, c, b, d, all distinct
swap between a and 1
c and 2,
d and n-3
b and n;

add a map, add both theory to actual alias

first path
1...n, print alias[num]

second path

2 .... n-4 -> 1 -> n-1 -> n -> n-2 -> n-3

so alias
1 -> a
n -> b
2 -> c
n-3 -> d
a -> 1
b -> n
c -> 2
d -> n - 3

others same

a-> c...p->d->q->b

c..p->a->q -> b -> d

set of unused ids;

get set of unused ids;

take one for p, one for q

remaining will be the one between c and p, exclusive


 */

int n, k, a, b, c, d;
int const MaxSize = 5001;

vector<int> unused;
int p, q;

void printP(vector<int>& p){
	printf("%d", p[0]);

	LP(i, 1, p.size())
		printf(" %d", p[i]);

	printf("\n");
}

void ab(){
		//a-> c...p->d->q->b
	vector<int> ab;
	ab.push_back(a);
	ab.push_back(c);

	int unusedSize = unused.size();

	LP(i, 2, unusedSize)
		ab.push_back(unused[i]);

	ab.push_back(p);
	ab.push_back(d);
	ab.push_back(q);
	ab.push_back(b);

	printP(ab);
}

void cd(){
//	c..p->a->q -> b -> d

	int unusedSize = unused.size();
	vector<int> cd;
	cd.push_back(c);

	LP(i, 2, unusedSize)
		cd.push_back(unused[i]);

	cd.push_back(p);
	cd.push_back(a);
	cd.push_back(q);
	cd.push_back(b);
	cd.push_back(d);


	printP(cd);
}

int main() {
	freopen("/Users/georgeli/B_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-small-attempt1.in", "r", stdin);
	//freopen("/Users/georgeli/B_1.out", "w", stdout);

	scanf("%d %d", &n, &k);

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if(k < (n - 1) + 3 || n < 6){
		printf("-1\n");
		return 0;
	}


	unused.clear();
	LPE(i, 1, n){
		if(i != a && i != b && i != c && i != d)
			unused.push_back(i);
	}

	p = unused[0];
	q = unused[1];

	ab();
	cd();

	return 0;
}
