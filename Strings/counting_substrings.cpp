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

void count_sort(vector<int> &p, vector<int> &c) {
	int n = p.size();

	vector<int> cnt(n);
	for(auto x: c) {
		cnt[x]++;
	}
	vector<int> p_new(n);
	vector<int> pos(n);
	pos[0] = 0;
	for(int i = 1; i < n; i++) {
		pos[i] = pos[i-1] + cnt[i-1];
	}
	for(auto x: p) {
		int i = c[x];
		p_new[pos[i]] = x;
		pos[i]++;
	}
	p = p_new;
}

vector<int> suffixArray(string s) {
	s += '$';

	int n = s.size();
	//p - order of strings, c - equivalence classes
	vector<int> p(n), c(n);

	{
		vector<pair<char,int>> a(n);

		for(int i = 0; i < n; i++) 
			a[i] = {s[i], i};

		sort(a.begin(), a.end());

		for(int i = 0; i < n; i++) 
			p[i] = a[i].second;

		c[p[0]] = 0;
		for(int i = 1; i < n; i++) {
			c[p[i]] = c[p[i-1]] + (a[i].first != a[i-1].first);
		}
	}

	int k = 0;
	while((1 << k) < n) {
		//transition of k -> k + 1
		for(int i = 0; i < n; i++) {
			p[i] = (p[i] - (1<<k) + n) % n;
		}

		count_sort(p, c);
		
		vector<int> c_new(n);
		c_new[p[0]] = 0;
		for(int i = 1; i < n; i++) {
			pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1<<k)) % n]};
			pair<int,int> now = {c[p[i]], c[(p[i] + (1<<k)) % n]};

			c_new[p[i]] = c_new[p[i-1]] + (now != prev);
		}

		c = c_new;
		k++;
	}

	return p;
}

//-1 sub is smaller
//1 sub is bigger
//0 they are equal
int get_lexicografical_order(string &s, int sufix_pos, string &sub) {

	for(int i = 0; i < (int)sub.size(); i++) {
		if(sufix_pos + i >= (int)s.size()) return -1;

		if(s[sufix_pos+i] < sub[i]) return -1;
		if(s[sufix_pos+i] > sub[i]) return 1;
	}

	return 0;
}

int find_first_substr(vector<int> &sa, string &s, string &sub) {
	int l = 1, r = sa.size()-1;
	int ans = 0;
	//cant consider sa[0] = '$'
	while(l <= r) {
		int mid = l + (r-l)/2;
		int order = get_lexicografical_order(s, sa[mid], sub);

		if(order == 0) {
			ans = mid;
			r = mid-1;
		} else if(order == -1) {
			l = mid+1;
		} else {
			r = mid-1;
		}
	}

	return ans;
}


int find_last_substr(vector<int> &sa, string &s, string &sub) {
	int l = 1, r = sa.size()-1;
	int ans = 0;
	//cant consider sa[0] = '$'
	while(l <= r) {
		int mid = l + (r-l)/2;
		int order = get_lexicografical_order(s, sa[mid], sub);

		if(order == 0) {
			ans = mid;
			l = mid+1;
		} else if(order == -1) {
			l = mid+1;
		} else {
			r = mid-1;
		}
	}

	return ans;
}


void solve() {	
	string s;
	cin >> s;
	vector<int> sa = suffixArray(s);
	
	int q;
	cin >> q;
	while(q--) {
		string sub;
		cin >> sub;
		int first = find_first_substr(sa, s, sub);
		if(first == 0) {
			cout << 0 << "\n";
			continue;
		}
		int last = find_last_substr(sa, s, sub);
		cout << last - first + 1 << "\n";
	}
}
 
int main() {
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	solve();

	return 0;
}
