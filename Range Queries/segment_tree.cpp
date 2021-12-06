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



#include <bits/stdc++.h>

using namespace std; 

//best implementation so far (exercise 3)
//counts the number of minimum elements in the segment

struct item {
	int m, c;
};

struct segtree {
	int size;
	vector<item> values;

	item NEUTRAL_ELEMENT = {INT_MAX, 0};

	item merge(item a, item b) {
		if(a.m < b.m) return a;
		if(b.m < a.m) return b;
		return {a.m, a.c + b.c};
	}

	item single(int v){
		return {v, 1};
	}

	void init(int n) {
		size = 1;
		while(size < n) size *= 2;
		values.resize(2 * size);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1){
			if(lx < (int)a.size())
				values[x] = single(a[lx]);
			return;
		}
		int m = (lx + rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		values[x] = merge(values[2*x+1], values[2*x+2]);
		
	}

	void build(vector<int> &a){
		build(a, 0, 0, size);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1){
			values[x] = single(v);
			return;
		}

		int m = (lx + rx) / 2;
		if(i < m){
			set(i, v, 2*x+1, lx, m);
		} else {
			set(i, v, 2*x+2, m, rx);
		}
		values[x] = merge(values[2*x+1], values[2*x+2]);
	}

	void set(int i, int v){
		set(i, v, 0, 0, size);
	}

	item calc(int l, int r, int x, int lx, int rx) {
		if(lx >= r || l >= rx) return {INT_MAX,0};
		if(lx >= l && rx <= r) return values[x];

		int m = (lx + rx)/2;

		item s1 = calc(l, r, 2*x+1, lx, m);
		item s2 = calc(l, r, 2*x+2, m, rx);

		return merge(s1,s2);
	}

	item calc(int l, int r){
		return calc(l, r, 0, 0, size);
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
