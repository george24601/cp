#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;

/* UVA 11877: The coco-cola store
 * greedy
 */

int Process(int n) {

	int total = 0;
	int butts = n;

	while (butts > 2) {
		int newMade = butts / 3;
		total += newMade;
		butts = butts % 3 + newMade;
	}

	if (2 == butts)
		total++;

	return total;
}

int main(int argc, const char * argv[]) {

	int n;
	while (cin >> n) {
		if (n == 0)
			break;

		cout << Process(n) << endl;
	}

	return 0;
}
