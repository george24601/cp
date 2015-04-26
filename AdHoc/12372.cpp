#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <stdio.h>
using namespace std;

//UVA 12372
//c++ test
typedef long long L;
#define INF 2000000000 // 2 billion
#define LP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

int main(int argc, const char * argv[]) {

	//freopen("C:\\Users\\George\\c1\\test\\src\\t.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	LP(i, 0, T)
	{
		int L, W, H;
		scanf("%d %d %d", &L, &W, &H);

		if (L <= 20 && W <= 20 && H <= 20)
			printf("Case %d: good\n", i + 1);
		else
			printf("Case %d: bad\n", i + 1);

	}

	return 0;
}
