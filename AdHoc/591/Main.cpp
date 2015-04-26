#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;

/* UVA 591: box of bricks
 *  Simple ad hoc
 */

int main(int argc, const char * argv[]) {

	int n;
	int caseNum = 0;
	while (true) {
		cin >> n;

		if (n == 0)
			break;
		caseNum++;
		cout << "Set #" << caseNum << endl;

		int hs[n];

		int total = 0;
		for (int i = 0; i < n; i++) {
			int h;
			cin >> h;
			total += h;
			hs[i] = h;
		}
		int avg = total/n;

		int moves = 0;

		for (int i = 0; i < n; i++)
		{
			if (hs[i] >  avg)
				moves += (hs[i] - avg);
		}

		cout << "The minimum number of moves is ";
		cout << moves << "." << endl;
		cout << endl;
	}
	return 0;
}
