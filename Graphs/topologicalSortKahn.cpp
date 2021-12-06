#include <bits/stdc++.h>

using namespace std;

#define dbg(x) { cerr << #x << " = " << x << "\n"; } 
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

//Using Kahn's algorithm
int indegrees[50000];
vi adj[50000];
vi ts;
int visited = 0;
priority_queue<int, vector<int>, greater<int>> pq;

void topSort() {
	while(!pq.empty()) {
		int front = pq.top();
		pq.pop();

		visited++;

		ts.pb(front);

		for(auto it: adj[front]){
			indegrees[it]--;
			if(indegrees[it] == 0){
				pq.push(it);
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 0; i < m; i++){
		cin >> a >> b;
		adj[a].pb(b);
		indegrees[b]++;
	}

	for(int i = 0; i < n; i++){
		if(indegrees[i] == 0){
			pq.push(i);
		}
	}

	topSort();

	if(visited != n){
		cout << "Can't topo sort this, sorry\n";
		return 0;
	}

	for(auto it: ts){
		cout << it << "\n";
	}


	return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
