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

/* UVA 357 Let Me Count The Ways
 * Coin change
 */

long long coins[] = { 1, 5, 10, 25, 50 };
int NumType = 5;

long long Calc(int target) {
	if (target == 0)
		return 1;

	long long base[target + 1];
	long long next[target + 1];

	for (int i = 0; i < target + 1; i++)
		base[i] = 0;

	for (int i = 0; i < target + 1; i++) {
		if (i < coins[0])
			base[i] = 0;
		else if (i == coins[0])
			base[i] = 1;
		else
			base[i] = base[i - coins[0]];
	}

//	cout << target << endl;

	for (int i = 1; i < NumType; i++) {
		for (int j = 0; j < target + 1; j++) {
			next[j] = base[j];
			if (j < coins[i])
				continue;
			else if (j == coins[i])
				next[j] += 1;
			else
				next[j] += next[j - coins[i]];
		}

		for (int j = 0; j < target + 1; j++)
			base[j] = next[j];
	}

	return base[target];
}

int main(int argc, const char * argv[]) {

	int target;
	while (scanf("%d", &target) != EOF) {

		long long result = Calc(target);

		if (result == 1)
			cout << "There is only 1 way to produce " << target
					<< " cents change." << endl;
		else
			cout << "There are " << result << " ways to produce " << target
					<< " cents change." << endl;
	}

	return 0;
}
