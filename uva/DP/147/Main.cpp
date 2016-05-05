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

/* UVA 147 Dollars
 * Coin change
 */

long long coins[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
int NumType = 11;

long long Calc(int target) {
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
				next[j] +=  next[j - coins[i]];
		}

		for (int j = 0; j < target + 1; j++)
			base[j] = next[j];
	}

	return base[target];
}

int main(int argc, const char * argv[]) {

	while (true) {

		double target;
		cin >> target;

		if (target == 0)
			break;

		int amount = target * 100;

		if ((target * 1000  - amount * 10) >= 1)
			amount += 1;

		long long result = Calc(amount);

		cout << std::right << std::setw(6) << std::fixed << std::setprecision(2) << target << std::right
				<< std::setw(17) << result << endl;
	}

	return 0;
}
