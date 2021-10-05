#include <bits/stdc++.h>

using namespace std;

vector<int> adj[5];
int dist[5];

void bfs(int v){
	
	for(int i = 0; i < (int) sizeof(dist)/(int) sizeof(int); i++) 
		dist[i] = -1;
	
	queue<int> q;
	
	q.push(v);
	dist[v] = 0;
	
	while(!q.empty()){
		for(auto it : adj[q.front()]){
			if(dist[it] == -1){
				dist[it] = dist[q.front()] + 1;
				q.push(it);
			}
		}
		q.pop();
	}
}

void dfs(int v){
	visited[v] = true;
	
	for(auto it : adj[v]){
		if(!visited[it]){
			dfs(it);
		}
	}
	
}

int main(){
	

	bfs(0);
	
	return 0;

}
