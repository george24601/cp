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
using namespace std;

typedef unsigned long long L;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
typedef pair<int, int> PII;
#define INF 2000000000
#define Ep 1e-9

/*
 from each station
 	 arriaval time + T=> populate previous ready time with the other station

 so for each station, we have readys  and departures
 j = 0
 i = 0
 while(i < sizeDeparture)
 {
 	 if (readys[j] == departures[i])
 	 {
 	 	 	 //dispatch the current train
 	 	 	  i++;
 	 	 	  j++;
 	 }else if (ready[j] < departures[i]){
 	 	 	 //dispatch the current train
 	 	 	  i++;
 	 	 	  j++;
 	 }else if (ready[j] > departures[i]) {
 	 	 i++
 	 	 numtrain++
 	 	 //need a new train
 	 }
 }

 */

int N, NA, NB, T;
vector<int> depA;
vector<int> readyA;
vector<int> depB;
vector<int> readyB;
string str;

int toMins(string str){
	int hrs = (str[0] - '0') * 10 + (str[1] - '0');
	int mins = (str[3] - '0') * 10 + (str[4] - '0');

	return hrs * 60 + mins;
}

int process(vector<int>& dep, vector<int>& ready){
	int res = 0;
	sort(dep.begin(), dep.end());
	sort(ready.begin(), ready.end());

	int j = 0;

	LP(i, 0, dep.size()){

		if (j == ready.size()){
			res++;
			continue;
		}

		if(dep[i] >= ready[j]){
			j++;
		}else {
			res++;
		}
	}

	return res;
}

int main() {
	freopen("/Users/georgeli/Downloads/B-large-practice.in", "r", stdin);
	//freopen("/Users/georgeli/qual_B.in", "r", stdin);
	freopen("/Users/georgeli/B_small.out", "w", stdout);

	cin >> N;

	LPE(cn, 1, N){
		cin >> T >> NA >> NB;

		depA.clear();
		readyA.clear();
		depB.clear();
		readyB.clear();

		LP(i, 0, NA){
			cin >> str;
			depA.push_back(toMins(str));

			cin >> str;
			readyB.push_back(toMins(str) + T);
		}

		LP(i, 0, NB){
			cin >> str;
			depB.push_back(toMins(str));

			cin >> str;
			readyA.push_back(toMins(str) + T);
		}

		printf("Case #%d: %d %d\n",cn, process(depA, readyA), process(depB, readyB));
	}

	return 0;
}
