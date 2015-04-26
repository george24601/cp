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

/* UVA 10696: f91
 *  Simple math problem
 */

long f91(long n)
{
	if (n >= 101)
		return n - 10;
	else
		return f91(f91(n + 11));
}

int main(int argc, const char * argv[]) {

	int n;
	while(cin >> n)
	{
		if (n == 0)
			break;

		printf("f91(%d) = %d\n", n, f91(n));
	}

	return 0;
}
