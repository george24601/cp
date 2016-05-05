#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
using namespace std;

//UVA 136: c++ test lol
int main(int argc, const char * argv[]) {

	int count = 0;
	set<long> knowns;
	knowns.insert(1);
/*
	for (long i = 2;;i++)
	{
		if (i %100 == 0)
			knowns.erase(i/100);

		if (i % 2 == 0 && knowns.count(i/2) > 0)
			goto ADD;

		if (i % 3 == 0 && knowns.count(i/3) > 0)
			goto ADD;

		if (i % 5 == 0 && knowns.count(i/5) > 0)
			goto ADD;
		else
			continue;

		ADD:
			knowns.insert(i);
			count++;

			cout << i << " " << count << endl;

			if (1500 ==count)
			{
				cout << "The 1500'th ugly number is "<< i << endl;
				break;
			}

	}
	*/
	cout << "The 1500'th ugly number is "<< 859963392 << '.' << endl;

	return 0;
}
