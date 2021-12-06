#include <bits/stdc++.h>

using namespace std;
#define MAX 1000000

int v, e;

vector<pair<int,int>> adj[MAX];
int dist[MAX];

void Djikstra(int s) {
	priority_queue<pair<int,int>> S;
	
	for(int i = 0; i < v; i++){
		dist[i] = INT_MAX;
	}
	
	S.push({0, s});
	
	while(!S.empty()){
		auto u = S.top();
		S.pop();
		
		for(auto it : adj[u.second]){
			if(dist[it.second] > dist[u.second] + it.first){
				dist[it.second] = dist[u.second] + it.first;
			}
		}
	}
	
}

int main() {
	
	cin >> v >> e;
	
	int x, y;
	for(int i = 0; i < e; i++){
		cin >> x >> y;
		adj[x].push_back(y);
	}
	
	Djikstra(1);
	
	
	return 0;
}
