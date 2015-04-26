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

/* UVA 11089: minsweeper
 *  Simple ad hoc
 */

int main(int argc, const char * argv[]) {
	int caseNum = 0;
	while (true) {
		int n, m;
		cin >> n;
		cin >> m;

		if (n == 0 && m == 0)
			break;

		caseNum++;

		if (caseNum > 1)
			cout << endl;

		cout << "Field #" << caseNum << ":" << endl;

		string line;

		int matrix[n][m];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				matrix[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			cin >> line;

			for (int j = 0; j < m; j++) {
				if (line[j] != '*')
					continue;

				matrix[i][j] = -1;

				if (i > 0 && j > 0 && matrix[i - 1][j - 1] != -1)
					matrix[i - 1][j - 1] += 1;
				if (i > 0 && matrix[i - 1][j] != -1)
					matrix[i - 1][j] += 1;
				if (i > 0 && j < m - 1 && matrix[i - 1][j + 1] != -1)
					matrix[i - 1][j + 1] += 1;
				if (j > 0 && matrix[i][j - 1] != -1)
					matrix[i][j - 1] += 1;
				if (j < m - 1 && matrix[i][j + 1] != -1)
					matrix[i][j + 1] += 1;
				if (i < n - 1 && j > 0 && matrix[i + 1][j - 1] != -1)
					matrix[i + 1][j - 1] += 1;
				if (i < n - 1 && matrix[i + 1][j] != -1)
					matrix[i + 1][j] += 1;
				if (i < n - 1 && j < m - 1 && matrix[i + 1][j + 1] != -1)
					matrix[i + 1][j + 1] += 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == -1)
					cout << '*';
				else
					cout << matrix[i][j];

			}
			cout << endl;
		}
	}

	return 0;
}
