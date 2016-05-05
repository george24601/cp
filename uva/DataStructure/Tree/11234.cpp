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

const int MaxN = 100000;

char buff[MaxN];
int len;

class Exp {
public:
	char sym;
	Exp* left;
	Exp* right;

	Exp(char c, Exp* l, Exp* r) {
		sym = c;
		left = l;
		right = r;
	}

	~Exp() {
		delete left;
		delete right;
	}
};

stack<Exp*> st;
void Read_r(int index) {
	if (index == len)
		return;
	//if symbol, put simple symbol tree on stack

	char c = buff[index];

	if (c >= 'a' && c <= 'z') {
		st.push(new Exp(c, NULL, NULL));
	} else {
		Exp* left = st.top();
		st.pop();
		Exp* right = st.top();
		st.pop();

		st.push(new Exp(c, left, right));
	}

	Read_r(index + 1);
	//if operator, pop two symbol and form a third tree
	//push new tree on to stack
}

queue<Exp*> ps;
stack<char> out;

int main() {
	//freopen("C:\\Test\\test.txt", "r", stdin);
	//freopen("C:\\Test\\expressions.in", "r", stdin);
	//freopen("C:\\Test\\out.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	LP(i, 0, T)
	{
		scanf("%s", buff);

		len = strlen(buff);

		//read postFix

		Read_r(0);
		Exp* root = st.top();
		st.pop();

		ps.push(root);

		while (!ps.empty()) {
			Exp* e = ps.front();
			ps.pop();

			out.push(e->sym);
			if (e->sym >= 'a' && e->sym <= 'z')
				continue;

			//if e is op => store op

			// line becomes LR LL R => queue
			ps.push(e->right);
			ps.push(e->left);
		}

		while (!out.empty()) {
			printf("%c", out.top());
			out.pop();
		}

		printf("\n");

		delete root;
	}

	return 0;
}
