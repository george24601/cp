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

/* UVA 10340:  All in all
 * ad hoc
 */

bool IsSub(string first, string second)
{
	int firstIndex = 0;
	int secondIndex = 0;

	while(secondIndex < second.length())
	{
		if (first[firstIndex] == second[secondIndex])
		{
			firstIndex++;

			if (firstIndex == first.length())
				return true;

		}

		secondIndex++;
	}

	return false;
}

int main(int argc, const char * argv[]) {

	while(!cin.eof())
	{
		string line;
		getline(cin, line);

		if (line.length() == 0)
			break;

		stringstream ss (line);

		string first;
		ss >> first;
		string second;
		ss >> second;

		if (IsSub(first, second))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
