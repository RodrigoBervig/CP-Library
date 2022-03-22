mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
const int MOD = 1e9+7;
const int P = uniform_int_distribution(27, MOD-1)(rng);

struct str_hash {
	int n;
	string s;
	vector<ll> h;
 
	str_hash(string s_) : n(s_.size()), s(s_), h(n) {
		h[0] = s[0];
		for(int i = 1; i < n; i++) h[i] = (h[i-1] * P + s[i]) % MOD;
	}
 
	ll operator()(int l, int r) { // retorna hash s[l...r]
		ll hash = h[r] - (l ? h[l - 1]*power[r - l + 1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};

power[0] = 1;
for(int i = 1; i < MAX; i++) {
	power[i] = power[i-1] * P % MOD;
}

//template<int MOD> int str_hash<MOD>::P = uniform(27, MOD-1);
// first parameter must be bigger than alphabet size