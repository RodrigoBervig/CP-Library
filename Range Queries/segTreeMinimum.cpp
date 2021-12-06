#include <bits/stdc++.h>

using namespace std; 

struct segtree {
	int size;
	vector<long long> minimums;

	void init(int n) {
		size = 1;
		while(size < n) size *= 2;
		minimums.assign(2*size, 0LL);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1){
			if(lx < (int)a.size())
				minimums[x] = a[lx];
			return;
		}
		int m = (lx + rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx); 
		minimums[x] = min(minimums[2*x+1], minimums[2*x+2]);
	}

	void build(vector<int> &a){
		build(a, 0, 0, size);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1){
			minimums[x] = v;
			return;
		}

		int m = (lx + rx) / 2;
		if(i < m){
			set(i, v, 2*x+1, lx, m);
		} else {
			set(i, v, 2*x+2, m, rx);
		}
		minimums[x] = min(minimums[2*x+1], minimums[2*x+2]);
	}

	void set(int i, int v){
		set(i, v, 0, 0, size);
	}

	long long minumum(int l, int r, int x, int lx, int rx) {
		if(lx >= r || l >= rx) return INT_MAX;
		if(lx >= l && rx <= r) return minimums[x];
		int m = (lx + rx)/2;
		long long s1 = minumum(l, r, 2*x+1, lx, m);
		long long s2 = minumum(l, r, 2*x+2, m, rx);
		return min(s1, s2);
	}

	long long minumum(int l, int r){
		return minumum(l, r, 0, 0, size);
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