#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

/* UVA 11462: age sort
 * couting sort problem
 */
int main(int argc, const char * argv[]) {

	int n;
	const int Size = 99;

	while (cin >> n)
	{
		if (n == 0)
			break;

		int counts[Size];

		for (int i = 0; i < Size; i++)
			counts[i] = 0;

		int nextNum;
		for (int i = 0; i < n; i++) {
			cin >> nextNum;
			counts[nextNum - 1] += 1;
		}


		bool isFirst = true;
		for (int i = 0; i < Size; i++) {
			//cout << counts[i] << endl;
			for (int j = 0; j < counts[i]; j++) {
				if (isFirst)
					isFirst = false;
				else
					cout << ' ';

				cout << (i + 1);
			}
		}

		cout << endl;
	}
	return 0;
}
