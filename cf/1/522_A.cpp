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
 total(depth, totalWeight, hasOneD){

 int res = (totalWeight == 0) && hasOneD ? 1 : 0

 if(depth == 0){
 return res;
 }


 if(hasOneD){

 LPE(i, 1, k)
 res += total(depth -1, totaWeight - i, hasOneD || i >= D);
 }else{

 }
 }

 */
int const MaxSize = 101;
int n, k, d;

int const MOD = 1000000007;

SAL graph;

map<string, int> nameToID;

int toID(string name) {
	if (nameToID.count(name) == 0) {
		nameToID[name] = nameToID.size();
	}

	return nameToID[name];
}

int DFS(int id) {

	int maxD = 0;

	LP(i, 0, graph[id].size())
	{
		maxD = max(maxD, DFS(graph[id][i]));
	//	cout << graph[id][i] << endl;
	}

	return maxD + 1;
}

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	int n;
	cin >> n;

	graph = SAL(n + 1);

	LP(i, 0, n)
	{
		string c, m, p;
		cin >> c >> m >> p;

		LP(ci,0, c.size()){
			if(c[ci] >= 'A' && c[ci] <= 'Z')
				c[ci] -= ('A' - 'a');
		}


		LP(ci,0, p.size()){
			if(p[ci] >= 'A' && p[ci] <= 'Z')
				p[ci] -= ('A' - 'a');
		}

		//cout << p << " " << c << endl;


		graph[toID(p)].push_back(toID(c));
	}

	cout << DFS(toID("polycarp")) << endl;

	return 0;
}
