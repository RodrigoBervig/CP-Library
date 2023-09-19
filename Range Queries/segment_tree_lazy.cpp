#include <bits/stdc++.h>
 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
using namespace std;
 
#define dbg(x) { cerr << #x << " = " << x << "\n"; } 
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull; 

//lazy de soma, arrumar a função caso queiro mudar, dá pra fazer min e max fácil
struct item {
	long long sum, lazy;
};
 
struct segtree {
	vector<item> st;
	int size;
 
	item neutral_element = {0, 0};
 
	item merge(item a, item b) {
		return {a.sum + b.sum, 0,};
	}
 
	item single(int v) { return {v, 0}; }
 
	void init(int n) {
		size = n;
		int k = 1;
		while(k <= n) k <<= 1;
		st.resize(k*2 + 1);
	}
 
	void build(int x, int lx, int rx, vector<int> &a) {
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
		build(1, 1, size, a);
	}

	void refresh(int x, int lx, int rx) {
		if(st[x].lazy == 0) return;
		
		long long val = st[x].lazy;
		st[x].sum += (rx-lx+1)*val;
		st[x].lazy = 0;
	
		if(rx == lx) return;

		st[2*x].lazy += val;
		st[2*x+1].lazy += val;
	}
 
	void update_segment(int x, int lx, int rx, int l, int r, long long v) {
		refresh(x, lx, rx);
		if(l > rx || r < lx) return;
 
		if(l <= lx && rx <= r) {
			st[x].lazy += v;
			refresh(x, lx, rx);
			return;
		}
 
		int mid = lx+(rx-lx)/2;
 
		update_segment(2*x, lx, mid, l, r, v);
		update_segment(2*x+1, mid+1, rx, l, r, v);

		refresh(2*x, lx, mid);
		refresh(2*x+1, mid+1, rx);
 
		st[x].sum = st[2*x].sum + st[2*x+1].sum;
	}
 
	void update_segment(int l, int r, long long v) {
		update_segment(1, 1, size, l, r, v);
	}
 
	long long query(int x, int lx, int rx, int l, int r) {
		refresh(x, lx, rx);
 
		if(l > rx || r < lx) return 0;
		if(l <= lx && rx <= r) {
			return st[x].sum;
		}
 
		int mid = lx + (rx-lx)/2;
		
		return query(2*x, lx, mid, l, r) + query(2*x+1, mid+1, rx, l, r);
		
	}
 
	long long query(int l, int r) {
		return query(1, 1, size, l, r);
	}
};
 
void solve() {
	int n, q;
	cin >> n >> q;
 
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
 
	segtree st;
	st.init(n);
	st.build(a);
 
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			st.update_segment(l, r, 1, x);
		} else if(t == 2){
			int l, r, x;
			cin >> l >> r >> x;
			st.update_segment(l, r, 2, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << st.query(l, r) << "\n";
		}
	}
}
 
int main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
 
	return 0;
}