struct item {
	long long v;
};

//this version is 1-indexed, queries [l, r]
struct segtree {
	vector<item> st;
	int size;

	item neutral_element = {INT_MAX};

	item merge(item a, item b) {
		return {min(a.v, b.v)};
	}

	item single(int v) {
		return {v};
	}

	void init(int n) {
		size = n;
		int k = 1;
		while(k <= n) k <<= 1;
		st.resize(k * 2 + 1);
	}

	void build(int x, int lx, int rx, vector<int> &a){ 
		if(lx == rx) {
			st[x] = single(a[lx]);
			return;
		}

		int mid = lx + (rx-lx)/2;
		build(2*x, lx, mid, a);
		build(2*x+1, mid+1, rx, a);
		st[x] = merge(st[2*x], st[2*x+1]);
	}

	void build(vector<int> &a) {
		build(1, 1, a.size(), a);
	}

	void update(int x, int lx, int rx, int p, int v) {
		if(rx == lx) {
			st[x] = single(v);
			return;
		}

		int mid = lx + (rx-lx)/2;
		if(p <= mid) update(2*x, lx, mid, p, v);
		else update(2*x+1, mid + 1, rx, p, v);
		st[x] = merge(st[2*x], st[2*x+1]);
	}

	void update(int p, int v){
		update(1, 1, size, p, v);
	}

	item query(int x, int lx, int rx, int l, int r) {
		if(r < lx || l > rx) return neutral_element;
		if(l <= lx && rx <= r) return st[x];

		int mid = lx + (rx-lx)/2;
		return merge(
			query(2*x, lx, mid, l, r),
			query(2*x+1, mid+1, rx, l, r)
			);
	}

	int query(int l, int r) {
		return query(1, 1, size, l, r).v;
	}
};
