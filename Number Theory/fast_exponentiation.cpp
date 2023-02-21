long long fast_xp(long long a, long long b, long long mod) {
	if(b == 0) return 1;
	long long res = fast_xp(a*a%mod, b/2, mod);
	return b % 2 ? a*res%mod : res;
}