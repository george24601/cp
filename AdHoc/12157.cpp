#include <cstdio>

#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

/* UVA 12157 Tariff Plan
 * ad hoc
 */

int cost(int min, int factor, int segLen)
{
	int totalSeg = (min / segLen) + 1;

	return totalSeg * factor;
}

int main(int argc, const char * argv[]) {

	int T;
	cin >> T;

	for (int i =0 ; i < T; i++)
	{
		cout << "Case " << i + 1 << ": ";
		int N;
		cin >> N;

		int mins[N];
		for (int j = 0; j < N; j++)
			cin >> mins[j];

		long long Mile = 0;
		long long Juice = 0;

		for (int j =0; j < N; j++)
		{
			Mile += cost(mins[j], 10, 30);
			Juice += cost(mins[j], 15, 60);
		}

		if (Mile < Juice)
			cout << "Mile "<< Mile << endl;
		else if (Mile > Juice)
			cout << "Juice "<< Juice << endl;
		else
			cout << "Mile Juice "<< Juice << endl;
	}

	return 0;
}
