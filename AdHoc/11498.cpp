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

/* UVA 11498:  Division of Nlogonia
 * ad-hoc
 */

int main(int argc, const char * argv[]) {

	while (true) {
		int K;
		cin >> K;

		if (K == 0)
			break;
		int N;
		cin >> N;
		int M;
		cin >> M;

		for (int i = 0; i < K; i++) {
			int X;
			cin >> X;
			int Y;
			cin >> Y;

			if (X == N || Y == M)
				cout << "divisa" << endl;
			else if (X < N && Y > M)
				cout << "NO" << endl;
			else if (X > N && Y > M)
				cout << "NE" << endl;
			else if (X > N && Y < M)
				cout << "SE" << endl;
			else if (X < N && Y < M)
				cout << "SO" << endl;
		}
	}

	return 0;
}
