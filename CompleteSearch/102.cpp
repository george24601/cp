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

/* UVA 102:ecological bin packing
 *  Simple complete search
 */

const int Size = 3;

long data[3][3];
long calc(int b, int g, int c) {

	long total = 0;

	for (int i = 0; i < Size; i++) {

		if (i != b)
			total += data[i][0];

		if (i != g)
			total += data[i][1];

		if (i != c)
			total += data[i][2];
	}

	return total;
}

int main(int argc, const char * argv[]) {

	while (!cin.eof()) {
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				cin >> data[i][j];

				if (j < Size - 1 && cin.eof())
					return 0;
			}
		}

		string minName = "BCG";
		long minVal = calc(0, 2, 1);

		string BGC = "BGC";
		long BGCVal = calc(0, 1, 2);

		if (BGCVal < minVal) {
			minVal = BGCVal;
			minName = BGC;
		}

		string CBG = "CBG";
		long CBGVal = calc(1, 2, 0);

		if (CBGVal < minVal) {
			minVal = CBGVal;
			minName = CBG;
		}
		string CGB = "CGB";
		long CGBVal = calc(2, 1, 0);

		if (CGBVal < minVal) {
			minVal = CGBVal;
			minName = CGB;
		}

		string GBC = "GBC";
		long GBCVal = calc(1, 0, 2);

		if (GBCVal < minVal) {
			minVal = GBCVal;
			minName = GBC;
		}

		string GCB = "GCB";
		long GCBVal = calc(2, 0, 1);

		if (GCBVal < minVal) {
			minVal = GCBVal;
			minName = GCB;
		}

		cout << minName << " " << minVal << endl;
	}

	return 0;
}
