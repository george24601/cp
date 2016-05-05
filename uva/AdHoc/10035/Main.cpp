#include <iostream>
#include <list>
#include <map>
#include <sstream>
using namespace std;

int Process (long a, long b, bool hasCarryOver)
{
	long first = a;
	long second = b;
	if (a < b)
	{
		first = b;
		second = a;
	}

	int target = hasCarryOver? 9 : 10;
	if (first < 10)
	{
		if (first + second >= target)
			return 1;
		else
			return 0;
	}

	int firstPart = a % 10;
	int secondPart = b % 10;

	if (firstPart + secondPart < target)
		return Process(a/10, b/10, false);
	else
		return 1 + Process ((a/10), b/10, true);
}
//UVA 10035: c++ test lol
int main(int argc, const char * argv[]) {

	long a;
	long b;
	while (cin >> a) {
		cin >> b;

		if (a == 0 && b == 0)
			break;

		int result = Process(a, b, false);

		if (result == 0)
			cout << "No carry operation." << endl;
		else if (1 == result)
			cout << "1 carry operation." << endl;
		else
			cout << result << " carry operations." <<endl;
	}
	return 0;
}
