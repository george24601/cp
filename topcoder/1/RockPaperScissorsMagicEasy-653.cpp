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
count(n, score) = 2 * card(n-1, score) + card(n-1, score -1)




 */

class 	RockPaperScissorsMagicEasy {
public:
	int count(vector <int> card, int score){
		int N = card.size();
		int res [2001][2001];

		LP(i, 0, N)
			memset(res[i], 0, sizeof(res[i]));

		res[1][0] = 2;
		res[1][1] = 1;

		LPE(n, 2, N){
			LPE(s, 0, score){
				res[n][s] = 2 * res[n-1][s];
				res[n][s] %= MOD;

				if(s > 0){
					res[n][s] += res[n-1][s - 1];
					res[n][s] %= MOD;
				}
			}
		}



		return res[N][score];
	}
};

/*
int main() {
	RockPaperScissorsMagicEasy test;
	static const int arr[] = {1,2};
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << test.count(vec, 0);
	return 0;
}
*/
