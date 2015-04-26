#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;

/* UVA 10341 Solve It
 * simple binary search
 */

int p, q, r, s, t, u;

double Eval(double x) {
	return p * exp(-1 * x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x
			+ u;
}

void Print(double val) {
//	cout << val << endl;
	 printf("%.4lf\n", val);
}

void Process_r(double low, double high) {
	if (high - low < 1e-9) {
		Print(high);
		return;
	}

	if (Eval(low) == 0)
		{
			Print(low);
			return;

		}else if (Eval(high) == 0)
		{
			Print(high);
			return;
		}


	double mid = (high + low) / 2;

	if (Eval(mid) > 0) {

		Process_r(mid, high);
	} else if (Eval(mid) < 0) {
		Process_r(low, mid);
	} else {
		Print(mid);
	}
}

int main(int argc, const char * argv[]) {

	while (scanf("%d", &p) != EOF) {
		scanf("%d", &q);
		scanf("%d", &r);
		scanf("%d", &s);
		scanf("%d", &t);
		scanf("%d", &u);

		if (Eval(0) < 0 || Eval(1) > 0)
			cout << "No solution" << endl;
		else
			Process_r(0, 1);
	}

	return 0;
}
