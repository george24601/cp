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

int N, n, m, X, Y, Z;
int const MaxN = 500000;
int const MOD = 1000000007;

int A[MaxN];
map<int, int> valToID;

int tree[MaxN * 3];
int numLeaves;

void normalize(){
	int sorted[MaxN];
	LP(i, 0, n)
		sorted[i] = A[i];

	sort(sorted, sorted + n);

	LP(i, 0, n){
		int val = sorted[i];
		if (valToID.count(val) == 0){
			valToID[val] = valToID.size();
		}
	}

	numLeaves = valToID.size();
}

bool getFirstBit(int id){
	return true;
}

int removeFirstBit(int id){
	return -1;
}

//start is 0, by assumption
int get(int id){

//	if ()


	return -1;
}

void set(int id, int val){


}

int toID(int val){
	return valToID[val];
}

int main() {
	//freopen("/Users/georgeli/Downloads/C-large-practice.in", "r", stdin);
	freopen("/Users/georgeli/C_1.in", "r", stdin);
	freopen("/Users/georgeli/C_large.out", "w", stdout);

	cin >> N;

	LPE(cn, 1, N){
		cin >> n >> m >> X >> Y >> Z;

		valToID.clear();

		A[0] = 0;
		LP (i, 0, n)
			A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;

		normalize();
		memset(tree, 0, sizeof(tree)); //build tree init all to 0

		LP(i, 0, n){
			int prev = get(toID(A[i]));
			int ans = prev + 1;
			ans %= MOD;
			set(toID(A[i]), ans);
		}

		printf("Case #%d: %d\n", cn, tree[1]);
	}

	return 0;
}
