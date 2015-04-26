#include <iostream>
#include <list>
#include <map>
using namespace std;

//UVA 10055: c++ test lol
int main(int argc, const char * argv[]) {

	long firstNum;
	long secondNum;

	while(cin >> firstNum)
	{
		cin >> secondNum;

		if (firstNum > secondNum)
			cout << firstNum - secondNum << endl;
		else
			cout << secondNum - firstNum<< endl;
	}
	return 0;
}
