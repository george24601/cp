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
 h <= d <= 2h

 new root =

 */

int const MaxSize = 101;

int const MOD = 1000000007;

SAL results;
int p,b;
int n, m;

void init(){
	int curCount = 1 << n;
	LPE(level, 1, n){
		curCount /= 2;

		LP(i, 0, curCount){
			int first = results[level - 1][i * 2];
			int second = results[level - 1][i * 2 + 1];
			results[level].push_back(level % 2 ? first | second : first ^ second);
		}

		//cout << level << " " << results[level].size() << endl;
	}
}

void update(){
	results[0][p-1] = b;

	int changedP = p - 1;

	LPE(level, 1, n){

		int affected = changedP / 2;
		int first = results[level - 1][affected * 2];
		int second = results[level - 1][affected * 2 + 1];

		//cout << level << " " << affected << endl;
		results[level][affected] = level % 2 ? first | second : first ^ second;
		changedP = affected;
	}
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d %d", &n, &m);

	results = SAL(n + 1);

	LP(i, 0, (1 << n)){
		int num;
		scanf("%d", &num);

		results[0].push_back(num);
	}

	init();


	LP(i, 0, m){
		scanf("%d %d", &p, &b);
		update();
		printf("%d\n", results[n][0]);
	}


	//print remaining
	return 0;
}
