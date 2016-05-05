#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 12279
//c++ test
typedef long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers


int main(int argc, const char * argv[]) {

	//freopen ("C:\\Users\\George\\c1\\test\\src\\t.txt","r",stdin);

	int numCase = 0;
	while(true)
	{
		int N;
		scanf("%d", &N);

		if (N == 0)
			break;
		numCase++;

		int totalP = 0;

		LP(i, 0, N)
		{
			int num;
			scanf("%d", &num);

			if (num > 0)
				totalP++;
			else
				totalP--;
		}

		printf("Case %d: %d\n", numCase, totalP);


	}

	return 0;
}
