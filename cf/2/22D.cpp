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
 tried a two pointer apprach with two arrays, turns out the result is not classical two pointer loop - uses 2 while loops
 a single event based solution is way cleaner

 */

int const MaxSize = 1000 + 5;
int n;
PII sp[MaxSize], ep[MaxSize];
bool covered[MaxSize];
vector<int> on;

int main() {
	ios_base::sync_with_stdio(false);
//	freopen("/Users/georgeli/A_1.in", "r", stdin);

	cin >> n;

	LP(i, 0, n)
	{
		int s, e;
		cin >> s >> e;
		sp[i] = PII(min(s, e), i);
		ep[i] = PII(max(s, e), i);
	}

	sort(sp, sp + n);
	sort(ep, ep + n);

	int ei = 0;
	int si = 0;

	vector<int> ans;
	while (si < n) {
		if (sp[si].first <= ep[ei].first) {
			int segI = sp[si].second;
			on.push_back(segI);
			si++;
		} else {
			while (ei < n && sp[si].first > ep[ei].first) {
				int segI = ep[ei].second;
				if (covered[segI]) {

				} else {
					ans.push_back(ep[ei].first);
					LP(j, 0, on.size())
					{
						covered[on[j]] = true;
					}
					on.clear();
				}

				ei++;
			}
		}
	}

	while (ei < n) {
		int segI = ep[ei].second;
		if (covered[segI]) {

		} else {
			ans.push_back(ep[ei].first);
			LP(j, 0, on.size())
			{
				//cout << on[j] << endl;
				covered[on[j]] = true;
			}
			on.clear();
		}

		ei++;
	}

	cout << ans.size() << endl;
	LP(i, 0, ans.size())
		cout << ans[i] << " ";

	return 0;
}
