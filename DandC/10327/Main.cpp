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

/* UVA 10327: filp sort
 * inversion index
 */

int main(int argc, const char * argv[]) {

	int n;
	while (scanf("%d", &n) != EOF) {
		int nums[n];

		for (int i = 0; i < n; i++)
			cin >> nums[i];

		int total = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[i] > nums[j])
					total++;
			}
		}

		printf("Minimum exchange operations : %d\n", total);
	}
	return 0;
}
