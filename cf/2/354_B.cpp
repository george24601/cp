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
 so for each class
if class is edge
speed[class] = speed [parent]
speed[class] = speed[left parent] + speed[right parent]

consider after a level is completely full => no impossible

for edge
time [edge] = time[edge's parent] + twice time to fill the parent

(time [middle] -time [parent left ]) * leftSpeed + (time[middle]- time[parent right]) * rightSpeed = 1



so we know the speed of each stream anyway => each side

so 2 moments
1. the parent level is full
=> each stream gives 1 / (2 * level) => not really,

claim:
a child can not be filled until both parents are filled
if a child is filled => both parents are filled
similarly, parital fill can not exist in 3 levels

so we know the speed to fill edges, 1/2, 1/4, 1/8...
given t, we know the max level is at

remaining time >= level - 1


 */

int const MaxSize = 10010;

int main() {
	freopen("/Users/georgeli/A_1.in", "r", stdin);
	int n, t;

	scanf("%d %d", &n, &t);

	int total = 0;

	int remaining = t;

	int level = 1;

	for(;level <= n; level++){
		int curTime = pow(2, level - 1);

		if(remaining >= curTime){
			total += level;
			remaining -= curTime;
		}else{
			break;
		}
	}

	if (n == level){
		cout << total << endl;
		return 0;
	}

	int curTime = pow(2, level - 1);

	if (remaining > curTime){
		total += level - 1;
		remaining -= curTime;

		if(remaining > curTime/2){
			total += level - 2;
		}
	}



	return 0;
}
