typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)

//NOTE WORKS ONLY WHEN MOD IS PRIME
LL MOD = 1e9 + 7;
LL f[MaxSize], invF[MaxSize], r[MaxSize];

void preCalc() {
	r[1] = 1;
	f[1] = 1;
	invF[1] = 1;
	LL m = MOD;

	for (LL i = 2; i < MaxSize; ++i) {
		r[i] = (m - (m / i) * r[m % i] % m) % m;

		f[i] = (i * f[i - 1]) % MOD;
		invF[i] = (r[i] * invF[i - 1]) % MOD;
	}
}

LL choose(LL top, LL bottom) {
	if (top < bottom || top < 0 || bottom < 0)
		return 0;
	if (top == bottom || bottom == 0)
		return 1;

	LL bfs = (invF[bottom] * invF[top - bottom]) % MOD;

	//	cout << "ftop:" << top << " " << f[top] << endl;

	return (f[top] * bfs) % MOD;
}

//in mod 1e9 + 7, the division A/B mod MOD is calculated by A * pow(B, MOD-2)) % MOD;
