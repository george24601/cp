#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
using namespace std;

//UVa 10354 avoiding your boss
//SSSP
typedef long long L;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8

const int INF = 2147483640;

const int MaxN = 10;

int n;

int main() {
	//freopen("C:\\Test\\dihedral.in", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	while (true) {
		cin >> n;

		if (n == 0)
			break;
		string line;
		getline(cin, line); //newline
		getline(cin, line);
		stringstream ss;
		ss << line;

		string token;

		bool nextIncre = true;
		int current = 0;

		while (ss >> token) {
			char op = token[0];
			string countS = token.substr(1, token.length() - 1);
			int count = atoi(countS.c_str());

			if (op == 'm') {
				count = count % 2;

				if (1 == count)
					nextIncre = !nextIncre;

			} else {
				count = count % n;

				if (nextIncre)
					current = (current + count) % n;
				else
					current = (current - count + n) % n;
			}
		}

		if (nextIncre) {
			int justRotate = current;

			int reverseAndRotate = 1 + (n - current) % n + 1;

			if (justRotate <= reverseAndRotate) {
				if (justRotate > 0)
					printf("r%d\n", justRotate);
				else
					printf("\n");
			} else {
				printf("m1 r%d m1\n", (n - current));
			}
		} else {
			int rotateFirst = current;
			int rotateLast = n - current;

			if (rotateFirst <= rotateLast)
				if (rotateFirst == 0)
					printf("m1\n", rotateFirst);
				else
					printf("r%d m1\n", rotateFirst);
			else
				printf("m1 r%d\n", rotateLast);
		}
	}

	return 0;
}
