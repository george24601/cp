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

/* UVA 374: big mod
 * mathematics
 */

long Process(long B, long P, long M) {
//	cout << B << " " << P << " " << M << endl;
	if (M == 1)
		return 0;

	if (P == 0)
		return 1;

	long cp = 1;
	long cr = B % M;
	long bitSet = P;
	long toReturn = 1;

	while (cp <= P && cp >= 1) {
		bool hasBit = (bitSet & 0x1) == 0x1;
		if (hasBit)
			toReturn = (toReturn * cr) % M;

		bitSet = bitSet >> 1;

		cp = cp * 2;

		cr = (cr * cr) % M;
	}

	return toReturn;
}

int main(int argc, const char * argv[]) {

	while (!cin.eof()) {
		string line;
		getline(cin, line);

		if (line.length() == 0)
			break;

		stringstream ss(line);
		long B, P, M;
		ss >> B;
		cin >> P;
		cin >> M;

		getline(cin, line);
		getline(cin, line);

		cout << Process(B, P, M) << endl;
	}
	return 0;
}
