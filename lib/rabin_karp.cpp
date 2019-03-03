LL const MOD = 1e9 + 7;
LL const BASE = 256;

//not really Rabin fingerprint 
/*When MOD is 101
 * a = 97, b = 98, r = 114.
 * "hi" = 65
 * "abr" = 4
 */
//don't forget to lower case if you are doing string matching
LL sHash(string s){
	LL h =  0
		LP(i, 0, s.size()){
			h = (h * BASE) + (LL)s[i]; //very similar idea to base number calculation
			h %= HASH_MOD;
		}

	return h;
}

void slide(){
	LL hash = 0;
	LL topBase = 1;
	LP(i, 0, winL)
	{
		if (i > 0) {
			topBase *= BASE;
			topBase %= MOD;
		}

		hash *= BASE;
		hash %= MOD;
		hash += (LL)(t[i] - 'a');
		hash %= MOD;
	}
	LP(i, winL, n)
	{
		//slide the hash
		LL oh = hash;
		hash -= topBase * (LL)(t[i - winL] - 'a');
		hash %= MOD; //watch out for the negative case!
		hash += MOD;
		hash %= MOD;

		hash *= BASE;
		hash %= MOD;
		hash += (LL)(t[i] - 'a');
		hash %= MOD;
	}
}
