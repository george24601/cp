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
 P disjoint pairs, within each pair, difference no more than D

 smaller => harder, suppose we know D, how to find the pair, can bsearch on D anyway
 start with smallest, see if anything in small + D, if there is, use it, notice we do not waste it anyway



 */

class EllysSocks {

	int numMatches(vector<int>& S, int D) {
		int res = 0;
		int N = S.size();

		bool used[1001];
		memset(used, false, sizeof(used));

		LP(i, 0, N)
		{
			if (used[i])
				continue;

			LP(j,i+1, N)
			{
				if (used[j])
					continue;

				if (S[j] - S[i] <= D) {
					res++;
					used[i] = true;
					used[j] = true;

					//printf("f: %d %d\n", S[i], S[j]);

					break;
				}
			}
		}

		return res;
	}

public:
	int getDifference(vector<int> S, int P) {
		int N = S.size();
		sort(S.begin(), S.end());

		int minD = 0;
		int maxD = S[N - 1] - S[0];

		while (minD < maxD) {
			int mid = (minD + maxD) / 2;

			if (numMatches(S, mid) >= P) {
				maxD = mid;
			} else {
				minD = mid + 1;
			}

//			printf("%d %d %d\n", mid, minD, maxD);
		}

		assert(minD == maxD);
		return minD;
	}
};

/*
int main() {

	EllysSocks test;
	static const int arr[] = { 42, 37, 84, 36, 41, 42 };

	vector<int> vA(arr, arr + sizeof(arr) / sizeof(arr[0]));

	cout << test.getDifference(vA, 2) << endl;

	return 0;
}
*/
