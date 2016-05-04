#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

 */

class GerrymanderEasy {
	 double getPM(vector <int>& A, vector <int>& B, int K){

		 int N = A.size();
		 LL totalY = 0;
		 LL totalX = 0;

		 double res = 0;

		 LP(i, 0, K){
			 totalY += A[i];
			 totalX += B[i];
		 }

		 res = (double)totalX / (double) totalY;
		 //cout << res << endl;

		 LP(i, K, N){
			 totalY += A[i];
			 totalY -= A[i - K];

			 totalX += B[i];
			 totalX -= B[i - K];

			 double temp = (double)totalX / (double) totalY;

			// cout << temp << endl;

			 res = max(res, temp);
		 }


		 return res;
	 }


public:
	 double getmax(vector <int> A, vector <int> B, int K){

		 int N = A.size();

		 double res = 0;

		 LPE(k, K, N){
			 res = max(res, getPM(A, B, k));
		 }

		 return res;
	 }
};

int main() {


	GerrymanderEasy test;
	static const int arr[] = {5,1,2,7};

	vector<int> vA(arr, arr + sizeof(arr) / sizeof(arr[0]));

	static const int arrB[] = {4,0,2,2};
	vector<int> vB(arrB, arrB + sizeof(arrB) / sizeof(arrB[0]));
	cout << test.getmax(vA, vB, 2) << endl;

	return 0;
}
