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

/* UVA 488:  triangle wave
 *  Simple ad hoc
 */

const int AlphaSize = 26;

void Print(int amp)
{
	for (int i = 1; i <= amp; i++)
	{
		for (int j = 0; j < i; j++)
			cout << i;
		cout << endl;
	}

	int i = amp - 1;
	while(i > 0)
	{
		for (int j = 0; j < i; j++)
			cout << i;


		cout << endl;
		i --;
	}
}

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i ++)
	{
		if (i > 0)
			cout << endl;

		int amp;
		cin >> amp;
		int freq;
		cin >> freq;

		for (int j = 0; j < freq; j++)
		{
			Print(amp);

			if (j < freq - 1)
				cout << endl;
		}
	}

	return 0;
}
