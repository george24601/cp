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


 */

class ExactTreeEasy {
public:
	vector<int> getTree(int n, int m){

		vector<int> res;

		LP(i, 0, n-m){ //not n-m+1, because last one has no outgoing edge
			res.push_back(i);
			res.push_back(i+1);
		}

		LP(i, n-m+1, n){
			res.push_back(0);
			res.push_back(i);
		}

		return res;
	}
};

int main() {
	return 0;
}
