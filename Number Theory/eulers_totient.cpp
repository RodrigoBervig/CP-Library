//Gives the number of positive coprime integers relative to N

int phi(int n) {
	int ans = n;

	for(int i = 2; i * i <= n; i++) {
		if(n%i) continue;
		ans -= ans/i;
		while(n % i == 0) n/=i;
	}

	if(n != 1) ans -= ans/n;

	return ans;
}

//Modified sieve version to compute it from 1 to N
void euler_phi(int n) {
	for(int i = 2; i <= n; i++) {
		totient[i] = i;
	}

	for(int i = 2; i <= n; i++) {
		if(totient[i] != i) continue;
		for(int j = i; j <= n; j+=i) {
			totient[j] -= totient[j]/i;
		}
	}
}