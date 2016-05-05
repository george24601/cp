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

 consider the case where all have same length
 max increase = first digit to max digit
 after increase is done, similar to the next phase
 max 1 * 10^6

 digits from 6....1

 create a subvector, so that all with same length

 start with first, try to find a higher one
 if there is , replace it, total score + base * diff

 mod on all things, and resort


 */

class ReplacingDigit {

	int round(vector<int>& sameLen, vector<int>& D) {
		int res = 0;

		sort(sameLen.begin(), sameLen.end());

		int N = sameLen.size();
		int dI = 8;

		LP(i, 0, N)
		{
			while (dI >= 0 && 0 == D[dI])
				dI--;

			if (dI < 0)
				return res; //no stickers

			if (sameLen[i] < (dI + 1)) {
				res += (dI + 1) - sameLen[i];
				D[dI] -= 1; //use 1 sticker
			} else
				return res; //no point trying other stickers
		}

		return res;
	}

public:
	int getMaximumStockWorth(vector<int> A, vector<int> D) {
		int N = A.size();

		int res = 0;

		for (int nd = 6; nd >= 0; nd--) {
			vector<int> toProcess;
			int base = pow(10, nd);
			LP(i, 0, N)
			{
				if (A[i] >= base) {
					toProcess.push_back((A[i] / base) % 10); //only take 1 digit
				}
			}

			res += round(toProcess, D) * base;
		}

		LP(i, 0, N)
			res += A[i];

		return res;
	}
};

/*
int main() {

	ReplacingDigit test;
	//static const int arr[] = { 100, 90 };
//	static const int D[] = {0, 0, 0, 0, 2, 1, 0, 0, 0};

	static const int arr[] = {123456}; //{9};
	static const int D[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; //{1, 1, 1, 1, 1, 1, 1, 1, 0};

	vector<int> vA(arr, arr + sizeof(arr) / sizeof(arr[0]));
	vector<int> vD(D, D + sizeof(D) / sizeof(D[0]));

	cout << test.getMaximumStockWorth(vA, vD) << endl;

	return 0;
}
*/
