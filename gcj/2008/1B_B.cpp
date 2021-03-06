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
 each number is broken down to a prime factor < sqrt(n)

 notice that, we can not have prime factor > sqrt(n), because that would imply the difference of two #s greater than the given range

 i.e.,

 first generate all #'s

 for each prime #,
 we union them with the prime factor

 in the end, find all distinct parents
 */

#define MaxSize 2000010

int parent[MaxSize];
LL Find(LL a) {
	//assumption: parent[a] is set to a on init
	if (parent[a] != a)
		parent[a] = Find(parent[a]);

	return parent[a];
}

void Union(LL a, LL b) {

	LL aP = Find(a);
	LL bP = Find(b);

	if (aP == bP)
		return;

	parent[max(aP, bP)] = min(aP, bP);
}

bool prime[MaxSize];

void sieve(){

  memset(prime, true, sizeof(prime));

  LP(i, 2, MaxSize){
    if(!prime[i])
      continue;

    int factor = 2;
    while(i * factor < MaxSize){
      prime[i* factor] = false;
      factor++;
    }
  }
}

int C;
LL A, B, P;

int const HalfSize = 1000000;

int toWithinRange(LL large){
	if (large <= HalfSize)
		return large;
	else
		return HalfSize + large - A + 1;
}

int process(){

	//cout << A << " " << B << " " << P << endl;

	for(LL num = P; num <= B - A; num++){

		if (!prime[num])
			continue;

		LL factor = A/num + (A % num == 0 ? 0 : 1);

		while(num * factor <= B){

	/*
			cout << num << " " << factor << endl;
	*/

			Union(toWithinRange(num* factor), num);

			factor++;
		}
	}

	set<LL> distinctParents;

	for(LL num = A; num <= B; num++){

		distinctParents.insert(Find(toWithinRange(num)));

		//cout << num << " " << Find(num) << endl;
	}

	return distinctParents.size();
}

void reset(){
	LP(i, 0, MaxSize)
		parent[i] = i;
}

int main() {
	freopen("/Users/georgeli/Downloads/B-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/B_1.in", "r", stdin);
	freopen("/Users/georgeli/B_large.out", "w", stdout);

	sieve();

	cin >> C;
	LPE(cn, 1, C)
	{
		reset();
		cin >> A >> B >> P;

		printf("Case #%d: %d\n", cn,  process());
	}

	return 0;
}
