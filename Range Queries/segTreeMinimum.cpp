#include <bits/stdc++.h>

using namespace std; 

struct item {
	int v;
};

//queries are [l, r-1]
struct segtree {

	int size;
	vector<item> t;

	item neutral_element {0};

	item merge(item a, item b) {
		return {max(a.v, b.v)};
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

	//for(auto it : st.minimums) cout << it << " ";
	//cout << "\n";

	int op, l, r;
	for(int i = 0; i < m; i++){
		cin >> op >> l >> r;
		if(op == 1){
			st.set(l,r);
		} else {
			cout << st.minumum(l,r) << "\n";
		}
	}
}