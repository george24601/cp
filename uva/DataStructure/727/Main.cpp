#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

/* UVA 727:  equations
 * infix to postfix problem
 */

int GetPriority(char c) {
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;

	if (c == ')')
		return 0;

	if (c == '(')
		return -1;

	return -1000;
}

bool IsOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

void Process_r(stack<char> operators, vector<char> inputs, int curIndex) {
	if (curIndex >= inputs.size()) {
		// when we read the end of input, pop until the stack is empty;
		while (!operators.empty()) {
			cout << operators.top();
			operators.pop();
		}

		return;
	}

	char currentInput = inputs[curIndex];

	//cout << "   reading: " << currentInput << endl;

	if (currentInput == '(') {
		operators.push(currentInput);
	} else if (currentInput == ')') {
		while (!operators.empty() && operators.top() != '(') {
			cout << operators.top();
			operators.pop();
		}

		operators.pop();

	} else if (IsOperator(currentInput)) {

		// when an operator is read
		// pop until the top of the satch has an elemetn of lower preciende
		while (!operators.empty()
				&& GetPriority(currentInput) <= GetPriority(operators.top())) {
			cout << operators.top();
			operators.pop();
		}

		operators.push(currentInput);

	} else {
		// when an operand is read, output it
		cout << currentInput;
	}

	// when ) is found, pop until we find the macthing (
	// ( has lowest precensdne when in the stack, but has thehightest
	// predence when i the input
	Process_r(operators, inputs, curIndex + 1);
}

int main(int argc, const char * argv[]) {

	int n;
	cin >> n;
	string line;
	getline(cin, line);

	for (int i = 0; i < n; i++) {
		vector<char> input;


		if (i == 0)
		{
			getline(cin, line);
		//	cout << "  line 1  " << line << endl;
		}

		while (getline(cin , line)) {

			if (line.empty())
				break;
			/*
			if (line.empty())
				cout << "empty" << endl;
			else
				cout << "  line 2  " << line << endl;
				*/

			input.push_back(line[0]);
		}

		stack<char> operators;
		Process_r(operators, input, 0);
		cout << endl;

		if (i < n - 1)
			cout << endl;
	}

	return 0;
}
