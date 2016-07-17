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
sort by value,



 */

int const MaxSize = 1000000;
int n;
int nums[MaxSize];
map<int, int> expect;
vector<int> discovered;

int gcd(int a, int b){
	if(b % a == 0)
		return a;
	else
		return gcd(b%a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	scanf("%d", &n);

	int numIn = n * n;

	LP(i, 0, numIn)
		scanf("%d", &nums[i]);

	sort(nums, nums + numIn);

	for(int i = numIn - 1; i >= 0; i--){
		int newN = nums[i];

		if(expect[newN]){
			expect[newN]--;
		}else{

			LP(j, 0, discovered.size()){
				int newGCD = gcd(newN, discovered[j]);
				expect[newGCD] +=2;
			}

			discovered.push_back(newN);
		}
	}

	assert(discovered.size() == n);

	LP(i, 0, n)
	{
		cout << discovered[i];

		if(i == (n - 1))
			cout << endl;
		else
			cout << " ";
	}

	return 0;
}

