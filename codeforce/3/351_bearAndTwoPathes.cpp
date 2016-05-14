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
 first path
 a -> c->p1....p2-> d -> b

 second path
 c->a ->p1...p2->b ->d

 so n+1 additional edges needed

 print p1 to p2


 */

int n, k, a, b, c, d;
int const MaxSize = 5001;

vector<int> unused;

void printP(vector<int>& p){
	printf("%d", p[0]);

	LP(i, 1, p.size())
		printf(" %d", p[i]);

	printf("\n");
}

void ab(){
		//a-> c->p...q->d->b
	vector<int> ab;
	ab.push_back(a);
	ab.push_back(c);

	int unusedSize = unused.size();

	LP(i, 0, unusedSize)
		ab.push_back(unused[i]);

	ab.push_back(d);
	ab.push_back(b);

	printP(ab);
}

//c->a->p...q->b->d
void cd(){

	int unusedSize = unused.size();
	vector<int> cd;
	cd.push_back(c);
	cd.push_back(a);

	LP(i, 0, unusedSize)
		cd.push_back(unused[i]);

	cd.push_back(b);
	cd.push_back(d);

	printP(cd);
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	//freopen("/Users/georgeli/Downloads/B-small-attempt1.in", "r", stdin);
	//freopen("/Users/georgeli/B_1.out", "w", stdout);

	scanf("%d %d", &n, &k);

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if(k < (n -1)  + 2 || n < 5){
		printf("-1\n");
		return 0;
	}

	unused.clear();

	LPE(i, 1, n){
		if(i != a && i != b && i != c && i != d)
			unused.push_back(i);
	}

	ab();
	cd();

	return 0;
}
