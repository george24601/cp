#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 10550: Combination Lock 
//c++ test
typedef long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

int Dist(int start,int end)
{
	int dist = start - end;
	if (dist < 0)
		dist += 40;

	return dist;
}

/*
int Min(int start, int end)
{
	int s = Dist(start, end, false);
	int d = Dist(end, start, true);

	if (s > d)
		return d;
	else 
		return s;
}
*/

int main(int argc, const char * argv[]) {

	while(true)
	{
		int start, f, s, t;
		scanf("%d %d %d %d", &start, &f, &s, &t);

		if (start == 0 &&f == 0 && s == 0 &&t == 0)
			break;

		int total = 80;
		total += Dist(start, f);
		total += 40;
		total += Dist(s, f);
		total += Dist(s, t);

		printf("%d\n", total * 9);
	}

	return 0;
}
