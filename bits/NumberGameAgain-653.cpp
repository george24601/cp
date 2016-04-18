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
in the forbidding table,
any # start with the prefix of the bits can not be solved
sort vecotr

 */

class 		NumberGameAgain {
	bool isPrefix(LL small, LL big){

		while(big > small)
			big /= 2;
		return big == small;
	}

	LL numSuf(int k, LL from){
		int nS = 0;
		LL target = pow(2, k) - 1;

		cout << target  << " " << from << endl;

		LL res = 1;
		while(target >= 2 * from){

			from *= 2;
			nS++;
			res += pow(2, nS);
		}

		cout << from << " " << nS <<" " << res << endl;

		return res;
	}

public:
	 long long solve(int k, vector<long long> table){
		 sort(table.begin(), table.end());

		 vector<LL> uniques;

		 LP(i, 0, table.size()){
			 bool hasPrefix = false;
			 LP(j, 0, i){
				 if(isPrefix(table[j], table[i])){
					 hasPrefix= true;
					 break;
				 }
			 }

			 if(!hasPrefix)
				 uniques.push_back(table[i]);
		 }

		 LL res = 0;

		 LP(i, 0, uniques.size())
			 res += numSuf(k, uniques[i]);

		 //return res;
		 return pow(2, k) - 2 - res;
	 }
};

int main() {
	NumberGameAgain test;
	static const int arr[] = {2, 4, 6};
//	static const int arr[] = {2, 3};
	vector<LL> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << test.solve(3, vec) << endl;
	return 0;
}
