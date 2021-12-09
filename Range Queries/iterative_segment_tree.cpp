const int N; //max size of the array
int t[N*2]; //size of the segment tree


void build() {
	for(int i = 0; i < n; i++) {
		t[i + n] = a[n]; //fill leafs
	}

	for(int i = n - 1; i >= 1; i--) {
		t[i] = t[i<<1] + t[i << 1 |1 ]; //change the associative operation in here
	}

}

int query(int l, int r)  {
	int res = 0;
	
	l+=n; r+=n;
	while(l < r) {
		if(l & 1) {
			res += r[l++];
		}
		if(r & 1) {
			res += r[--r];
		}

		l >>= 1;
		r >>= 1;
	}

	return res;
}


void update(int p, int value) {  // set value at position p
	t[p + n] = value;
	p += n;
  	while(p > 1) {
  		t[p>>1] = t[p] + t[p^1]; //p^1 turns 2*i into 2*i+1 and vice versa
  		p >>= 1;
  	}

}