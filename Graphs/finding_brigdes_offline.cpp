#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define dbg(x) { cerr << #x << " = " << x << "\n"; } 
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

//algo for finding bridges offline in O(n+e)

vector<bool> visited[MAX];
vector<bool> tim[MAX];
vector<bool> low[MAX];

set<pi> bridges;

void dfs(int s, int parent) {
	visited[s] = true;

	tim[s] = curr_tim++;
	low[s] = tim[s];
	
	for(auto v: adj[s]) {
		if(visited[v] && v != parent) { //this edge is a back edge
			low[s] = min(low[s], tin[v]);
			continue;
		} else if(visited[v] && v == parent) continue;

		dfs(v, parent);
		low[s] = min(low[s], low[v]);
		if(low[v] > tin[s]) bridges.insert({s, v});
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	
	while(t--) {
		solve();
	}

	return 0;
}
