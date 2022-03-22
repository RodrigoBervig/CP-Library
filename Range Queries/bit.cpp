struct fenwick_tree {
	vector<int> bit;
	int size;

	void build(vector<int> &a) {
		size = (int)a.size();
		bit.resize(size);
		bit[0] = 0;
		for(int i = 1; i <= n; i++) bit[i] = a[i-1];
		for(int i = 1; i <= n; i++) {
			int j = i + (i & -i);
			if(j <= n) bit[j] += bit[i];	
		}
	}

	void add(int v, int p) {
		for(; p <= n; p += (p & -p)) {
			bit[p] += v;
		}
	}

	void sum(int p) {
		ll ans = 0;
		for(; p >= 0; p -= (p & -p)) {
			ans += bit[p];
		}
		return ans;
	}

	void query(int l, int r) {
		return sum(r) - sum(l-1);
	}
}