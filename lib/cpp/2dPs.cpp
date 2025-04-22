void calcPS() {

	LPE(r, 1, rc)
	{
		LPE(c, 1, cc)
		{
			ps[r][c] = ps[r][c - 1] + ps[r][c];
		}
	}

	LPE(r, 1, rc)
	{
		LPE(c, 1, cc)
		{
			ps[r][c] += ps[r - 1][c];
		}
	}

}
