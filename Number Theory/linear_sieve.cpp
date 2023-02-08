const int N = 1e7; // works up to N = 10^7
vector<int> least_prime(N+1, 0);
vector<int> primes;

void linear_sieve() {
	for(int i = 2; i <= N; i++) {
		if(least_prime[i] == 0) {
			least_prime[i] = i;
			primes.push_back(i);
		}
		
		for(int j = 0; primes[j] * i <= N; j++) {
			least_prime[i*primes[j]] = primes[j];
			if(primes[j] == least_prime[i]) break;
		}
	}

}
