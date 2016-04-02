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
#define MOD 1000000007

/*
if already sorted: 0
if head is at 0: 1
if tail is at n-1: 1
if both head and tail in [1,n-2]: 2
if head at n-1, tail in the middle: 2
if tail at 0, head....: 2
else, 3

*/

class 	BearSlowlySorts{


public:
	int minMoves(vector <int> w){
		vector<int> target = w;
		sort(target.begin(), target.end());
		int n = w.size();

		bool isSorted = true;
		LP(i, 0, n){
			if(w[i] != target[i]){
				isSorted = false;
				break;
			}
		}

		if(isSorted)
			return 0;
		else if(target[0] == w[0] || target[n-1] == w[n - 1])
			return 1;
		else if(target[0] == w[n - 1] && target[n - 1] == w[0])
			return 3;
		else
			return 2;

    	return 0;
    }
};

int main() {
}
