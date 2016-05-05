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

/* UVA 575: Skew Binary
 *  Simple ad hoc
 */

const int AlphaSize = 26;

void Process(string line)
{
	int i = line.length() -1;
	long total = 0;
	long power = 2;

	while(i >= 0)
	{
		long rep = power - 1;

		total += ((line[i] - '0') * rep);

		power = power * 2;
		i--;
	}

	cout << total << endl;
}

int main(int argc, const char * argv[]) {

	while (true) {
		string line;
		getline(cin, line);

		if (line.compare("0") == 0)
			break;

		Process(line);
	}

	return 0;
}
