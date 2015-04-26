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

/* UVA 674 Coin Change
 * Coin change
 */

long long coins[] = { 1, 5, 10, 25, 50 };
int NumType = 5;

int main(int argc, const char * argv[]) {

	int target = 7489;
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


	int amount;
	while (scanf("%d", &amount) != EOF) {

		int result = 0;
		if (amount == 0)
			result = 1;
		else
			result = base[amount];

		printf("%d\n", result);
	}

	return 0;
}
