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

/* UVA 10370: above average
 *  Simple ad hoc
 */


int main(int argc, const char * argv[]) {

	int c = 0;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		int n;
		cin >> n;

		long marks[n];

		long total = 0;
		for (int j = 0; j < n; j++)
		{
			long mark;
			cin >> mark;
			marks[j] = mark;
			total += mark;
		}

		double avg = total / (double) (n);

		int numAbove = 0;
		for (int j = 0; j < n; j++)
		{
			if (marks[j] > avg)
				numAbove++;
		}

		double percentage = (numAbove/ (double) n) * 100;
		printf ("%.3f", percentage);
		cout << '%' << endl;

	}

	return 0;
}
