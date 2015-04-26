#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

//UVA 146: ID Codes. Use next_permutation
int main(int argc, const char * argv[]) {

	string line;
	while (cin >> line) {
		if ("#" == line)
			break;

		char chars[line.length()];
		for (int i = 0; i < line.length(); i++) {
			chars[i] = line[i];
		}

		bool hasMore = next_permutation(chars, chars + line.length());

		if (hasMore) {
			for (int i = 0; i < line.length(); i++)
				cout << chars[i];

			cout << endl;
		} else {
			cout << "No Successor" << endl;
		}
	}

	return 0;
}
