#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<bool> taken;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> adj[100];

void process(int vtx) {
	taken[vtx] = true;
	for(auto it: adj[vtx]){
		if(!taken[it.first])
			pq.push({it.second, it.first}); //weight and index
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int s = 0; //abritrary starting node
	taken[s] = true;
	process(s);

	int mst_cost = 0;
	
	while(!pq.empty()) {
		pii front = pq.top();
		pq.pop();
		if(!taken[front.second]){
			mst_cost += front.first;
			process(front.second);
		}
	}

	cout << "MST cost = " << mst_cost << "\n";

	return 0;
}