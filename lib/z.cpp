vector<int> s;
int sl, z[MaxSize * 2 + 1];

void runZ() {
	int l = 0, r = 0;
	z[0] = 0;

	LP(i, 1, sl)
	{
		int curLen;
		if (i > r) {
			curLen = 0;
		} else {
			curLen = min(r - i + 1, z[i - l]);
		}
		while ((i + curLen) < sl && s[curLen] == s[i + curLen]) {
			curLen++;
		}

		z[i] = curLen;

		if (i + z[i] - 1 > r) {
			l = i;
			r = i + curLen - 1;
		}
	}
}
