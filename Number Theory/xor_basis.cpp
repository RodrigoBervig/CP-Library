vector<long long> a(n+1), basis;
	
//basis contains all the linear independent vectors
//basis.size() is the rank of the matrix
//the number of elements with xor_sum != 0 you can make is 2^(N-rank):
//why? because any subset of non-basis elements can be formed by the basis, does we can make that subset = xor_zero (note the 0 is never part of the basis)

for(int i = 1; i <= n; i++) {
	long long A = a[i];

	for(auto x: basis) {
		A = min(A, A^x);
	}
	if(A) basis.push_back(A);
}
