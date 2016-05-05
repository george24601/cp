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

//DP,graph, complete search
/*
 for the left most, match the one that satistifies

 if only 1 satisfies, mark that
 if only 0 satifies, bad
 if each has more than 1 sats

 */
class SegmentsAndPoints {
public:
	string isPossible(vector <int> p, vector <int> l, vector <int> r){
		int n = p.size();

		bool mP[110];
		memset(mP, false, sizeof(mP));

		bool mSeg[110];
		memset(mSeg, false, sizeof(mSeg));

		while(true){
			bool discovered = false;

			LP(i, 0, n){

				if (mP[i])
					continue; //matched already

				int singleMatch = -1;
				int matchCount = 0;

				LP(j, 0 , n){
					if (mSeg[j])
						continue; //matched already

					if (l.at(j) <= p.at(i) && p.at(i) <= r.at(j)){
						matchCount++;
						singleMatch = j;
					}
				}

				if (0 == matchCount)
					return "Impossible";
				else if (1 == matchCount){
					discovered = true;
					mP[i] = true;
					mSeg[singleMatch] = true;
				}
			}

			if(!discovered)
				break;
		}

		return "Possible";
	}
};

int main(){
	return 0;
}
