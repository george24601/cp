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

/* UVA 10030:ecological premium
 *  Simple ad hoc
 */


int main(int argc, const char * argv[]) {

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long total = 0;

		int f = 0;
		cin >> f;

		for (int j = 0; j < f; j++)
		{
			long size;
			cin >> size;
			int numAnimal;
			cin >> numAnimal;
			long ef;
			cin >> ef;

			total += size * ef;

		}

		cout << total << endl;
	}

	return 0;
}
