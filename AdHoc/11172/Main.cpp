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

/* UVA 11172: relational operators
 *  Simple ad hoc
 */


int main(int argc, const char * argv[]) {

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long a, b;
		cin >> a;
		cin >> b;

		if ( a > b)
			cout << '>'  << endl;
		else if ( a < b)
			cout << '<'  << endl;
		else
			cout << '='  << endl;
	}

	return 0;
}
