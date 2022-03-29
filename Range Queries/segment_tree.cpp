/*
	Find the kth number:
	int find(int v, int lx, int rx, int k) {
		if(k > values[v])
			return -1;
		if(lx - rx == 1){
			if(lx < (int)a.size())
				return values[lx];
		}
		int tm = (lx + rx) / 2;
		if(k <= values[2*v+1])
			return find(2*v+1, lx, tm, k);
		else
			return find(2*v+1, tm, rx, k - values[2*v+1]);
	}
*/

//counts the number of minimum elements in the segment

struct item {
	int v;
};
 
struct segtree {
 
	int size;
	vector<item> t;
 
	item neutral_element {INT_MAX};
 
	item merge(item a, item b) {
		return {min(a.v, b.v)};
	}
 
	item single(int v) {
		return {v};
	}
 
	void init(int n) {
		size = 1;
		while(size < n) size <<= 1;
		t.resize(2*size);
	}
 
	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < (int)a.size())
				t[x] = single(a[lx]);
			return;
		}
		int mid = lx + (rx - lx)/2;
		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		t[x] = merge(t[2*x+1], t[2*x+2]);
	}
 
	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}
 
	void update(int p, int value, int x, int lx, int rx) {
		if(rx - lx == 1) {
			t[x] = single(value);
			return;
		}
		int mid = lx + (rx-lx)/2;
		if(p < mid) {
			update(p, value, 2*x+1, lx, mid);
		} else {
			update(p, value, 2*x+2, mid, rx);
		}
		t[x] = merge(t[2*x+1], t[2*x+2]);
	}
 
	void update(int p, int value) {
		update(p, value, 0, 0, size);
	}
 
	item query(int l, int r, int x, int lx, int rx) {
		if(lx >= r || rx <= l) return neutral_element;
		if(lx >= l && rx <= r) return t[x];
		int mid = lx + (rx-lx)/2;
		item s1 = query(l, r, 2*x+1, lx, mid);
		item s2 = query(l, r, 2*x+2, mid, rx);
		return merge(s1, s2);
	}
 
	item query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
 
 
};
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	segtree st;
	st.init(n);

	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	st.build(a);

	//for(auto it : st.values) cout << it << " ";
	//cout << "\n";

	int op, l, r;

	for(int i = 0; i < m; i++){
		cin >> op >> l >> r;
		if(op == 1){
			st.set(l,r);
		} else {
			auto res =  st.calc(l,r);
			cout << res.m << " " << res.c << "\n";
		}
	}
}

//segment with maximum sum
struct item {
	ll mx, pref, suf, sum;
};

struct segtree {
	vector<item> t;
	int size;

	item merge(item a, item b) {
		ll mx = max({a.mx, b.mx, a.suf + b.pref});
		ll pref = max(a.pref, a.sum + b.pref);
		ll suf = max(b.suf, b.sum + a.suf);
		return {mx, pref, suf, a.sum + b.sum};
	}

	item single(int a) {
		return {max(0,a), a, a, a};
	}

	void init(int n) {
		size = 1;
		while(size < n) size <<= 1;
		t.resize(size * 2);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < (int)a.size()) {
				t[x] = single(a[lx]);
			}
			return;
		}
		int mid = lx + (rx -lx)/2;
		build(a, 2*x+1, lx, mid);
		build(a, 2*x+2, mid, rx);
		t[x] = merge(t[2*x+1], t[2*x+2]);
	}

	void build(vector<int> &a) {
		init((int)a.size());
		build(a, 0, 0, size);
	}


	ll query() {
		return t[0].mx;
	}

	void update(int p, int value, int x, int lx, int rx) {
		if(rx - lx == 1) {
			t[x] = single(value);
			return;
		}
		int mid = lx + (rx -lx)/2;
		if(mid <= p) {
			update(p, value, 2*x+2, mid, rx);
		} else update(p, value, 2*x+1, lx, mid);
		t[x] = merge(t[2*x+1], t[2*x+2]);
	}

	void update(int p, int value) {
		update(p, value, 0, 0, size);
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	segtree st;
	st.build(a);

	int i, v;
	cout << st.query() << "\n";
	while(m--) {
		cin >> i >> v;
		st.update(i, v);
		cout << st.query() << "\n";
	}
}

