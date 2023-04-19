//insert here segment tree structure, below implementation used a 1-index one

const int maxN = 2e5+10, logN = 20;

vector<int> sz, height, heavy_child, chain, in;
int parent[maxN][logN];
segtree st;

//compute heavy children and necessary things
void dfs(int u, vector<vector<int>> &adj) {
	for(int i = 1; i < logN; i++) {
		parent[u][i] = parent[parent[u][i-1]][i-1];
	}

	sz[u] = 1;
	int heavy_size = 0;
	for(auto v: adj[u]){
		if(v == parent[u][0]) continue;
		
		parent[v][0] = u;
		height[v] = height[u] + 1; 
		dfs(v, adj);
		
		sz[u] += sz[v];
		if(sz[v] > heavy_size) {
			heavy_size = sz[v];
			heavy_child[u] = v;
		}
	}
}

//compute heavy paths and give appropriate visiting order
void decompose(int u, int head, int &t, vector<vector<int>> &adj){
	chain[u] = head;
	in[u] = t++;
	if(heavy_child[u] != -1) {
		decompose(heavy_child[u], head, t, adj);
	}
	for(auto v: adj[u]) {
		if(v == parent[u][0] || v == heavy_child[u]) continue;
		decompose(v, v, t, adj); 
	}
}

void init_hld(int n, vector<vector<int>> &adj, vector<long long> &values) {
	sz.resize(n+1, 0), height.resize(n+1, 0), heavy_child.resize(n+1, -1), chain.resize(n+1, 0), in.resize(n+1, 0);

	parent[1][0] = 1;
	height[1] = 1;

	dfs(1, adj);
	int t = 1;
	decompose(1, 1, t, adj);

	vector<long long> b(t+1);
	for(int i = 1; i <= n; i++) {
		b[in[i]] = values[i];
	}

	st.init(t);
	st.build(b);
}

//------------------------------ lca functions
int get_kth_ancestor(int a, int k) {
	for(int i = logN-1; i >= 0; i--) {
		if(k & (1 << i)) {
			a = parent[a][i];
		}
	}

	return a;
}

int lca(int u, int v) {
	if(height[u] < height[v]) swap(u, v);

	for(int i = logN-1; i >= 0; i--) {
		if(height[u] - (1 << i) >= height[v]){
			u = parent[u][i];
		}
	}

	if(u == v) return u;

	for(int i = logN - 1; i >= 0; i--) {
		if(parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	return parent[u][0];
}
//-------------------------------------------------

long long query_chain(int u, int l) {
	long long ans = 0;
	while(height[l] < height[u]) {
		int top = chain[u];
	
		if(height[top] <= height[l]) {
			int diff = height[u] - height[l];
			top = get_kth_ancestor(u, diff-1);
		}
	
		ans = max(ans, st.query(in[top], in[u])); //change to st.query(in[u], in[top]);
		u = parent[top][0];
	}
	
	return ans;
}

long long query_path(int u, int v) {
	int l = lca(u, v);
	
	long long ans = max({query_chain(u, l), query_chain(v, l), st.query(in[l], in[l])});

	return ans;
}