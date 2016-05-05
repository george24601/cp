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

/* UVA 10683:  the decadary watch
 * ad hoc
 */

int charToInt(char a, char b)
{
	return (a - '0') * 10 + (b - '0');
}

int main(int argc, const char * argv[]) {

	long totalOldCCs = 24  * 60 * 60 * 100;
			long totalNewCCs = 10 * 100 * 100 * 100;

			string line;
			while(cin >> line)
			{
				int hh = charToInt(line[0], line[1]);
				int mm = charToInt(line[2], line[3]);
				int ss = charToInt(line[4], line[5]);
				int cc = charToInt(line[6], line[7]);

				long oldTotalCC = cc + 100 * ss + 60 * 100 * mm + 60 * 60 * 100 * hh;
				long newCC = (long) (oldTotalCC  * ((double)totalNewCCs/ (double) totalOldCCs));

				long newHH = newCC / (100 * 100  *100);
				newCC -= newHH * 100 * 100 * 100;

				long newMM = newCC/ (100 * 100);
				newCC -= newMM * 100 * 100;

				long newSS = newCC / 100;

				newCC -= newSS * 100;

				printf("%d%02d%02d%02d\n", newHH,newMM,newSS,newCC);
			}


	return 0;
}
