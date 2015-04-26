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

/* UVA 10008: what's crptanalysis
 *  Simple ad hoc
 */

const int AlphaSize = 26;
int main(int argc, const char * argv[]) {

	int n;
	cin >> n;

	int freq[AlphaSize];

	for (int i = 0; i < AlphaSize; i++)
		freq[i] = 0;

	string line;
	getline(cin, line);

	for (int i = 0; i < n; i++) {
		getline(cin, line);

		for (int j = 0; j < line.length(); j++) {
			char c = line[j];

			if (c >= 'A' && c <= 'Z') {
				int index = c - 'A';
				freq[index] += 1;
			} else if (c >= 'a' && c <= 'z') {
				int index = c - 'a';
				freq[index] += 1;
			}
		}
	}

	priority_queue<pair<int, int> > output;

	for (int i = 0; i < AlphaSize; i++) {
		if (freq[i] == 0)
			continue;

		output.push(make_pair(freq[i], -1 * i));
	}

	while (output.size() > 0) {
		pair<int, int> current = output.top();
		char c = 'A' - current.second;
		cout << c << " " << current.first << endl;
		output.pop();
	}

	return 0;
}
