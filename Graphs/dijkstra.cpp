void djikstra(int s, vector<vector<pair<int,int>>> &adj, vector<long long> &dist) {
	dist[s] = 0;

	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

	pq.push({0, s});

	while(pq.size()) {
		auto [w, u] = pq.top();
		pq.pop();

		if(dist[u] < w) continue;

		for(auto [v, w_uv]: adj[u]) {
			if(dist[v] <= w + w_uv) continue;
			dist[v] = w + w_uv;
			pq.push({dist[v], v});
		}
	}
}