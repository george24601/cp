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

/* UVA 11340: Newspaper
 *  Simple data structure
 */

int main(int argc, const char * argv[]) {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;

		map<unsigned char, long> charToVal;

		for (int j = 0; j < K; j++) {
			unsigned char c;
			cin >> c;
			long cents;
			cin >> cents;

			charToVal.insert(pair<unsigned char, int>(c, cents));
		}

		int M;
		cin >> M;

		long sum = 0;
		cin.get();

		for (int j = 0; j < M; j++) {
			while (!cin.eof()) {
				unsigned char c = cin.get();

				if (c == '\n')
					break;


				if (charToVal.count(c) > 0)
					sum += charToVal.at(c);
			}
		}

		cout << sum / 100 << '.';

		if (sum % 100 < 10)
			cout << '0';

		cout << sum % 100 << '$' << endl;
	}
	return 0;
}
