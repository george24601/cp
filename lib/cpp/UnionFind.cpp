#define MaxSize 30000;
int parent[MaxSize];

int f(int a) {
  //assumption: parent[a] is set a itself on init
	if (parent[a] != a)
		parent[a] = find(parent[a]);

	return parent[a];
}

void u(int a, int b) {

	int aP = find(a);
	int bP = find(b);

	if (aP == bP)
		return;

	parent[max(aP, bP)] = min(aP, bP);
}
