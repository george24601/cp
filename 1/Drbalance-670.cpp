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
 1. change it at the head, than tail will affect more prefixes
 2. we need to change from neg to pos

 for each char
 	 if +, ignore
 	 else, try swaping


*/

class 	Drbalance{

	bool good(string s, int k){
		int balance = 0;
		int totalNeg = 0;

		LP(i, 0, s.length()){
			if(s[i] == '+')
				balance++;
			else
				balance--;

			if(balance < 0){
				totalNeg++;
				if(totalNeg > k)
					return false;
			}

		}

		return true;
	}

public:
	int lesscng(string s, int k){
		int i = 0;
		int n = s.length();

		int ans = 0;

		while(!good(s,k)){

			while(i < n && s[i] == '+')
				i++;

			if(i == n)
				break; //end of search

			ans++;
			s[i] = '+';
		}

		return ans;
	}
};
