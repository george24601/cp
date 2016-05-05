#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 11364: optimal parking 
//c++ test
typedef long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers


int main(int argc, const char * argv[]) {

	int t;
	scanf("%d", &t);
	LP(i, 0, t)
	{
		int n;
		scanf("%d", &n);
		int stores[20];

		LP(j, 0, n)
			scanf("%d", &stores[j]);

		int max = stores[0];
		int min = stores[0];
		LP(k, 0, n)
		{
			int cur = stores[k];
			if (cur > max)
				max = cur;

			if (cur < min)
				min = cur;
		}


		printf("%d\n", (max - min ) * 2);

	}

	return 0;
}
