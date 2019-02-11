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
 sort by t(i), and check all possible best result
 catch case:
 1. inverse the order to detect mixing old and new is
 2. overflow
 */

int const MaxSize = 1000 + 5;
int n, x[MaxSize], y[MaxSize];
PII tOi[MaxSize];
double p[MaxSize];
double ans[MaxSize];

int len2(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool good(int from, int to) {
	LL dt = tOi[to].first - tOi[from].first;
	int fromI = tOi[from].second;
	int toI = tOi[to].second;
	LL d2 = len2(x[fromI], y[fromI], x[toI], y[toI]);

	return d2 <= (dt * dt);
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	cin >> n;

	LP(i, 0, n)
	{
		int t;
		cin >> x[i] >> y[i] >> t >> p[i];
		tOi[i] = PII(t, i);
	}

	sort(tOi, tOi + n);

	LP(i, 0, n)
	{
		double pi = p[tOi[i].second];
		ans[i] = pi;
		LP(j, 0, i)
		{
			if (good(j, i)) {
				ans[i] = max(ans[i], ans[j] + pi);
			}
		}
	}

	double fa = 0;
	LP(i, 0, n)
		fa = max(fa, ans[i]);

	cout << setprecision(12) << fa;

	return 0;
}
