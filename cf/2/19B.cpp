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
 convert the problem by adding 1 to each time
 if we inspect the condition formula, we can see that we can reduce to problem into a knapscak, instead of attacking it head-on

 */

int const MaxSize = 2000 + 5;
int n;
LL t[MaxSize], c[MaxSize];
LL minC[MaxSize][2 * MaxSize];

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n;
	LPE(i, 1, n)
	{
		cin >> t[i] >> c[i];
		t[i] += 1;
	}

	LPE(i, 0, n)
	{
		LPE(curT, 0, 2 * n)
		{
			minC[i][curT] = LINF;
		}
	}

	minC[0][0] = 0;

	LPE(i, 1, n)
	{
		minC[i][t[i]] = c[i];

		LPE(curT, 0, 2 * n)
		{
			minC[i][curT] = min(minC[i][curT], minC[i - 1][curT]);
			if (curT >= t[i]) {
				LL takeC = minC[i - 1][curT - t[i]];

				if (takeC >= LINF)
					continue;

				if (minC[i][curT] > takeC + c[i]) {
					minC[i][curT] = takeC + c[i];
				}
			}
		}
	}

	LL ans = LINF;
	LPE(curT, n, 2 * n)
	{
		ans = min(ans, minC[n][curT]);
	}

	cout << ans;

	return 0;
}
