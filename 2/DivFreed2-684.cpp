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

//DP, complete search

/*
 index i, number A,
 next possible one will be all of
 at i+1, B
	A <= B or A mod B != 0 (i.e. A > B), this is equivalent of saying
 
	sum of all ans[i][A] A in [1, K], minus ones where A mod B == 0
 
 
 */
class DivFreed2{
    
    int cache [11][100001];
    
public:
    int count(int n, int k){
        LPE(i, 0, n)
        memset(cache[i], -1, sizeof(cache[i]));
        
        LPE(i,1, k)
        cache[1][i] = 1;
        
        LPE(i, 2, n){
            int prevSum = 0;
            
            LPE(A, 1, k){
                prevSum += cache[i-1][A];
                prevSum %= MOD;
            }
            
            LPE(B, 1, k){
                int bad = 0;
                
                for(int factor = 2; factor * B <= k; factor++){
                    bad += cache[i-1][factor * B];
                    bad %= MOD;
                }
                
                int res = prevSum - bad;
                if(res < 0)
                    res += MOD;
                
                cache[i][B] = res;
                
            }
        }
        
        int total = 0;
        
        LPE(i, 1, k){
            total += cache[n][i];
            total %= MOD;
        }
        
        return total;
    }
};

/*
 int main() {
 DivFreed2 test;
 cout << test.count(2, 2) << endl;
 cout << test.count(9, 1) << endl;
 cout << test.count(3, 3) << endl;
 cout << test.count(1, 107) << endl;
 cout << test.count(2, 10) << endl;
 cout << test.count(2, 1234) << endl;
 cout << test.count(3, 8) << endl;
 cout << test.count(10, 100000) << endl;
 
 return 0;
 }
 */