typedef unsigned long long UL;
typedef long long LL;
typedef long double LD;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define Ep 1e-8
#define INF 1e9
#define LINF 1e18

/*
 catch:
 1. need to exclude parent in dfs
 2. need to dedup answer

 Official solution uses UF

 */

int const MaxSize = 1000 + 5;
int n;
SAL g;
int state[MaxSize];
vector<PII> ces;
vector<int> firstNode;

void dfs(int v, int p) {
	if (state[v] == 2) {
		return;
	}
	state[v] = 1;

	LP(i, 0, g[v].size())
	{
		int next = g[v][i];
		if(next == p)
			continue;

		if (state[next]) {
			if(v < next)
				ces.push_back(PII(v, next));
		} else {
			dfs(next, v);
		}
	}

	state[v] = 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n;

	g = SAL(n + 1);
	memset(state, 0, sizeof(state));
	LP(i, 0, n - 1)
	{
		int s, t;
		cin >> s >> t;
		g[s].push_back(t);
		g[t].push_back(s);
	}

	LPE(v, 1, n)
	{
		if (!state[v]) {
			firstNode.push_back(v);
			dfs(v, -1);
		}
	}


	cout << ces.size() << endl;
	LP(i, 1, firstNode.size())
	{
		cout << ces[i - 1].first << " " << ces[i - 1].second << " "<< firstNode[i - 1]
				<< " " << firstNode[i] << endl;
	}

	return 0;
}
