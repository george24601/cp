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

/* UVA 10346:  Peter's smokes
 * greedy
 */

long Process(long n, long k) {

	long total = n;
	long butts = n;

	while (butts >= k) {
		int newMade = butts / k;
		total += newMade;
		butts = butts % k + newMade;
	}

	return total;
}

int main(int argc, const char * argv[]) {

	while (!cin.eof()) {
		string line;
		getline(cin, line);

		if (line.length() == 0)
			break;
		stringstream ss(line);
		long n;
		long k;
		ss >> n;
		ss >> k;

		cout << Process(n, k) << endl;
	}

	return 0;
}
