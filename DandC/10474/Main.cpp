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

/* UVA 10474 where is the marbel
 * simple binary search
 */

int n, q;

int counter = 0;

int BS_r(int vals[], int target, int start, int end) {

	if (start == end)
		return start;
	else if (start > end)
		return -1;
	else if (vals[end] < target)
		return -1;
	else if (vals[start] > target)
		return -1;

	int mid = (start + end) / 2;

	if (vals[mid] == target) {
		return mid;
	} else if (vals[mid] > target) {
		return BS_r(vals, target, start, mid - 1);
	} else {
		return BS_r(vals, target, mid + 1, end);
	}
}

int main(int argc, const char * argv[]) {

	while (true) {
		scanf("%d %d", &n, &q);

		if (n == 0 && q == 0)
			break;

		counter++;

		printf("CASE# %d:\n", counter);

		int marbles[n];

		for (int i = 0; i < n; i++)
			scanf("%d", &marbles[i]);

		sort(marbles, marbles + n);

		for (int i = 0; i < q; i++) {
			int target;
			scanf("%d", &target);
			bool found = false;

			for (int j = 0; j < n; j++) {

				if (marbles[j] > target)
					break;
				else if (marbles[j] == target) {
					printf("%d found at %d\n", target, j + 1);
					found = true;
					break;
				}
			}

			if (!found)
				printf("%d not found\n", target);
		}
	}

	return 0;
}
