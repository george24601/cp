#include <iostream>
#include <list>
#include <map>
using namespace std;

//UVA 458: c++ test lol
int main(int argc, const char * argv[]) {

	string line;

	while(cin >> line)
	{
		for (int i = 0; i < line.length(); i++)
		{
			cout << (char) (line[i] - 7);
		}

		cout << endl;
	}
	return 0;
}
