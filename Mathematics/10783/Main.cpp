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

/* UVA 10783: odd sum
 *  Simple math problem
 */


int main(int argc, const char * argv[]) {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a,b;
		cin >> a;
		cin >> b;
		int smaller = a > b? b : a;
		int bigger = a > b? a: b;
		long sum = 0;

		for (int j = smaller; j <= bigger; j++)
		{
			if(j %2 == 1)
				sum += j;
		}

		cout << "Case " << i + 1<< ": " << sum << endl;
	}

	return 0;
}
