mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	int n;
	string s;
	vector<ll> h, power;

	str_hash(string s_) : n(s_.size()), s(s_), h(n), powers(n) {
		power[0] = 1;
		for(int i = 1; i < n; i++) power[i] = power[i-1] * P % MOD; //precompute powers of P

		h[0] = s[0];
		for(int i = 1; i < n; i++) h[i] = (h[i-1] * P + s[i]) % MOD;
	}

	ll operator()(int l, int r) {
		if(l == 0) return h[r];
		ll ans = h[r] - h[l-1] * power[r-l+1] % MOD;
		return ans < 0 ? ans + MOD : ans;
	}
};

template<int MOD> int str_hash<MOD>::P = uniform(27, MOD-1);
// first parameter must be bigger than alphabet size