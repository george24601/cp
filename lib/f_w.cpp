LP(i, 0, 26)
{
	LP(j, 0, 26)
	{
		if (i == j)
			len[i][j] = 0;
		else
			len[i][j] = INF;
	}
}

int n;
cin >> n;
LP(i, 0, n)
{
	char a, b;
	int w;
	cin >> a >> b >> w;
	len[a - 'a'][b - 'a'] = min(len[a - 'a'][b - 'a'], w);
}

LP(newI, 0, 26)
{
	LP(i, 0, 26)
	{
		LP(j, 0, 26)
		{
			len[i][j] = min(len[i][j], len[i][newI] + len[newI][j]);
		}
	}
}
